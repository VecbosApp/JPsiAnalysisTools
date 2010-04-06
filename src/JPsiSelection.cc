#include <string>

#include <TTree.h>

#include "CommonTools/include/Counters.hh"
#include "CommonTools/include/Selection.hh"
#include "CommonTools/include/Utils.hh"
#include "JPsiAnalysisTools/include/JPsiSelection.hh"
#include "CommonTools/include/EfficiencyEvaluator.hh"
#include "CommonTools/include/LeptonIdBits.h"

#include <iostream>
#include <string>

#include <TTree.h>

using namespace bits;

JPsiSelection::JPsiSelection(TTree *tree) 
  : JPsiBase(tree) {
  
  // initialize the selection
  std::string fileCuts     = "config/cuts.txt";
  std::string fileSwitches = "config/switches.txt";
  _selection = new Selection(fileCuts,fileSwitches);  
  
  _selection->addSwitch("MCtruth");
  _selection->addCut("etaElectronAcc");
  _selection->addCut("ptElectronAcc");
  _selection->addSwitch("electronID");
  _selection->addCut("trackerIsolHard");
  _selection->addCut("trackerIsolSlow");
  _selection->addCut("ecalIsolHardEB");
  _selection->addCut("ecalIsolSlowEB");
  _selection->addCut("ecalIsolHardEE");
  _selection->addCut("ecalIsolSlowEE");
  _selection->addCut("invMass");
  _selection->summary();

  // counter
  counter = new Counters();
  counter->SetTitle("EVENT COUNTER");
  counter->AddVar("event");
  counter->AddVar("MCtruth");
  counter->AddVar("atLeast2reco");
  counter->AddVar("etaElectronAcc");
  counter->AddVar("ptElectronAcc");
  counter->AddVar("nRecoEle");
  counter->AddVar("electronID");
  counter->AddVar("trackerIsolHard");
  counter->AddVar("trackerIsolSlow");
  counter->AddVar("ecalIsolHard");
  counter->AddVar("ecalIsolSlow"); 
  counter->AddVar("invMass");
  counter->AddVar("final");

  // single electron efficiency
  EgammaCutBasedID_Hard.ConfigureNoClass("config/eleid/hard");
  EgammaCutBasedID_Slow.ConfigureNoClass("config/eleid/slow");

  // kinematics
  m_p4ElectronPlus  = new TLorentzVector(0.,0.,0.,0.);
  m_p4ElectronMinus = new TLorentzVector(0.,0.,0.,0.);
  _bestElectrons    = new std::vector<int>;
}

JPsiSelection::~JPsiSelection(){

  delete m_p4ElectronPlus;
  delete m_p4ElectronMinus;
  delete _bestElectrons;
  delete _selection;

  myEleIdTree -> save();
  myKineTree  -> save();
}

void JPsiSelection::Loop() {

  if(fChain == 0) return;

  Utils anaUtilsGlobal;
  
  // kinematics reduced tree
  std::string reducedTreeName = _datasetName+"-kine.root";
  myKineTree = new RedJPsiTree(reducedTreeName.c_str());

  // eleId reduced tree
  std::string reducedEleIdTreeName = _datasetName+"-eleId.root";
  myEleIdTree = new RedEleIDTree(reducedEleIdTreeName.c_str());
  myEleIdTree->addIsolation();
  myEleIdTree->addPFEleID();

  // analysis
  Long64_t nbytes = 0, nb = 0;
  Long64_t nentries = fChain->GetEntries();
  std::cout << "Number of entries = " << nentries << std::endl;

  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    if (jentry%1000 == 0) std::cout << ">>> Processing event # " << jentry << std::endl;
    
    counter->IncrVar("event",1.);
    
    resetKinematics();
    
    // look to the MC truth decay tree
    bool foundMcTree = findMcTree();
    if(_selection->getSwitch("MCtruth") && !foundMcTree ) continue;
    counter->IncrVar("MCtruth",1.);

    // looking for reco electrons
    if(nEle>1) counter->IncrVar("atLeast2reco",1.); 

    // looking for electrons in the acceptance
    getElectronsInEta();
    if(eleInEta.size()>1) counter->IncrVar("etaElectronAcc",1.);
    else continue;

    // looking for electron with pt above threshold
    getElectronsInPt();
    if(eleInPt.size()>1) counter->IncrVar("ptElectronAcc",1.);
    else continue;

    // get the two highest Et electrons: chiara: da controllare se combinatorio e' meglio
    std::pair<int,int> theElectrons = getBestElectronPair();
    int tbElectron(theElectrons.second);
    int tbPositron(theElectrons.first);    
    theElectron = tbElectron;
    thePositron = tbPositron;
    bool foundTwoReco = false;
    if (theElectron>-1 && thePositron>-1)  foundTwoReco = true;
    if(!foundTwoReco ) continue;
    counter->IncrVar("nRecoEle",1.);

    // kinematics 
    setKinematics();   

    // tracker or ECAL driven electrons and index of supercluster
    int eleIndexSc=-1;
    int posIndexSc=-1;
    bool eleTrackerDriven = false;
    bool posTrackerDriven = false;
    if(theElectron>-1) { 
      eleTrackerDriven = anaUtilsGlobal.electronRecoType(recoFlagsEle[theElectron], isTrackerDriven); 
      if (eleTrackerDriven)  eleIndexSc = PFsuperClusterIndexEle[theElectron];
      if (!eleTrackerDriven) eleIndexSc = superClusterIndexEle[theElectron];
    }
    if(thePositron>-1) { 
      posTrackerDriven = anaUtilsGlobal.electronRecoType(recoFlagsEle[thePositron], isTrackerDriven); 
      if (posTrackerDriven)  posIndexSc = PFsuperClusterIndexEle[thePositron];
      if (!posTrackerDriven) posIndexSc = superClusterIndexEle[thePositron];
    }

    int theHard, theSlow;
    float pt1, pt2, eta1, eta2;
    int rf1, rf2;
    if(m_p4ElectronMinus->Pt() > m_p4ElectronPlus->Pt()) {
      theHard = theElectron;
      theSlow = thePositron;
      pt1 = m_p4ElectronMinus->Pt();
      eta1 = m_p4ElectronMinus->Eta();
      rf1 = recoFlagsEle[theElectron];
      pt2 = m_p4ElectronPlus->Pt();
      eta2 = m_p4ElectronPlus->Eta();
      rf2 = recoFlagsEle[thePositron];
    } else {
      theHard = thePositron;
      theSlow = theElectron;
      pt2 = m_p4ElectronMinus->Pt();
      eta2 = m_p4ElectronMinus->Eta();
      rf2 = recoFlagsEle[theElectron];
      pt1 = m_p4ElectronPlus->Pt();
      eta1 = m_p4ElectronPlus->Eta();
      rf1 = recoFlagsEle[thePositron];
    }

    this->fillEleIdTree(theHard, theSlow);    

    // electron ID cuts
    bool theHardID = true;
    bool theSlowID = true;
    if ( theHard>-1 ) theHardID = isEleID(theHard, true);
    if ( theSlow>-1 ) theSlowID = isEleID(theSlow, false);
    
    if( _selection->getSwitch("electronID") && (!theHardID || !theSlowID) ) continue;
    counter->IncrVar("electronID");

    // tracker isolation cuts
    float sumPtHard = getSumPtSecondFP04(theHard,theSlow);
    float sumPtSlow = getSumPtSecondFP04(theSlow,theHard);
    if ( _selection->getSwitch("trackerIsolHard") && !_selection->passCut("trackerIsolHard", sumPtHard) ) continue;
    counter->IncrVar("trackerIsolHard");
    if ( _selection->getSwitch("trackerIsolSlow") && !_selection->passCut("trackerIsolSlow", sumPtSlow) ) continue;
    counter->IncrVar("trackerIsolSlow");
    
    // ECAL isolation cuts
    float sumEtGTHard = dr04EcalRecHitSumEtEle[theHard];
    float sumEtGTSlow = dr04EcalRecHitSumEtEle[theSlow];
    bool barrelHard = anaUtilsGlobal.fiducialFlagECAL(fiducialFlagsEle[theHard],isEB);
    bool barrelSlow = anaUtilsGlobal.fiducialFlagECAL(fiducialFlagsEle[theSlow],isEB);
    bool theHardEcalIsol = (barrelHard) ? _selection->passCut("ecalIsolHardEB", sumEtGTHard) : _selection->passCut("ecalIsolHardEE", sumEtGTHard);
    bool theSlowEcalIsol = (barrelSlow) ? _selection->passCut("ecalIsolSlowEB", sumEtGTSlow) : _selection->passCut("ecalIsolSlowEE", sumEtGTSlow);
    if ( _selection->getSwitch("ecalIsolHard") && !theHardEcalIsol ) continue;
    counter->IncrVar("ecalIsolHard");
    if ( _selection->getSwitch("ecalIsolSlow") && !theSlowEcalIsol ) continue;
    counter->IncrVar("ecalIsolSlow");
    
    /*

    // electron identification: vogliamo usare l'eleID alla San Diego? chiara
    bool theElectronID = true;
    bool thePositronID = true;
    if (theElectron>-1) theElectronID = isEleID(theElectron, eleIndexSc);
    if (thePositron>-1) thePositronID = isEleID(thePositron, posIndexSc);    
    if(_selection->getSwitch("electronID") && !theElectronID) continue;
    if(_selection->getSwitch("electronID") && !thePositronID) continue;
    counter->IncrVar("electronID",1.);
    
    // electron isolation - chiara da studiare
    float theEleTrackerPtSum = ( theElectron > -1 ) ? dr03TkSumPtEle[theElectron] : 0.0;
    float thePosTrackerPtSum = ( thePositron > -1 ) ? dr03TkSumPtEle[thePositron] : 0.0;
    float theEleEcalPtSum    = ( theElectron > -1 ) ? dr03EcalRecHitSumEtEle[theElectron] : 0.0;
    float thePosEcalPtSum    = ( thePositron > -1 ) ? dr03EcalRecHitSumEtEle[thePositron] : 0.0;
    float theEleHcalPtSum    = ( theElectron > -1 ) ? dr03HcalTowerSumEtEle[theElectron] : 0.0;
    float thePosHcalPtSum    = ( thePositron > -1 ) ? dr03HcalTowerSumEtEle[thePositron] : 0.0;
    // if(_selection->getSwitch("electronIsol") && 1) continue
    counter->IncrVar("electronIsol",1.);

    */
   
    // invariant mass (fit region range)
    if( _selection->getSwitch("invMass") && !_selection->passCut("invMass", invariantMassTracker) ) continue;
    counter->IncrVar("invMass");

    counter->IncrVar("final");
    
    // filling kinematics tree
    myKineTree -> fillAll(invariantMass, invariantMassTracker, deltaR, pt1, pt2, eta1, eta2, rf1, rf2);
    myKineTree -> fillRunInfo(runNumber, lumiBlock, eventNumber);

    // storing trees
    myKineTree  -> store();
  }
}


 


bool JPsiSelection::findMcTree() {

  /*  
  _theGenEle=-1;
  _theGenPos=-1;

  int indE=999;
  int indP=999;
  
  for(int imc=0;imc<nMc;imc++) {
    if( indE<999 && indP<999 ) continue;
    if( idMc[imc]==-11 && abs(idMc[mothMc[imc]])==443) {indE = imc; }
    if( idMc[imc]==+11 && abs(idMc[mothMc[imc]])==443) {indP = imc; }
  }

  if( indE<999 && indP<999 ) {
    _theGenEle = indE;
    _theGenPos = indP;
    
    // distributions for efficiency studies
    // H_genEta -> Fill(etaMc[_theGenEle]);
    // H_genEta -> Fill(etaMc[_theGenPos]);
    // H_genPhi -> Fill(phiMc[_theGenEle]);
    // H_genPhi -> Fill(phiMc[_theGenPos]);
    // H_genPt  -> Fill(pMc[_theGenEle]*fabs(sin(thetaMc[_theGenEle])));
    // H_genPt  -> Fill(pMc[_theGenPos]*fabs(sin(thetaMc[_theGenPos])));
  }

  return ( indE<999 && indP<999 );
  */
  return true;
}

void JPsiSelection::getElectronsInEta() {
   
  Utils anaUtils;
  
  for(int iEle=0; iEle<nEle; iEle++) {
    if(_selection->getSwitch("etaElectronAcc")) { 
      bool inTheGap = anaUtils.fiducialFlagECAL(fiducialFlagsEle[iEle],isGap);
      if (inTheGap) continue;
      if(!_selection->passCut("etaElectronAcc",etaEle[iEle])) continue;
    }
    eleInEta.push_back(iEle);
  }
}

void JPsiSelection::getElectronsInPt() {
  
  Utils anaUtils;
  
  for(int iEle=0; iEle<eleInEta.size(); iEle++) {
    
    TVector3 pLepton(pxEle[eleInEta[iEle]],pyEle[eleInEta[iEle]],pzEle[eleInEta[iEle]]);
    float thisPt=pLepton.Pt();
    if(_selection->getSwitch("ptElectronAcc") && !_selection->passCut("ptElectronAcc",thisPt) ) continue;
    
    eleInPt.push_back(eleInEta[iEle]);
  }
}

std::pair<int,int> JPsiSelection::getBestElectronPair() {

  int theLep1=-1;
  int theLep2=-1;
  float maxPtLep1=-1000.;
  float maxPtLep2=-1000.;
  std::vector<int> goodRecoLeptons;

  for(int iEle=0;iEle<eleInPt.size();iEle++) {

    TVector3 pLepton(pxEle[eleInPt[iEle]],pyEle[eleInPt[iEle]],pzEle[eleInPt[iEle]]);
    float thisPt     = pLepton.Pt();
    float thisCharge = chargeEle[eleInPt[iEle]];
    if (thisCharge>0 && thisPt>maxPtLep1){ maxPtLep1 = thisPt; theLep1 = eleInPt[iEle]; }
    if (thisCharge<0 && thisPt>maxPtLep2){ maxPtLep2 = thisPt; theLep2 = eleInPt[iEle]; }
  }
  _bestElectrons->clear();
  _bestElectrons->push_back(theLep1);  _bestElectrons->push_back(theLep2); 

  return make_pair(theLep1,theLep2);
}

void JPsiSelection::setKinematics() {

  m_p4ElectronMinus -> SetXYZT(pxEle[theElectron],pyEle[theElectron],pzEle[theElectron],energyEle[theElectron]);
  m_p4ElectronPlus  -> SetXYZT(pxEle[thePositron],pyEle[thePositron],pzEle[thePositron],energyEle[thePositron]);      
  invariantMass     = (*m_p4ElectronMinus + *m_p4ElectronPlus).M();
  
  int trackEle = trackIndexEle[theElectron];
  int trackPos = trackIndexEle[thePositron];
  TVector3 p3TrackEle(pxTrack[trackEle],pyTrack[trackEle],pzTrack[trackEle]);
  TVector3 p3TrackPos(pxTrack[trackPos],pyTrack[trackPos],pzTrack[trackPos]);  
  TLorentzVector pTrackEle(p3TrackEle,p3TrackEle.Mag());
  TLorentzVector pTrackPos(p3TrackPos,p3TrackPos.Mag());

  invariantMassTracker = (pTrackEle+pTrackPos).M();
  
  deltaR = p3TrackEle.DeltaR(p3TrackPos); 
}

void JPsiSelection::resetKinematics() {
  
  theElectron = -1;
  thePositron = -1;
  m_p4ElectronMinus -> SetXYZT(0,0,0,0);
  m_p4ElectronPlus  -> SetXYZT(0,0,0,0);
  invariantMass = 0;
  invariantMassTracker = 0;
  eleInEta.clear();
  eleInPt.clear();
  deltaR = 0.;
}

void JPsiSelection::displayEfficiencies(std::string datasetName) {
  
  std::string::size_type loc = datasetName.find_first_of(".",0);
  if( loc != std::string::npos ) {
    datasetName.erase(loc);
  }
  
  std::cout << "--------------------------------" << std::endl;
  std::cout << "Selection efficiency: " << std::endl;

  counter->Draw();
  counter->Draw("MCtruth","event");
  counter->Draw("atLeast2reco","MCtruth");
  counter->Draw("etaElectronAcc","atLeast2reco");
  counter->Draw("ptElectronAcc","etaElectronAcc");
  counter->Draw("nRecoEle","ptElectronAcc");
  counter->Draw("electronID","nRecoEle");
  counter->Draw("trackerIsolHard","electronID");
  counter->Draw("trackerIsolSlow","trackerIsolHard");
  counter->Draw("ecalIsolHard","trackerIsolSlow");
  counter->Draw("ecalIsolSlow","ecalIsolHard");
  counter->Draw("invMass","ecalIsolSlow");
  counter->Draw("final","MCtruth");

  std::cout << "---------------------------------------------------" << std::endl;
  std::cout << "EleID efficiency hard electrons (ECAL driven only): " << std::endl;
  EgammaCutBasedID_Hard.diplayEfficiencies();   
  std::cout << "---------------------------------------------------" << std::endl;
  std::cout << "EleID efficiency slow electrons (ECAL driven only): " << std::endl;
  EgammaCutBasedID_Slow.diplayEfficiencies();   
  std::cout << "---------------------------------------------------" << std::endl;

}

bool JPsiSelection::isEleID(int eleIndex, bool isTheHard) {

  Utils anaUtils;

  int gsfTrackIndex = gsfTrackIndexEle[eleIndex];
  TVector3 pTrkAtOuter(pxAtOuterGsfTrack[gsfTrackIndex],pyAtOuterGsfTrack[gsfTrackIndex],pzAtOuterGsfTrack[gsfTrackIndex]);

  // if is ECAL driven, take the electron ID variables from the standard electron
  // above all, take the ECAL supercluster instead of PF super cluster
  float HoE, s9s25, deta, dphiin, dphiout, fbrem, see, spp, eopout, eop;
  bool ecaldriven = anaUtils.electronRecoType(recoFlagsEle[eleIndex], isEcalDriven);
  if(ecaldriven) {
    int sc = superClusterIndexEle[eleIndex];
    HoE = hOverEEle[eleIndex];
    s9s25 = e3x3SC[sc]/e5x5SC[sc];
    deta = deltaEtaAtCaloEle[eleIndex];
    dphiin = deltaPhiAtVtxEle[eleIndex];
    dphiout = deltaPhiAtCaloEle[eleIndex];
    fbrem = fabs(momentumEle[eleIndex]-pTrkAtOuter.Mag())/momentumEle[eleIndex];
    see = sqrt(covIEtaIEtaSC[sc]);
    spp = sqrt(covIPhiIPhiSC[sc]);
    eopout = eSeedOverPoutEle[eleIndex];
    eop = eSuperClusterOverPEle[eleIndex];
  } else {
    int pfcand = getPFElectron(eleIndex);
    int sc = PFsuperClusterIndexEle[eleIndex];
    HoE = hOverEEle[eleIndex];
    s9s25 = e3x3PFSC[sc]/e5x5PFSC[sc];
    //    deta = deltaEtaAtCaloPFEle[pfcand];
    deta = 0 ;
    dphiin = 0;
    //    dphiout = deltaPhiAtCaloPFEle[pfcand];
    dphiout = 0;
    fbrem = fabs(momentumEle[eleIndex]-pTrkAtOuter.Mag())/momentumEle[eleIndex];
    see = sqrt(covIEtaIEtaPFSC[sc]);
    spp = sqrt(covIPhiIPhiPFSC[sc]);
    // eopout = EoPoutModePFEle[pfcand];
    //    eop = EoPModePFEle[pfcand];
    eopout = eop = 1;
  }

  bool isIdentified = false;
  if(isTheHard) {
    EgammaCutBasedID_Hard.SetEcalFiducialRegion( fiducialFlagsEle[eleIndex] );
    EgammaCutBasedID_Hard.SetRecoFlag(recoFlagsEle[eleIndex]);
    EgammaCutBasedID_Hard.applyElectronIDOnPFlowElectrons(false);
    EgammaCutBasedID_Hard.SetHOverE( HoE );
    EgammaCutBasedID_Hard.SetS9S25( s9s25 );
    EgammaCutBasedID_Hard.SetDEta( deta );
    EgammaCutBasedID_Hard.SetDPhiIn( dphiin );
    EgammaCutBasedID_Hard.SetDPhiOut( dphiout );
    EgammaCutBasedID_Hard.SetBremFraction( fabs(momentumEle[eleIndex]-pTrkAtOuter.Mag())/momentumEle[eleIndex] );
    EgammaCutBasedID_Hard.SetSigmaEtaEta( see );
    EgammaCutBasedID_Hard.SetSigmaPhiPhi( spp );
    EgammaCutBasedID_Hard.SetEOverPout( eopout );
    EgammaCutBasedID_Hard.SetEOverPin( eop );
    EgammaCutBasedID_Hard.SetElectronClass ( classificationEle[eleIndex] );
    EgammaCutBasedID_Hard.SetEgammaCutBasedID ( anaUtils.electronIdVal(eleIdCutsEle[theElectron],eleIdLoose) );
    EgammaCutBasedID_Hard.SetLikelihood( eleIdLikelihoodEle[eleIndex] );

    isIdentified = EgammaCutBasedID_Hard.outputNoClass();

  } else {
    EgammaCutBasedID_Slow.SetEcalFiducialRegion( fiducialFlagsEle[eleIndex] );
    EgammaCutBasedID_Slow.SetRecoFlag(recoFlagsEle[eleIndex]);
    EgammaCutBasedID_Slow.applyElectronIDOnPFlowElectrons(false);
    EgammaCutBasedID_Slow.SetHOverE( HoE );
    EgammaCutBasedID_Slow.SetS9S25( s9s25 );
    EgammaCutBasedID_Slow.SetDEta( deta );
    EgammaCutBasedID_Slow.SetDPhiIn( dphiin );
    EgammaCutBasedID_Slow.SetDPhiOut( dphiout );
    EgammaCutBasedID_Slow.SetBremFraction( fabs(momentumEle[eleIndex]-pTrkAtOuter.Mag())/momentumEle[eleIndex] );
    EgammaCutBasedID_Slow.SetSigmaEtaEta( see );
    EgammaCutBasedID_Slow.SetSigmaPhiPhi( spp );
    EgammaCutBasedID_Slow.SetEOverPout( eopout );
    EgammaCutBasedID_Slow.SetEOverPin( eop );
    EgammaCutBasedID_Slow.SetElectronClass ( classificationEle[eleIndex] );
    EgammaCutBasedID_Slow.SetEgammaCutBasedID ( anaUtils.electronIdVal(eleIdCutsEle[theElectron],eleIdLoose) );
    EgammaCutBasedID_Slow.SetLikelihood( eleIdLikelihoodEle[eleIndex] );

    isIdentified = EgammaCutBasedID_Slow.outputNoClass();
  }

  return isIdentified;
}

float JPsiSelection::getSumPtSecondFP04(int first, int second) {

  float sumPt04 = dr04TkSumPtEle[first];
  if(second < 0) return sumPt04;

  int firstGsfTrack = gsfTrackIndexEle[first];
  int secondKFTrack = trackIndexEle[second];

  TVector3 pFirst(pxGsfTrack[firstGsfTrack],pyGsfTrack[firstGsfTrack],pzGsfTrack[firstGsfTrack]);
  TVector3 pTrackSecond(pxTrack[secondKFTrack],pyTrack[secondKFTrack],pzTrack[secondKFTrack]);

  float dr = pTrackSecond.DeltaR(pFirst);

  if( dr < 0.4 ) sumPt04 -= pTrackSecond.Pt();

  return sumPt04;

}

int JPsiSelection::getPFElectron(int gsfElectron) {

  int PFCand = -1;

  int gsftrack = gsfTrackIndexEle[gsfElectron];
  for (int ipf=0; ipf<nPFEle; ipf++) {
    if ( gsfTrackIndexPFEle[ipf] == gsftrack ) {
      PFCand = ipf;
      break;
    }
  }

  return PFCand;

}

void JPsiSelection::fillEleIdTree(int hard, int slow) {

  Utils anaUtils;

  // electron ID and isolation variables used for optimization
  int myRecoFlag[2];
  float myPt[2];
  float myEta[2];
  
  // electron ID variables
  int myClass[2];
  float myFBrem[2];
  float myHOverE[2];          
  float myEOverP[2], myEOverPout[2];
  float myDeltaEtaAtCalo[2], myDeltaPhiAtCalo[2];
  float mySigmaIEtaIEta[2];
  
  // PF electron ID variables
  float myEoPModePFEle[2];
  float myEoPoutModePFEle[2];
  float myEBremoDeltaPPFEle[2];
  float myDeltaEtaAtCaloPFEle[2];
  float myDeltaPhiAtCaloPFEle[2]; 
  float myHOverHEPFEle[2];
  float myHOverPPFEle[2];
  float myMva[2];

    // electron isolation variables
  float mySumPt04[2];
  float mySumEtJurFP04[2];
  float mySumEtScFP04[2];

  // defaults
  for(int i=0; i<2; i++) {
    // electron isolation variables
    mySumPt04[i]=-999;
    mySumEtJurFP04[i]=-999;
    mySumEtScFP04[i]=-999;

    myRecoFlag[i]=-999;
    myPt[i]=-999;
    myEta[i]=-999;
  
    // electron ID variables
    myClass[i]=-999;
    myFBrem[i]=-999;
    myHOverE[i]=-999;          
    myEOverP[i]=-999; 
    myEOverPout[i]=-999;
    myDeltaEtaAtCalo[i]=-999;
    myDeltaPhiAtCalo[i]=-999;
    mySigmaIEtaIEta[i]=-999;
  
    // PF electron ID variables
    myEoPModePFEle[i]=-999;
    myEoPoutModePFEle[i]=-999;
    myEBremoDeltaPPFEle[i]=-999;
    myDeltaEtaAtCaloPFEle[i]=-999;
    myDeltaPhiAtCaloPFEle[i]=-999; 
    myHOverHEPFEle[i]=-999;
    myHOverPPFEle[i]=-999;
    myMva[2]=-999;

    // electron isolation variables
    mySumPt04[i]=-999;
    mySumEtJurFP04[i]=-999;
    mySumEtScFP04[i]=-999;
  }

  std::vector<int> electrons;
  electrons.push_back(hard);
  electrons.push_back(slow);
  for(int i=0; i<2; i++) {
    int ele = electrons[i];
    if ( ele == -1 ) continue;
    myRecoFlag[i] = recoFlagsEle[ele];
    // kinematics
    TVector3 pEle(pxEle[ele],pyEle[ele],pzEle[ele]);
    int gsftrack = gsfTrackIndexEle[ele];
    TVector3 pOutEle(pxAtOuterGsfTrack[gsftrack],pyAtOuterGsfTrack[gsftrack],pzAtOuterGsfTrack[gsftrack]);

    myPt[i] = pEle.Pt();
    myEta[i] = pEle.Eta();
    myFBrem[i] = (pEle.Mag() - pOutEle.Mag()) / pEle.Mag();

    // ele ID
    myClass[i] = classificationEle[ele];
    myHOverE[i] = hOverEEle[ele];
    myEOverP[i] = eSuperClusterOverPEle[ele];
    myEOverPout[i] = eSeedOverPoutEle[ele];
    myDeltaEtaAtCalo[i] = deltaEtaAtCaloEle[ele];
    myDeltaPhiAtCalo[i] = deltaPhiAtCaloEle[ele];
    
    // seed cluster shape
    bool eleTrackerDriven = anaUtils.electronRecoType(recoFlagsEle[ele], isTrackerDriven);
    bool eleEcalDriven =  anaUtils.electronRecoType(recoFlagsEle[ele], isEcalDriven);
    int eleIndexSc = -1;
    if (eleEcalDriven) { // take ECAL SC if ECAL only or both
      eleIndexSc = superClusterIndexEle[ele];
      mySigmaIEtaIEta[i] = sqrt(covIEtaIEtaSC[eleIndexSc]);
    } else { // tracker driven only
      eleIndexSc = PFsuperClusterIndexEle[ele];
      mySigmaIEtaIEta[i] = sqrt(covIEtaIEtaPFSC[eleIndexSc]);
    }

    // PF electron ID variables
    int pfcand = getPFElectron(ele);
    if(pfcand>-1) {
      // myEoPModePFEle[i] = EoPModePFEle[pfcand];
      //      myEoPoutModePFEle[i] = EoPoutModePFEle[pfcand];
      //      myEBremoDeltaPPFEle[i] = EBremoDeltaPPFEle[pfcand];
      //      myDeltaEtaAtCaloPFEle[i] = deltaEtaAtCaloPFEle[pfcand];
      //      myDeltaPhiAtCaloPFEle[i] = deltaPhiAtCaloPFEle[pfcand];
      myEoPModePFEle[i] = myEoPoutModePFEle[i] = myEBremoDeltaPPFEle[i] =   myDeltaEtaAtCaloPFEle[i] = myDeltaPhiAtCaloPFEle[i] = 999;
      myHOverHEPFEle[i] = myHOverPPFEle[pfcand];
      //myHOverPPFEle[i] = hOverPPFEle[pfcand];
      myHOverPPFEle[i] = 999;
      myMva[i] = MvaOutputPFEle[pfcand];
    } else {
      myEoPModePFEle[i] = -999;
      myEoPoutModePFEle[i] = -999;
      myEBremoDeltaPPFEle[i] = -999;
      myDeltaEtaAtCaloPFEle[i] = -999;
      myDeltaPhiAtCaloPFEle[i] = -999;
      myHOverHEPFEle[i] = -999;
      myHOverPPFEle[i] = -999;
      myMva[i] = -999;
    }
   
    // isolation
    mySumPt04[i] = (i==0) ? getSumPtSecondFP04(hard,slow) : getSumPtSecondFP04(slow,hard);
    mySumEtJurFP04[i] = dr04EcalRecHitSumEtEle[ele];
    mySumEtScFP04[i] = scBasedEcalSum04Ele[ele];
 
  }

  if(hard!=-1 || slow!=-1) {
    myEleIdTree -> fillAll(myClass, myRecoFlag, myPt, myEta, myHOverE, myEOverP, myEOverPout, myDeltaEtaAtCalo, myDeltaPhiAtCalo, mySigmaIEtaIEta, myFBrem);
    myEleIdTree -> fillPFEleID(myEoPModePFEle,myEoPoutModePFEle,myEBremoDeltaPPFEle,myDeltaEtaAtCaloPFEle,myDeltaPhiAtCaloPFEle,myHOverHEPFEle,myHOverPPFEle, myMva);
    myEleIdTree -> fillIsolation(mySumPt04,mySumEtJurFP04,mySumEtScFP04);
    
    myEleIdTree -> store();
  }

}
