//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jan 26 12:55:16 2010 by ROOT version 5.22/00d
// from TTree ntp1/ntp1
// found on file: rfio:///castor/cern.ch/user/e/emanuele/JPsi/Trees3/JPsiEE_2360GeV_EGMSkimV6/default_MC_1.root
//////////////////////////////////////////////////////////

#ifndef JPsiBase_h
#define JPsiBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class JPsiBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           nl1Technical;
   Int_t           l1Technical[64];   //[nl1Technical]
   Int_t           nl1Global;
   Int_t           l1Global[128];   //[nl1Global]
   Int_t           runNumber;
   Int_t           eventNumber;
   Int_t           lumiBlock;
   Int_t           bunchCrossing;
   Int_t           orbitNumber;
   Int_t           nMc;
   Float_t         pMc[1000];   //[nMc]
   Float_t         massMc[1000];   //[nMc]
   Float_t         thetaMc[1000];   //[nMc]
   Float_t         etaMc[1000];   //[nMc]
   Float_t         phiMc[1000];   //[nMc]
   Float_t         energyMc[1000];   //[nMc]
   Int_t           idMc[1000];   //[nMc]
   Int_t           mothMc[1000];   //[nMc]
   Int_t           nDauMc[1000];   //[nMc]
   Int_t           statusMc[1000];   //[nMc]
   Float_t         xMc[1000];   //[nMc]
   Float_t         yMc[1000];   //[nMc]
   Float_t         zMc[1000];   //[nMc]
   Int_t           nEle;
   Int_t           chargeEle[30];   //[nEle]
   Float_t         energyEle[30];   //[nEle]
   Float_t         etEle[30];   //[nEle]
   Float_t         momentumEle[30];   //[nEle]
   Float_t         thetaEle[30];   //[nEle]
   Float_t         etaEle[30];   //[nEle]
   Float_t         phiEle[30];   //[nEle]
   Float_t         pxEle[30];   //[nEle]
   Float_t         pyEle[30];   //[nEle]
   Float_t         pzEle[30];   //[nEle]
   Float_t         vertexXEle[30];   //[nEle]
   Float_t         vertexYEle[30];   //[nEle]
   Float_t         vertexZEle[30];   //[nEle]
   Float_t         massEle[30];   //[nEle]
   Int_t           fiducialFlagsEle[30];   //[nEle]
   Int_t           recoFlagsEle[30];   //[nEle]
   Int_t           energyCorrectionsEle[30];   //[nEle]
   Float_t         esEnergyEle[30];   //[nEle]
   Int_t           superClusterIndexEle[30];   //[nEle]
   Int_t           PFsuperClusterIndexEle[30];   //[nEle]
   Int_t           trackIndexEle[30];   //[nEle]
   Int_t           gsfTrackIndexEle[30];   //[nEle]
   Float_t         PFChi2EcalTrackEle[30];   //[nEle]
   Float_t         PFesEneL1Ele[30];   //[nEle]
   Float_t         PFesEneL2Ele[30];   //[nEle]
   Float_t         PFesChi2L1Ele[30];   //[nEle]
   Float_t         PFesChi2L2Ele[30];   //[nEle]
   Int_t           classificationEle[30];   //[nEle]
   Int_t           standardClassificationEle[30];   //[nEle]
   Float_t         hOverEEle[30];   //[nEle]
   Float_t         eSuperClusterOverPEle[30];   //[nEle]
   Float_t         eSeedOverPoutEle[30];   //[nEle]
   Float_t         deltaEtaAtVtxEle[30];   //[nEle]
   Float_t         deltaPhiAtVtxEle[30];   //[nEle]
   Float_t         deltaEtaAtCaloEle[30];   //[nEle]
   Float_t         deltaPhiAtCaloEle[30];   //[nEle]
   Float_t         tipEle[30];   //[nEle]
   Float_t         dr03TkSumPtEle[30];   //[nEle]
   Float_t         dr03EcalRecHitSumEtEle[30];   //[nEle]
   Float_t         dr03HcalTowerSumEtEle[30];   //[nEle]
   Float_t         dr04TkSumPtEle[30];   //[nEle]
   Float_t         dr04EcalRecHitSumEtEle[30];   //[nEle]
   Float_t         dr04HcalTowerSumEtEle[30];   //[nEle]
   Float_t         scBasedEcalSum03Ele[30];   //[nEle]
   Float_t         scBasedEcalSum04Ele[30];   //[nEle]
   Float_t         scHaloBasedEcalSum03Ele[30];   //[nEle]
   Float_t         scHaloBasedEcalSum04Ele[30];   //[nEle]
   Int_t           eleIdCutsEle[30];   //[nEle]
   Float_t         eleIdLikelihoodEle[30];   //[nEle]
   UChar_t         pflowMVAEle[30];   //[nEle]
   Int_t           nPFEle;
   Int_t           chargePFEle[40];   //[nPFEle]
   Float_t         energyPFEle[40];   //[nPFEle]
   Float_t         etPFEle[40];   //[nPFEle]
   Float_t         momentumPFEle[40];   //[nPFEle]
   Float_t         thetaPFEle[40];   //[nPFEle]
   Float_t         etaPFEle[40];   //[nPFEle]
   Float_t         phiPFEle[40];   //[nPFEle]
   Float_t         pxPFEle[40];   //[nPFEle]
   Float_t         pyPFEle[40];   //[nPFEle]
   Float_t         pzPFEle[40];   //[nPFEle]
   Float_t         vertexXPFEle[40];   //[nPFEle]
   Float_t         vertexYPFEle[40];   //[nPFEle]
   Float_t         vertexZPFEle[40];   //[nPFEle]
   Float_t         massPFEle[40];   //[nPFEle]
   Float_t         MvaOutputPFEle[40];   //[nPFEle]
   Float_t         PS1EnergyPFEle[40];   //[nPFEle]
   Float_t         PS2EnergyPFEle[40];   //[nPFEle]
   Float_t         EcalEnergyPFEle[40];   //[nPFEle]
   Float_t         EcalElectronEnergyPFEle[40];   //[nPFEle]
   Float_t         EoPModePFEle[40];   //[nPFEle]
   Float_t         EoPoutModePFEle[40];   //[nPFEle]
   Float_t         EBremoDeltaPPFEle[40];   //[nPFEle]
   Float_t         deltaEtaAtCaloPFEle[40];   //[nPFEle]
   Float_t         deltaPhiAtCaloPFEle[40];   //[nPFEle]
   Float_t         hOverHEPFEle[40];   //[nPFEle]
   Float_t         hOverPPFEle[40];   //[nPFEle]
   Int_t           gsfTrackIndexPFEle[40];   //[nPFEle]
   Int_t           trackIndexPFEle[40];   //[nPFEle]
   Int_t           nSC;
   Int_t           nBCSC[100];   //[nSC]
   Int_t           nCrystalsSC[100];   //[nSC]
   Int_t           iAlgoSC[100];   //[nSC]
   Float_t         rawEnergySC[100];   //[nSC]
   Float_t         energySC[100];   //[nSC]
   Float_t         etaSC[100];   //[nSC]
   Float_t         thetaSC[100];   //[nSC]
   Float_t         phiSC[100];   //[nSC]
   Float_t         e3x3SC[100];   //[nSC]
   Float_t         e5x5SC[100];   //[nSC]
   Float_t         eMaxSC[100];   //[nSC]
   Float_t         e2x2SC[100];   //[nSC]
   Float_t         e2ndSC[100];   //[nSC]
   Float_t         covIEtaIEtaSC[100];   //[nSC]
   Float_t         covIEtaIPhiSC[100];   //[nSC]
   Float_t         covIPhiIPhiSC[100];   //[nSC]
   Float_t         hOverESC[100];   //[nSC]
   Int_t           recoFlagSC[100];   //[nSC]
   Int_t           channelStatusSC[100];   //[nSC]
   Float_t         timeSC[100];   //[nSC]
   Float_t         chi2ProbSC[100];   //[nSC]
   Float_t         seedEnergySC[100];   //[nSC]
   Int_t           idClosProblSC[100];   //[nSC]
   Int_t           sevClosProblSC[100];   //[nSC]
   Float_t         fracClosProblSC[100];   //[nSC]
   Int_t           trackIndexSC[100];   //[nSC]
   Float_t         trackDeltaRSC[100];   //[nSC]
   Float_t         trackDeltaPhiSC[100];   //[nSC]
   Float_t         trackDeltaEtaSC[100];   //[nSC]
   Int_t           gsfTrackIndexSC[100];   //[nSC]
   Float_t         gsfTrackDeltaRSC[100];   //[nSC]
   Float_t         gsfTrackDeltaPhiSC[100];   //[nSC]
   Float_t         gsfTrackDeltaEtaSC[100];   //[nSC]
   Float_t         pxVtxPropagatedNegChargeSC[100];   //[nSC]
   Float_t         pyVtxPropagatedNegChargeSC[100];   //[nSC]
   Float_t         pzVtxPropagatedNegChargeSC[100];   //[nSC]
   Float_t         pxVtxPropagatedPosChargeSC[100];   //[nSC]
   Float_t         pyVtxPropagatedPosChargeSC[100];   //[nSC]
   Float_t         pzVtxPropagatedPosChargeSC[100];   //[nSC]
   Int_t           nPFSC;
   Int_t           nBCPFSC[100];   //[nPFSC]
   Int_t           nCrystalsPFSC[100];   //[nPFSC]
   Int_t           iAlgoPFSC[100];   //[nPFSC]
   Float_t         rawEnergyPFSC[100];   //[nPFSC]
   Float_t         energyPFSC[100];   //[nPFSC]
   Float_t         etaPFSC[100];   //[nPFSC]
   Float_t         thetaPFSC[100];   //[nPFSC]
   Float_t         phiPFSC[100];   //[nPFSC]
   Float_t         e3x3PFSC[100];   //[nPFSC]
   Float_t         e5x5PFSC[100];   //[nPFSC]
   Float_t         eMaxPFSC[100];   //[nPFSC]
   Float_t         e2x2PFSC[100];   //[nPFSC]
   Float_t         e2ndPFSC[100];   //[nPFSC]
   Float_t         covIEtaIEtaPFSC[100];   //[nPFSC]
   Float_t         covIEtaIPhiPFSC[100];   //[nPFSC]
   Float_t         covIPhiIPhiPFSC[100];   //[nPFSC]
   Float_t         hOverEPFSC[100];   //[nPFSC]
   Int_t           recoFlagPFSC[100];   //[nPFSC]
   Int_t           channelStatusPFSC[100];   //[nPFSC]
   Float_t         timePFSC[100];   //[nPFSC]
   Float_t         chi2ProbPFSC[100];   //[nPFSC]
   Float_t         seedEnergyPFSC[100];   //[nPFSC]
   Int_t           idClosProblPFSC[100];   //[nPFSC]
   Int_t           sevClosProblPFSC[100];   //[nPFSC]
   Float_t         fracClosProblPFSC[100];   //[nPFSC]
   Float_t         pxVtxPropagatedNegChargePFSC[100];   //[nPFSC]
   Float_t         pyVtxPropagatedNegChargePFSC[100];   //[nPFSC]
   Float_t         pzVtxPropagatedNegChargePFSC[100];   //[nPFSC]
   Float_t         pxVtxPropagatedPosChargePFSC[100];   //[nPFSC]
   Float_t         pyVtxPropagatedPosChargePFSC[100];   //[nPFSC]
   Float_t         pzVtxPropagatedPosChargePFSC[100];   //[nPFSC]
   Int_t           nTrack;
   Float_t         pxTrack[400];   //[nTrack]
   Float_t         pyTrack[400];   //[nTrack]
   Float_t         pzTrack[400];   //[nTrack]
   Int_t           vtxIndexTrack[400];   //[nTrack]
   Float_t         vtxWeightTrack[400];   //[nTrack]
   Float_t         chargeTrack[400];   //[nTrack]
   Float_t         ptErrorTrack[400];   //[nTrack]
   Float_t         trackValidHitsTrack[400];   //[nTrack]
   Float_t         trackLostHitsTrack[400];   //[nTrack]
   Float_t         trackNormalizedChi2Track[400];   //[nTrack]
   Int_t           qualityMaskTrack[400];   //[nTrack]
   Float_t         trackDxyTrack[400];   //[nTrack]
   Float_t         trackD0Track[400];   //[nTrack]
   Float_t         trackDszTrack[400];   //[nTrack]
   Float_t         trackDzTrack[400];   //[nTrack]
   Float_t         trackDxyErrorTrack[400];   //[nTrack]
   Float_t         trackD0ErrorTrack[400];   //[nTrack]
   Float_t         trackDszErrorTrack[400];   //[nTrack]
   Float_t         trackDzErrorTrack[400];   //[nTrack]
   Float_t         trackDxyPVTrack[400];   //[nTrack]
   Float_t         trackDszPVTrack[400];   //[nTrack]
   Float_t         trackDzPVTrack[400];   //[nTrack]
   Float_t         trackVxTrack[400];   //[nTrack]
   Float_t         trackVyTrack[400];   //[nTrack]
   Float_t         trackVzTrack[400];   //[nTrack]
   Float_t         pxAtOuterTrack[400];   //[nTrack]
   Float_t         pyAtOuterTrack[400];   //[nTrack]
   Float_t         pzAtOuterTrack[400];   //[nTrack]
   Float_t         xAtOuterTrack[400];   //[nTrack]
   Float_t         yAtOuterTrack[400];   //[nTrack]
   Float_t         zAtOuterTrack[400];   //[nTrack]
   Float_t         pxAtInnerTrack[400];   //[nTrack]
   Float_t         pyAtInnerTrack[400];   //[nTrack]
   Float_t         pzAtInnerTrack[400];   //[nTrack]
   Float_t         xAtInnerTrack[400];   //[nTrack]
   Float_t         yAtInnerTrack[400];   //[nTrack]
   Float_t         zAtInnerTrack[400];   //[nTrack]
   Float_t         recHitsSizeTrack[400];   //[nTrack]
   UChar_t         isPixB1Track[400];   //[nTrack]
   UChar_t         isPixB2Track[400];   //[nTrack]
   UChar_t         isPixE1Track[400];   //[nTrack]
   UChar_t         isPixE2Track[400];   //[nTrack]
   Int_t           numberOfValidPixelBarrelHitsTrack[400];   //[nTrack]
   Int_t           numberOfValidPixelEndcapHitsTrack[400];   //[nTrack]
   Int_t           numberOfValidStripTIBHitsTrack[400];   //[nTrack]
   Int_t           numberOfValidStripTIDHitsTrack[400];   //[nTrack]
   Int_t           numberOfValidStripTOBHitsTrack[400];   //[nTrack]
   Int_t           numberOfValidStripTECHitsTrack[400];   //[nTrack]
   Float_t         truncatedDeDxTrack[400];   //[nTrack]
   Float_t         truncatedDeDxErrorTrack[400];   //[nTrack]
   Float_t         truncatedDeDxNoMTrack[400];   //[nTrack]
   Float_t         medianDeDxTrack[400];   //[nTrack]
   Float_t         medianDeDxErrorTrack[400];   //[nTrack]
   Float_t         medianDeDxNoMTrack[400];   //[nTrack]
   Float_t         harmonic2DeDxTrack[400];   //[nTrack]
   Float_t         harmonic2DeDxErrorTrack[400];   //[nTrack]
   Float_t         harmonic2DeDxNoMTrack[400];   //[nTrack]
   Int_t           nGsfTrack;
   Float_t         pxGsfTrack[300];   //[nGsfTrack]
   Float_t         pyGsfTrack[300];   //[nGsfTrack]
   Float_t         pzGsfTrack[300];   //[nGsfTrack]
   Float_t         chargeGsfTrack[300];   //[nGsfTrack]
   Float_t         ptErrorGsfTrack[300];   //[nGsfTrack]
   Float_t         trackValidHitsGsfTrack[300];   //[nGsfTrack]
   Float_t         trackLostHitsGsfTrack[300];   //[nGsfTrack]
   Float_t         trackNormalizedChi2GsfTrack[300];   //[nGsfTrack]
   Int_t           qualityMaskGsfTrack[300];   //[nGsfTrack]
   Float_t         trackDxyGsfTrack[300];   //[nGsfTrack]
   Float_t         trackD0GsfTrack[300];   //[nGsfTrack]
   Float_t         trackDszGsfTrack[300];   //[nGsfTrack]
   Float_t         trackDzGsfTrack[300];   //[nGsfTrack]
   Float_t         trackDxyErrorGsfTrack[300];   //[nGsfTrack]
   Float_t         trackD0ErrorGsfTrack[300];   //[nGsfTrack]
   Float_t         trackDszErrorGsfTrack[300];   //[nGsfTrack]
   Float_t         trackDzErrorGsfTrack[300];   //[nGsfTrack]
   Float_t         trackDxyPVGsfTrack[300];   //[nGsfTrack]
   Float_t         trackDszPVGsfTrack[300];   //[nGsfTrack]
   Float_t         trackDzPVGsfTrack[300];   //[nGsfTrack]
   Float_t         trackVxGsfTrack[300];   //[nGsfTrack]
   Float_t         trackVyGsfTrack[300];   //[nGsfTrack]
   Float_t         trackVzGsfTrack[300];   //[nGsfTrack]
   Float_t         pxAtOuterGsfTrack[300];   //[nGsfTrack]
   Float_t         pyAtOuterGsfTrack[300];   //[nGsfTrack]
   Float_t         pzAtOuterGsfTrack[300];   //[nGsfTrack]
   Float_t         xAtOuterGsfTrack[300];   //[nGsfTrack]
   Float_t         yAtOuterGsfTrack[300];   //[nGsfTrack]
   Float_t         zAtOuterGsfTrack[300];   //[nGsfTrack]
   Float_t         pxAtInnerGsfTrack[300];   //[nGsfTrack]
   Float_t         pyAtInnerGsfTrack[300];   //[nGsfTrack]
   Float_t         pzAtInnerGsfTrack[300];   //[nGsfTrack]
   Float_t         xAtInnerGsfTrack[300];   //[nGsfTrack]
   Float_t         yAtInnerGsfTrack[300];   //[nGsfTrack]
   Float_t         zAtInnerGsfTrack[300];   //[nGsfTrack]
   Float_t         recHitsSizeGsfTrack[300];   //[nGsfTrack]
   UChar_t         isPixB1GsfTrack[300];   //[nGsfTrack]
   UChar_t         isPixB2GsfTrack[300];   //[nGsfTrack]
   UChar_t         isPixE1GsfTrack[300];   //[nGsfTrack]
   UChar_t         isPixE2GsfTrack[300];   //[nGsfTrack]
   Int_t           numberOfValidPixelBarrelHitsGsfTrack[300];   //[nGsfTrack]
   Int_t           numberOfValidPixelEndcapHitsGsfTrack[300];   //[nGsfTrack]
   Int_t           numberOfValidStripTIBHitsGsfTrack[300];   //[nGsfTrack]
   Int_t           numberOfValidStripTIDHitsGsfTrack[300];   //[nGsfTrack]
   Int_t           numberOfValidStripTOBHitsGsfTrack[300];   //[nGsfTrack]
   Int_t           numberOfValidStripTECHitsGsfTrack[300];   //[nGsfTrack]
   Int_t           chargeModeGsfTrack[300];   //[nGsfTrack]
   Float_t         pxModeGsfTrack[300];   //[nGsfTrack]
   Float_t         pyModeGsfTrack[300];   //[nGsfTrack]
   Float_t         pzModeGsfTrack[300];   //[nGsfTrack]
   Int_t           recoFlagsGsfTrack[300];   //[nGsfTrack]
   Int_t           nPV;
   Float_t         PVxPV[400];   //[nPV]
   Float_t         PVyPV[400];   //[nPV]
   Float_t         PVzPV[400];   //[nPV]
   Float_t         PVErrxPV[400];   //[nPV]
   Float_t         PVErryPV[400];   //[nPV]
   Float_t         PVErrzPV[400];   //[nPV]
   Float_t         SumPtPV[400];   //[nPV]
   Float_t         ndofPV[400];   //[nPV]
   Float_t         chi2PV[400];   //[nPV]
   Double_t        genPtHat;
   Double_t        genProcessId;
   Double_t        genWeight;
   Double_t        genAlphaQCD;
   Double_t        genAlphaQED;

   // List of branches
   TBranch        *b_nl1Technical;   //!
   TBranch        *b_l1Technical;   //!
   TBranch        *b_nl1Global;   //!
   TBranch        *b_l1Global;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_lumiBlock;   //!
   TBranch        *b_bunchCrossing;   //!
   TBranch        *b_orbitNumber;   //!
   TBranch        *b_nMc;   //!
   TBranch        *b_pMc;   //!
   TBranch        *b_massMc;   //!
   TBranch        *b_thetaMc;   //!
   TBranch        *b_etaMc;   //!
   TBranch        *b_phiMc;   //!
   TBranch        *b_energyMc;   //!
   TBranch        *b_idMc;   //!
   TBranch        *b_mothMc;   //!
   TBranch        *b_nDauMc;   //!
   TBranch        *b_statusMc;   //!
   TBranch        *b_xMc;   //!
   TBranch        *b_yMc;   //!
   TBranch        *b_zMc;   //!
   TBranch        *b_nEle;   //!
   TBranch        *b_chargeEle;   //!
   TBranch        *b_energyEle;   //!
   TBranch        *b_etEle;   //!
   TBranch        *b_momentumEle;   //!
   TBranch        *b_thetaEle;   //!
   TBranch        *b_etaEle;   //!
   TBranch        *b_phiEle;   //!
   TBranch        *b_pxEle;   //!
   TBranch        *b_pyEle;   //!
   TBranch        *b_pzEle;   //!
   TBranch        *b_vertexXEle;   //!
   TBranch        *b_vertexYEle;   //!
   TBranch        *b_vertexZEle;   //!
   TBranch        *b_massEle;   //!
   TBranch        *b_fiducialFlagsEle;   //!
   TBranch        *b_recoFlagsEle;   //!
   TBranch        *b_energyCorrectionsEle;   //!
   TBranch        *b_esEnergyEle;   //!
   TBranch        *b_superClusterIndexEle;   //!
   TBranch        *b_PFsuperClusterIndexEle;   //!
   TBranch        *b_trackIndexEle;   //!
   TBranch        *b_gsfTrackIndexEle;   //!
   TBranch        *b_PFChi2EcalTrackEle;   //!
   TBranch        *b_PFesEneL1Ele;   //!
   TBranch        *b_PFesEneL2Ele;   //!
   TBranch        *b_PFesChi2L1Ele;   //!
   TBranch        *b_PFesChi2L2Ele;   //!
   TBranch        *b_classificationEle;   //!
   TBranch        *b_standardClassificationEle;   //!
   TBranch        *b_hOverEEle;   //!
   TBranch        *b_eSuperClusterOverPEle;   //!
   TBranch        *b_eSeedOverPoutEle;   //!
   TBranch        *b_deltaEtaAtVtxEle;   //!
   TBranch        *b_deltaPhiAtVtxEle;   //!
   TBranch        *b_deltaEtaAtCaloEle;   //!
   TBranch        *b_deltaPhiAtCaloEle;   //!
   TBranch        *b_tipEle;   //!
   TBranch        *b_dr03TkSumPtEle;   //!
   TBranch        *b_dr03EcalRecHitSumEtEle;   //!
   TBranch        *b_dr03HcalTowerSumEtEle;   //!
   TBranch        *b_dr04TkSumPtEle;   //!
   TBranch        *b_dr04EcalRecHitSumEtEle;   //!
   TBranch        *b_dr04HcalTowerSumEtEle;   //!
   TBranch        *b_scBasedEcalSum03Ele;   //!
   TBranch        *b_scBasedEcalSum04Ele;   //!
   TBranch        *b_scHaloBasedEcalSum03Ele;   //!
   TBranch        *b_scHaloBasedEcalSum04Ele;   //!
   TBranch        *b_eleIdCutsEle;   //!
   TBranch        *b_eleIdLikelihoodEle;   //!
   TBranch        *b_pflowMVAEle;   //!
   TBranch        *b_nPFEle;   //!
   TBranch        *b_chargePFEle;   //!
   TBranch        *b_energyPFEle;   //!
   TBranch        *b_etPFEle;   //!
   TBranch        *b_momentumPFEle;   //!
   TBranch        *b_thetaPFEle;   //!
   TBranch        *b_etaPFEle;   //!
   TBranch        *b_phiPFEle;   //!
   TBranch        *b_pxPFEle;   //!
   TBranch        *b_pyPFEle;   //!
   TBranch        *b_pzPFEle;   //!
   TBranch        *b_vertexXPFEle;   //!
   TBranch        *b_vertexYPFEle;   //!
   TBranch        *b_vertexZPFEle;   //!
   TBranch        *b_massPFEle;   //!
   TBranch        *b_MvaOutputPFEle;   //!
   TBranch        *b_PS1EnergyPFEle;   //!
   TBranch        *b_PS2EnergyPFEle;   //!
   TBranch        *b_EcalEnergyPFEle;   //!
   TBranch        *b_EcalElectronEnergyPFEle;   //!
   TBranch        *b_EoPModePFEle;   //!
   TBranch        *b_EoPoutModePFEle;   //!
   TBranch        *b_EBremoDeltaPPFEle;   //!
   TBranch        *b_deltaEtaAtCaloPFEle;   //!
   TBranch        *b_deltaPhiAtCaloPFEle;   //!
   TBranch        *b_hOverHEPFEle;   //!
   TBranch        *b_hOverPPFEle;   //!
   TBranch        *b_gsfTrackIndexPFEle;   //!
   TBranch        *b_trackIndexPFEle;   //!
   TBranch        *b_nSC;   //!
   TBranch        *b_nBCSC;   //!
   TBranch        *b_nCrystalsSC;   //!
   TBranch        *b_iAlgoSC;   //!
   TBranch        *b_rawEnergySC;   //!
   TBranch        *b_energySC;   //!
   TBranch        *b_etaSC;   //!
   TBranch        *b_thetaSC;   //!
   TBranch        *b_phiSC;   //!
   TBranch        *b_e3x3SC;   //!
   TBranch        *b_e5x5SC;   //!
   TBranch        *b_eMaxSC;   //!
   TBranch        *b_e2x2SC;   //!
   TBranch        *b_e2ndSC;   //!
   TBranch        *b_covIEtaIEtaSC;   //!
   TBranch        *b_covIEtaIPhiSC;   //!
   TBranch        *b_covIPhiIPhiSC;   //!
   TBranch        *b_hOverESC;   //!
   TBranch        *b_recoFlagSC;   //!
   TBranch        *b_channelStatusSC;   //!
   TBranch        *b_timeSC;   //!
   TBranch        *b_chi2ProbSC;   //!
   TBranch        *b_seedEnergySC;   //!
   TBranch        *b_idClosProblSC;   //!
   TBranch        *b_sevClosProblSC;   //!
   TBranch        *b_fracClosProblSC;   //!
   TBranch        *b_trackIndexSC;   //!
   TBranch        *b_trackDeltaRSC;   //!
   TBranch        *b_trackDeltaPhiSC;   //!
   TBranch        *b_trackDeltaEtaSC;   //!
   TBranch        *b_gsfTrackIndexSC;   //!
   TBranch        *b_gsfTrackDeltaRSC;   //!
   TBranch        *b_gsfTrackDeltaPhiSC;   //!
   TBranch        *b_gsfTrackDeltaEtaSC;   //!
   TBranch        *b_pxVtxPropagatedNegChargeSC;   //!
   TBranch        *b_pyVtxPropagatedNegChargeSC;   //!
   TBranch        *b_pzVtxPropagatedNegChargeSC;   //!
   TBranch        *b_pxVtxPropagatedPosChargeSC;   //!
   TBranch        *b_pyVtxPropagatedPosChargeSC;   //!
   TBranch        *b_pzVtxPropagatedPosChargeSC;   //!
   TBranch        *b_nPFSC;   //!
   TBranch        *b_nBCPFSC;   //!
   TBranch        *b_nCrystalsPFSC;   //!
   TBranch        *b_iAlgoPFSC;   //!
   TBranch        *b_rawEnergyPFSC;   //!
   TBranch        *b_energyPFSC;   //!
   TBranch        *b_etaPFSC;   //!
   TBranch        *b_thetaPFSC;   //!
   TBranch        *b_phiPFSC;   //!
   TBranch        *b_e3x3PFSC;   //!
   TBranch        *b_e5x5PFSC;   //!
   TBranch        *b_eMaxPFSC;   //!
   TBranch        *b_e2x2PFSC;   //!
   TBranch        *b_e2ndPFSC;   //!
   TBranch        *b_covIEtaIEtaPFSC;   //!
   TBranch        *b_covIEtaIPhiPFSC;   //!
   TBranch        *b_covIPhiIPhiPFSC;   //!
   TBranch        *b_hOverEPFSC;   //!
   TBranch        *b_recoFlagPFSC;   //!
   TBranch        *b_channelStatusPFSC;   //!
   TBranch        *b_timePFSC;   //!
   TBranch        *b_chi2ProbPFSC;   //!
   TBranch        *b_seedEnergyPFSC;   //!
   TBranch        *b_idClosProblPFSC;   //!
   TBranch        *b_sevClosProblPFSC;   //!
   TBranch        *b_fracClosProblPFSC;   //!
   TBranch        *b_pxVtxPropagatedNegChargePFSC;   //!
   TBranch        *b_pyVtxPropagatedNegChargePFSC;   //!
   TBranch        *b_pzVtxPropagatedNegChargePFSC;   //!
   TBranch        *b_pxVtxPropagatedPosChargePFSC;   //!
   TBranch        *b_pyVtxPropagatedPosChargePFSC;   //!
   TBranch        *b_pzVtxPropagatedPosChargePFSC;   //!
   TBranch        *b_nTrack;   //!
   TBranch        *b_pxTrack;   //!
   TBranch        *b_pyTrack;   //!
   TBranch        *b_pzTrack;   //!
   TBranch        *b_vtxIndexTrack;   //!
   TBranch        *b_vtxWeightTrack;   //!
   TBranch        *b_chargeTrack;   //!
   TBranch        *b_ptErrorTrack;   //!
   TBranch        *b_trackValidHitsTrack;   //!
   TBranch        *b_trackLostHitsTrack;   //!
   TBranch        *b_trackNormalizedChi2Track;   //!
   TBranch        *b_qualityMaskTrack;   //!
   TBranch        *b_trackDxyTrack;   //!
   TBranch        *b_trackD0Track;   //!
   TBranch        *b_trackDszTrack;   //!
   TBranch        *b_trackDzTrack;   //!
   TBranch        *b_trackDxyErrorTrack;   //!
   TBranch        *b_trackD0ErrorTrack;   //!
   TBranch        *b_trackDszErrorTrack;   //!
   TBranch        *b_trackDzErrorTrack;   //!
   TBranch        *b_trackDxyPVTrack;   //!
   TBranch        *b_trackDszPVTrack;   //!
   TBranch        *b_trackDzPVTrack;   //!
   TBranch        *b_trackVxTrack;   //!
   TBranch        *b_trackVyTrack;   //!
   TBranch        *b_trackVzTrack;   //!
   TBranch        *b_pxAtOuterTrack;   //!
   TBranch        *b_pyAtOuterTrack;   //!
   TBranch        *b_pzAtOuterTrack;   //!
   TBranch        *b_xAtOuterTrack;   //!
   TBranch        *b_yAtOuterTrack;   //!
   TBranch        *b_zAtOuterTrack;   //!
   TBranch        *b_pxAtInnerTrack;   //!
   TBranch        *b_pyAtInnerTrack;   //!
   TBranch        *b_pzAtInnerTrack;   //!
   TBranch        *b_xAtInnerTrack;   //!
   TBranch        *b_yAtInnerTrack;   //!
   TBranch        *b_zAtInnerTrack;   //!
   TBranch        *b_recHitsSizeTrack;   //!
   TBranch        *b_isPixB1Track;   //!
   TBranch        *b_isPixB2Track;   //!
   TBranch        *b_isPixE1Track;   //!
   TBranch        *b_isPixE2Track;   //!
   TBranch        *b_numberOfValidPixelBarrelHitsTrack;   //!
   TBranch        *b_numberOfValidPixelEndcapHitsTrack;   //!
   TBranch        *b_numberOfValidStripTIBHitsTrack;   //!
   TBranch        *b_numberOfValidStripTIDHitsTrack;   //!
   TBranch        *b_numberOfValidStripTOBHitsTrack;   //!
   TBranch        *b_numberOfValidStripTECHitsTrack;   //!
   TBranch        *b_truncatedDeDxTrack;   //!
   TBranch        *b_truncatedDeDxErrorTrack;   //!
   TBranch        *b_truncatedDeDxNoMTrack;   //!
   TBranch        *b_medianDeDxTrack;   //!
   TBranch        *b_medianDeDxErrorTrack;   //!
   TBranch        *b_medianDeDxNoMTrack;   //!
   TBranch        *b_harmonic2DeDxTrack;   //!
   TBranch        *b_harmonic2DeDxErrorTrack;   //!
   TBranch        *b_harmonic2DeDxNoMTrack;   //!
   TBranch        *b_nGsfTrack;   //!
   TBranch        *b_pxGsfTrack;   //!
   TBranch        *b_pyGsfTrack;   //!
   TBranch        *b_pzGsfTrack;   //!
   TBranch        *b_chargeGsfTrack;   //!
   TBranch        *b_ptErrorGsfTrack;   //!
   TBranch        *b_trackValidHitsGsfTrack;   //!
   TBranch        *b_trackLostHitsGsfTrack;   //!
   TBranch        *b_trackNormalizedChi2GsfTrack;   //!
   TBranch        *b_qualityMaskGsfTrack;   //!
   TBranch        *b_trackDxyGsfTrack;   //!
   TBranch        *b_trackD0GsfTrack;   //!
   TBranch        *b_trackDszGsfTrack;   //!
   TBranch        *b_trackDzGsfTrack;   //!
   TBranch        *b_trackDxyErrorGsfTrack;   //!
   TBranch        *b_trackD0ErrorGsfTrack;   //!
   TBranch        *b_trackDszErrorGsfTrack;   //!
   TBranch        *b_trackDzErrorGsfTrack;   //!
   TBranch        *b_trackDxyPVGsfTrack;   //!
   TBranch        *b_trackDszPVGsfTrack;   //!
   TBranch        *b_trackDzPVGsfTrack;   //!
   TBranch        *b_trackVxGsfTrack;   //!
   TBranch        *b_trackVyGsfTrack;   //!
   TBranch        *b_trackVzGsfTrack;   //!
   TBranch        *b_pxAtOuterGsfTrack;   //!
   TBranch        *b_pyAtOuterGsfTrack;   //!
   TBranch        *b_pzAtOuterGsfTrack;   //!
   TBranch        *b_xAtOuterGsfTrack;   //!
   TBranch        *b_yAtOuterGsfTrack;   //!
   TBranch        *b_zAtOuterGsfTrack;   //!
   TBranch        *b_pxAtInnerGsfTrack;   //!
   TBranch        *b_pyAtInnerGsfTrack;   //!
   TBranch        *b_pzAtInnerGsfTrack;   //!
   TBranch        *b_xAtInnerGsfTrack;   //!
   TBranch        *b_yAtInnerGsfTrack;   //!
   TBranch        *b_zAtInnerGsfTrack;   //!
   TBranch        *b_recHitsSizeGsfTrack;   //!
   TBranch        *b_isPixB1GsfTrack;   //!
   TBranch        *b_isPixB2GsfTrack;   //!
   TBranch        *b_isPixE1GsfTrack;   //!
   TBranch        *b_isPixE2GsfTrack;   //!
   TBranch        *b_numberOfValidPixelBarrelHitsGsfTrack;   //!
   TBranch        *b_numberOfValidPixelEndcapHitsGsfTrack;   //!
   TBranch        *b_numberOfValidStripTIBHitsGsfTrack;   //!
   TBranch        *b_numberOfValidStripTIDHitsGsfTrack;   //!
   TBranch        *b_numberOfValidStripTOBHitsGsfTrack;   //!
   TBranch        *b_numberOfValidStripTECHitsGsfTrack;   //!
   TBranch        *b_chargeModeGsfTrack;   //!
   TBranch        *b_pxModeGsfTrack;   //!
   TBranch        *b_pyModeGsfTrack;   //!
   TBranch        *b_pzModeGsfTrack;   //!
   TBranch        *b_recoFlagsGsfTrack;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_PVxPV;   //!
   TBranch        *b_PVyPV;   //!
   TBranch        *b_PVzPV;   //!
   TBranch        *b_PVErrxPV;   //!
   TBranch        *b_PVErryPV;   //!
   TBranch        *b_PVErrzPV;   //!
   TBranch        *b_SumPtPV;   //!
   TBranch        *b_ndofPV;   //!
   TBranch        *b_chi2PV;   //!
   TBranch        *b_genPtHat;   //!
   TBranch        *b_genProcessId;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_genAlphaQCD;   //!
   TBranch        *b_genAlphaQED;   //!

   JPsiBase(TTree *tree=0);
   virtual ~JPsiBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef JPsiBase_cxx
JPsiBase::JPsiBase(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("rfio:///castor/cern.ch/user/e/emanuele/JPsi/Trees3/JPsiEE_2360GeV_EGMSkimV6/default_MC_1.root");
      if (!f) {
         f = new TFile("rfio:///castor/cern.ch/user/e/emanuele/JPsi/Trees3/JPsiEE_2360GeV_EGMSkimV6/default_MC_1.root");
      }
      tree = (TTree*)gDirectory->Get("ntp1");

   }
   Init(tree);
}

JPsiBase::~JPsiBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t JPsiBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t JPsiBase::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void JPsiBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nl1Technical", &nl1Technical, &b_nl1Technical);
   fChain->SetBranchAddress("l1Technical", l1Technical, &b_l1Technical);
   fChain->SetBranchAddress("nl1Global", &nl1Global, &b_nl1Global);
   fChain->SetBranchAddress("l1Global", l1Global, &b_l1Global);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("lumiBlock", &lumiBlock, &b_lumiBlock);
   fChain->SetBranchAddress("bunchCrossing", &bunchCrossing, &b_bunchCrossing);
   fChain->SetBranchAddress("orbitNumber", &orbitNumber, &b_orbitNumber);
   fChain->SetBranchAddress("nMc", &nMc, &b_nMc);
   fChain->SetBranchAddress("pMc", pMc, &b_pMc);
   fChain->SetBranchAddress("massMc", massMc, &b_massMc);
   fChain->SetBranchAddress("thetaMc", thetaMc, &b_thetaMc);
   fChain->SetBranchAddress("etaMc", etaMc, &b_etaMc);
   fChain->SetBranchAddress("phiMc", phiMc, &b_phiMc);
   fChain->SetBranchAddress("energyMc", energyMc, &b_energyMc);
   fChain->SetBranchAddress("idMc", idMc, &b_idMc);
   fChain->SetBranchAddress("mothMc", mothMc, &b_mothMc);
   fChain->SetBranchAddress("nDauMc", nDauMc, &b_nDauMc);
   fChain->SetBranchAddress("statusMc", statusMc, &b_statusMc);
   fChain->SetBranchAddress("xMc", xMc, &b_xMc);
   fChain->SetBranchAddress("yMc", yMc, &b_yMc);
   fChain->SetBranchAddress("zMc", zMc, &b_zMc);
   fChain->SetBranchAddress("nEle", &nEle, &b_nEle);
   fChain->SetBranchAddress("chargeEle", chargeEle, &b_chargeEle);
   fChain->SetBranchAddress("energyEle", energyEle, &b_energyEle);
   fChain->SetBranchAddress("etEle", etEle, &b_etEle);
   fChain->SetBranchAddress("momentumEle", momentumEle, &b_momentumEle);
   fChain->SetBranchAddress("thetaEle", thetaEle, &b_thetaEle);
   fChain->SetBranchAddress("etaEle", etaEle, &b_etaEle);
   fChain->SetBranchAddress("phiEle", phiEle, &b_phiEle);
   fChain->SetBranchAddress("pxEle", pxEle, &b_pxEle);
   fChain->SetBranchAddress("pyEle", pyEle, &b_pyEle);
   fChain->SetBranchAddress("pzEle", pzEle, &b_pzEle);
   fChain->SetBranchAddress("vertexXEle", vertexXEle, &b_vertexXEle);
   fChain->SetBranchAddress("vertexYEle", vertexYEle, &b_vertexYEle);
   fChain->SetBranchAddress("vertexZEle", vertexZEle, &b_vertexZEle);
   fChain->SetBranchAddress("massEle", massEle, &b_massEle);
   fChain->SetBranchAddress("fiducialFlagsEle", fiducialFlagsEle, &b_fiducialFlagsEle);
   fChain->SetBranchAddress("recoFlagsEle", recoFlagsEle, &b_recoFlagsEle);
   fChain->SetBranchAddress("energyCorrectionsEle", energyCorrectionsEle, &b_energyCorrectionsEle);
   fChain->SetBranchAddress("esEnergyEle", esEnergyEle, &b_esEnergyEle);
   fChain->SetBranchAddress("superClusterIndexEle", superClusterIndexEle, &b_superClusterIndexEle);
   fChain->SetBranchAddress("PFsuperClusterIndexEle", PFsuperClusterIndexEle, &b_PFsuperClusterIndexEle);
   fChain->SetBranchAddress("trackIndexEle", trackIndexEle, &b_trackIndexEle);
   fChain->SetBranchAddress("gsfTrackIndexEle", gsfTrackIndexEle, &b_gsfTrackIndexEle);
   fChain->SetBranchAddress("PFChi2EcalTrackEle", PFChi2EcalTrackEle, &b_PFChi2EcalTrackEle);
   fChain->SetBranchAddress("PFesEneL1Ele", PFesEneL1Ele, &b_PFesEneL1Ele);
   fChain->SetBranchAddress("PFesEneL2Ele", PFesEneL2Ele, &b_PFesEneL2Ele);
   fChain->SetBranchAddress("PFesChi2L1Ele", PFesChi2L1Ele, &b_PFesChi2L1Ele);
   fChain->SetBranchAddress("PFesChi2L2Ele", PFesChi2L2Ele, &b_PFesChi2L2Ele);
   fChain->SetBranchAddress("classificationEle", classificationEle, &b_classificationEle);
   fChain->SetBranchAddress("standardClassificationEle", standardClassificationEle, &b_standardClassificationEle);
   fChain->SetBranchAddress("hOverEEle", hOverEEle, &b_hOverEEle);
   fChain->SetBranchAddress("eSuperClusterOverPEle", eSuperClusterOverPEle, &b_eSuperClusterOverPEle);
   fChain->SetBranchAddress("eSeedOverPoutEle", eSeedOverPoutEle, &b_eSeedOverPoutEle);
   fChain->SetBranchAddress("deltaEtaAtVtxEle", deltaEtaAtVtxEle, &b_deltaEtaAtVtxEle);
   fChain->SetBranchAddress("deltaPhiAtVtxEle", deltaPhiAtVtxEle, &b_deltaPhiAtVtxEle);
   fChain->SetBranchAddress("deltaEtaAtCaloEle", deltaEtaAtCaloEle, &b_deltaEtaAtCaloEle);
   fChain->SetBranchAddress("deltaPhiAtCaloEle", deltaPhiAtCaloEle, &b_deltaPhiAtCaloEle);
   fChain->SetBranchAddress("tipEle", tipEle, &b_tipEle);
   fChain->SetBranchAddress("dr03TkSumPtEle", dr03TkSumPtEle, &b_dr03TkSumPtEle);
   fChain->SetBranchAddress("dr03EcalRecHitSumEtEle", dr03EcalRecHitSumEtEle, &b_dr03EcalRecHitSumEtEle);
   fChain->SetBranchAddress("dr03HcalTowerSumEtEle", dr03HcalTowerSumEtEle, &b_dr03HcalTowerSumEtEle);
   fChain->SetBranchAddress("dr04TkSumPtEle", dr04TkSumPtEle, &b_dr04TkSumPtEle);
   fChain->SetBranchAddress("dr04EcalRecHitSumEtEle", dr04EcalRecHitSumEtEle, &b_dr04EcalRecHitSumEtEle);
   fChain->SetBranchAddress("dr04HcalTowerSumEtEle", dr04HcalTowerSumEtEle, &b_dr04HcalTowerSumEtEle);
   fChain->SetBranchAddress("scBasedEcalSum03Ele", scBasedEcalSum03Ele, &b_scBasedEcalSum03Ele);
   fChain->SetBranchAddress("scBasedEcalSum04Ele", scBasedEcalSum04Ele, &b_scBasedEcalSum04Ele);
   fChain->SetBranchAddress("scHaloBasedEcalSum03Ele", scHaloBasedEcalSum03Ele, &b_scHaloBasedEcalSum03Ele);
   fChain->SetBranchAddress("scHaloBasedEcalSum04Ele", scHaloBasedEcalSum04Ele, &b_scHaloBasedEcalSum04Ele);
   fChain->SetBranchAddress("eleIdCutsEle", eleIdCutsEle, &b_eleIdCutsEle);
   fChain->SetBranchAddress("eleIdLikelihoodEle", eleIdLikelihoodEle, &b_eleIdLikelihoodEle);
   fChain->SetBranchAddress("pflowMVAEle", pflowMVAEle, &b_pflowMVAEle);
   fChain->SetBranchAddress("nPFEle", &nPFEle, &b_nPFEle);
   fChain->SetBranchAddress("chargePFEle", chargePFEle, &b_chargePFEle);
   fChain->SetBranchAddress("energyPFEle", energyPFEle, &b_energyPFEle);
   fChain->SetBranchAddress("etPFEle", etPFEle, &b_etPFEle);
   fChain->SetBranchAddress("momentumPFEle", momentumPFEle, &b_momentumPFEle);
   fChain->SetBranchAddress("thetaPFEle", thetaPFEle, &b_thetaPFEle);
   fChain->SetBranchAddress("etaPFEle", etaPFEle, &b_etaPFEle);
   fChain->SetBranchAddress("phiPFEle", phiPFEle, &b_phiPFEle);
   fChain->SetBranchAddress("pxPFEle", pxPFEle, &b_pxPFEle);
   fChain->SetBranchAddress("pyPFEle", pyPFEle, &b_pyPFEle);
   fChain->SetBranchAddress("pzPFEle", pzPFEle, &b_pzPFEle);
   fChain->SetBranchAddress("vertexXPFEle", vertexXPFEle, &b_vertexXPFEle);
   fChain->SetBranchAddress("vertexYPFEle", vertexYPFEle, &b_vertexYPFEle);
   fChain->SetBranchAddress("vertexZPFEle", vertexZPFEle, &b_vertexZPFEle);
   fChain->SetBranchAddress("massPFEle", massPFEle, &b_massPFEle);
   fChain->SetBranchAddress("MvaOutputPFEle", MvaOutputPFEle, &b_MvaOutputPFEle);
   fChain->SetBranchAddress("PS1EnergyPFEle", PS1EnergyPFEle, &b_PS1EnergyPFEle);
   fChain->SetBranchAddress("PS2EnergyPFEle", PS2EnergyPFEle, &b_PS2EnergyPFEle);
   fChain->SetBranchAddress("EcalEnergyPFEle", EcalEnergyPFEle, &b_EcalEnergyPFEle);
   fChain->SetBranchAddress("EcalElectronEnergyPFEle", EcalElectronEnergyPFEle, &b_EcalElectronEnergyPFEle);
   fChain->SetBranchAddress("EoPModePFEle", EoPModePFEle, &b_EoPModePFEle);
   fChain->SetBranchAddress("EoPoutModePFEle", EoPoutModePFEle, &b_EoPoutModePFEle);
   fChain->SetBranchAddress("EBremoDeltaPPFEle", EBremoDeltaPPFEle, &b_EBremoDeltaPPFEle);
   fChain->SetBranchAddress("deltaEtaAtCaloPFEle", deltaEtaAtCaloPFEle, &b_deltaEtaAtCaloPFEle);
   fChain->SetBranchAddress("deltaPhiAtCaloPFEle", deltaPhiAtCaloPFEle, &b_deltaPhiAtCaloPFEle);
   fChain->SetBranchAddress("hOverHEPFEle", hOverHEPFEle, &b_hOverHEPFEle);
   fChain->SetBranchAddress("hOverPPFEle", hOverPPFEle, &b_hOverPPFEle);
   fChain->SetBranchAddress("gsfTrackIndexPFEle", gsfTrackIndexPFEle, &b_gsfTrackIndexPFEle);
   fChain->SetBranchAddress("trackIndexPFEle", trackIndexPFEle, &b_trackIndexPFEle);
   fChain->SetBranchAddress("nSC", &nSC, &b_nSC);
   fChain->SetBranchAddress("nBCSC", nBCSC, &b_nBCSC);
   fChain->SetBranchAddress("nCrystalsSC", nCrystalsSC, &b_nCrystalsSC);
   fChain->SetBranchAddress("iAlgoSC", iAlgoSC, &b_iAlgoSC);
   fChain->SetBranchAddress("rawEnergySC", rawEnergySC, &b_rawEnergySC);
   fChain->SetBranchAddress("energySC", energySC, &b_energySC);
   fChain->SetBranchAddress("etaSC", etaSC, &b_etaSC);
   fChain->SetBranchAddress("thetaSC", thetaSC, &b_thetaSC);
   fChain->SetBranchAddress("phiSC", phiSC, &b_phiSC);
   fChain->SetBranchAddress("e3x3SC", e3x3SC, &b_e3x3SC);
   fChain->SetBranchAddress("e5x5SC", e5x5SC, &b_e5x5SC);
   fChain->SetBranchAddress("eMaxSC", eMaxSC, &b_eMaxSC);
   fChain->SetBranchAddress("e2x2SC", e2x2SC, &b_e2x2SC);
   fChain->SetBranchAddress("e2ndSC", e2ndSC, &b_e2ndSC);
   fChain->SetBranchAddress("covIEtaIEtaSC", covIEtaIEtaSC, &b_covIEtaIEtaSC);
   fChain->SetBranchAddress("covIEtaIPhiSC", covIEtaIPhiSC, &b_covIEtaIPhiSC);
   fChain->SetBranchAddress("covIPhiIPhiSC", covIPhiIPhiSC, &b_covIPhiIPhiSC);
   fChain->SetBranchAddress("hOverESC", hOverESC, &b_hOverESC);
   fChain->SetBranchAddress("recoFlagSC", recoFlagSC, &b_recoFlagSC);
   fChain->SetBranchAddress("channelStatusSC", channelStatusSC, &b_channelStatusSC);
   fChain->SetBranchAddress("timeSC", timeSC, &b_timeSC);
   fChain->SetBranchAddress("chi2ProbSC", chi2ProbSC, &b_chi2ProbSC);
   fChain->SetBranchAddress("seedEnergySC", seedEnergySC, &b_seedEnergySC);
   fChain->SetBranchAddress("idClosProblSC", idClosProblSC, &b_idClosProblSC);
   fChain->SetBranchAddress("sevClosProblSC", sevClosProblSC, &b_sevClosProblSC);
   fChain->SetBranchAddress("fracClosProblSC", fracClosProblSC, &b_fracClosProblSC);
   fChain->SetBranchAddress("trackIndexSC", trackIndexSC, &b_trackIndexSC);
   fChain->SetBranchAddress("trackDeltaRSC", trackDeltaRSC, &b_trackDeltaRSC);
   fChain->SetBranchAddress("trackDeltaPhiSC", trackDeltaPhiSC, &b_trackDeltaPhiSC);
   fChain->SetBranchAddress("trackDeltaEtaSC", trackDeltaEtaSC, &b_trackDeltaEtaSC);
   fChain->SetBranchAddress("gsfTrackIndexSC", gsfTrackIndexSC, &b_gsfTrackIndexSC);
   fChain->SetBranchAddress("gsfTrackDeltaRSC", gsfTrackDeltaRSC, &b_gsfTrackDeltaRSC);
   fChain->SetBranchAddress("gsfTrackDeltaPhiSC", gsfTrackDeltaPhiSC, &b_gsfTrackDeltaPhiSC);
   fChain->SetBranchAddress("gsfTrackDeltaEtaSC", gsfTrackDeltaEtaSC, &b_gsfTrackDeltaEtaSC);
   fChain->SetBranchAddress("pxVtxPropagatedNegChargeSC", pxVtxPropagatedNegChargeSC, &b_pxVtxPropagatedNegChargeSC);
   fChain->SetBranchAddress("pyVtxPropagatedNegChargeSC", pyVtxPropagatedNegChargeSC, &b_pyVtxPropagatedNegChargeSC);
   fChain->SetBranchAddress("pzVtxPropagatedNegChargeSC", pzVtxPropagatedNegChargeSC, &b_pzVtxPropagatedNegChargeSC);
   fChain->SetBranchAddress("pxVtxPropagatedPosChargeSC", pxVtxPropagatedPosChargeSC, &b_pxVtxPropagatedPosChargeSC);
   fChain->SetBranchAddress("pyVtxPropagatedPosChargeSC", pyVtxPropagatedPosChargeSC, &b_pyVtxPropagatedPosChargeSC);
   fChain->SetBranchAddress("pzVtxPropagatedPosChargeSC", pzVtxPropagatedPosChargeSC, &b_pzVtxPropagatedPosChargeSC);
   fChain->SetBranchAddress("nPFSC", &nPFSC, &b_nPFSC);
   fChain->SetBranchAddress("nBCPFSC", nBCPFSC, &b_nBCPFSC);
   fChain->SetBranchAddress("nCrystalsPFSC", nCrystalsPFSC, &b_nCrystalsPFSC);
   fChain->SetBranchAddress("iAlgoPFSC", iAlgoPFSC, &b_iAlgoPFSC);
   fChain->SetBranchAddress("rawEnergyPFSC", rawEnergyPFSC, &b_rawEnergyPFSC);
   fChain->SetBranchAddress("energyPFSC", energyPFSC, &b_energyPFSC);
   fChain->SetBranchAddress("etaPFSC", etaPFSC, &b_etaPFSC);
   fChain->SetBranchAddress("thetaPFSC", thetaPFSC, &b_thetaPFSC);
   fChain->SetBranchAddress("phiPFSC", phiPFSC, &b_phiPFSC);
   fChain->SetBranchAddress("e3x3PFSC", e3x3PFSC, &b_e3x3PFSC);
   fChain->SetBranchAddress("e5x5PFSC", e5x5PFSC, &b_e5x5PFSC);
   fChain->SetBranchAddress("eMaxPFSC", eMaxPFSC, &b_eMaxPFSC);
   fChain->SetBranchAddress("e2x2PFSC", e2x2PFSC, &b_e2x2PFSC);
   fChain->SetBranchAddress("e2ndPFSC", e2ndPFSC, &b_e2ndPFSC);
   fChain->SetBranchAddress("covIEtaIEtaPFSC", covIEtaIEtaPFSC, &b_covIEtaIEtaPFSC);
   fChain->SetBranchAddress("covIEtaIPhiPFSC", covIEtaIPhiPFSC, &b_covIEtaIPhiPFSC);
   fChain->SetBranchAddress("covIPhiIPhiPFSC", covIPhiIPhiPFSC, &b_covIPhiIPhiPFSC);
   fChain->SetBranchAddress("hOverEPFSC", hOverEPFSC, &b_hOverEPFSC);
   fChain->SetBranchAddress("recoFlagPFSC", recoFlagPFSC, &b_recoFlagPFSC);
   fChain->SetBranchAddress("channelStatusPFSC", channelStatusPFSC, &b_channelStatusPFSC);
   fChain->SetBranchAddress("timePFSC", timePFSC, &b_timePFSC);
   fChain->SetBranchAddress("chi2ProbPFSC", chi2ProbPFSC, &b_chi2ProbPFSC);
   fChain->SetBranchAddress("seedEnergyPFSC", seedEnergyPFSC, &b_seedEnergyPFSC);
   fChain->SetBranchAddress("idClosProblPFSC", idClosProblPFSC, &b_idClosProblPFSC);
   fChain->SetBranchAddress("sevClosProblPFSC", sevClosProblPFSC, &b_sevClosProblPFSC);
   fChain->SetBranchAddress("fracClosProblPFSC", fracClosProblPFSC, &b_fracClosProblPFSC);
   fChain->SetBranchAddress("pxVtxPropagatedNegChargePFSC", pxVtxPropagatedNegChargePFSC, &b_pxVtxPropagatedNegChargePFSC);
   fChain->SetBranchAddress("pyVtxPropagatedNegChargePFSC", pyVtxPropagatedNegChargePFSC, &b_pyVtxPropagatedNegChargePFSC);
   fChain->SetBranchAddress("pzVtxPropagatedNegChargePFSC", pzVtxPropagatedNegChargePFSC, &b_pzVtxPropagatedNegChargePFSC);
   fChain->SetBranchAddress("pxVtxPropagatedPosChargePFSC", pxVtxPropagatedPosChargePFSC, &b_pxVtxPropagatedPosChargePFSC);
   fChain->SetBranchAddress("pyVtxPropagatedPosChargePFSC", pyVtxPropagatedPosChargePFSC, &b_pyVtxPropagatedPosChargePFSC);
   fChain->SetBranchAddress("pzVtxPropagatedPosChargePFSC", pzVtxPropagatedPosChargePFSC, &b_pzVtxPropagatedPosChargePFSC);
   fChain->SetBranchAddress("nTrack", &nTrack, &b_nTrack);
   fChain->SetBranchAddress("pxTrack", pxTrack, &b_pxTrack);
   fChain->SetBranchAddress("pyTrack", pyTrack, &b_pyTrack);
   fChain->SetBranchAddress("pzTrack", pzTrack, &b_pzTrack);
   fChain->SetBranchAddress("vtxIndexTrack", vtxIndexTrack, &b_vtxIndexTrack);
   fChain->SetBranchAddress("vtxWeightTrack", vtxWeightTrack, &b_vtxWeightTrack);
   fChain->SetBranchAddress("chargeTrack", chargeTrack, &b_chargeTrack);
   fChain->SetBranchAddress("ptErrorTrack", ptErrorTrack, &b_ptErrorTrack);
   fChain->SetBranchAddress("trackValidHitsTrack", trackValidHitsTrack, &b_trackValidHitsTrack);
   fChain->SetBranchAddress("trackLostHitsTrack", trackLostHitsTrack, &b_trackLostHitsTrack);
   fChain->SetBranchAddress("trackNormalizedChi2Track", trackNormalizedChi2Track, &b_trackNormalizedChi2Track);
   fChain->SetBranchAddress("qualityMaskTrack", qualityMaskTrack, &b_qualityMaskTrack);
   fChain->SetBranchAddress("trackDxyTrack", trackDxyTrack, &b_trackDxyTrack);
   fChain->SetBranchAddress("trackD0Track", trackD0Track, &b_trackD0Track);
   fChain->SetBranchAddress("trackDszTrack", trackDszTrack, &b_trackDszTrack);
   fChain->SetBranchAddress("trackDzTrack", trackDzTrack, &b_trackDzTrack);
   fChain->SetBranchAddress("trackDxyErrorTrack", trackDxyErrorTrack, &b_trackDxyErrorTrack);
   fChain->SetBranchAddress("trackD0ErrorTrack", trackD0ErrorTrack, &b_trackD0ErrorTrack);
   fChain->SetBranchAddress("trackDszErrorTrack", trackDszErrorTrack, &b_trackDszErrorTrack);
   fChain->SetBranchAddress("trackDzErrorTrack", trackDzErrorTrack, &b_trackDzErrorTrack);
   fChain->SetBranchAddress("trackDxyPVTrack", trackDxyPVTrack, &b_trackDxyPVTrack);
   fChain->SetBranchAddress("trackDszPVTrack", trackDszPVTrack, &b_trackDszPVTrack);
   fChain->SetBranchAddress("trackDzPVTrack", trackDzPVTrack, &b_trackDzPVTrack);
   fChain->SetBranchAddress("trackVxTrack", trackVxTrack, &b_trackVxTrack);
   fChain->SetBranchAddress("trackVyTrack", trackVyTrack, &b_trackVyTrack);
   fChain->SetBranchAddress("trackVzTrack", trackVzTrack, &b_trackVzTrack);
   fChain->SetBranchAddress("pxAtOuterTrack", pxAtOuterTrack, &b_pxAtOuterTrack);
   fChain->SetBranchAddress("pyAtOuterTrack", pyAtOuterTrack, &b_pyAtOuterTrack);
   fChain->SetBranchAddress("pzAtOuterTrack", pzAtOuterTrack, &b_pzAtOuterTrack);
   fChain->SetBranchAddress("xAtOuterTrack", xAtOuterTrack, &b_xAtOuterTrack);
   fChain->SetBranchAddress("yAtOuterTrack", yAtOuterTrack, &b_yAtOuterTrack);
   fChain->SetBranchAddress("zAtOuterTrack", zAtOuterTrack, &b_zAtOuterTrack);
   fChain->SetBranchAddress("pxAtInnerTrack", pxAtInnerTrack, &b_pxAtInnerTrack);
   fChain->SetBranchAddress("pyAtInnerTrack", pyAtInnerTrack, &b_pyAtInnerTrack);
   fChain->SetBranchAddress("pzAtInnerTrack", pzAtInnerTrack, &b_pzAtInnerTrack);
   fChain->SetBranchAddress("xAtInnerTrack", xAtInnerTrack, &b_xAtInnerTrack);
   fChain->SetBranchAddress("yAtInnerTrack", yAtInnerTrack, &b_yAtInnerTrack);
   fChain->SetBranchAddress("zAtInnerTrack", zAtInnerTrack, &b_zAtInnerTrack);
   fChain->SetBranchAddress("recHitsSizeTrack", recHitsSizeTrack, &b_recHitsSizeTrack);
   fChain->SetBranchAddress("isPixB1Track", isPixB1Track, &b_isPixB1Track);
   fChain->SetBranchAddress("isPixB2Track", isPixB2Track, &b_isPixB2Track);
   fChain->SetBranchAddress("isPixE1Track", isPixE1Track, &b_isPixE1Track);
   fChain->SetBranchAddress("isPixE2Track", isPixE2Track, &b_isPixE2Track);
   fChain->SetBranchAddress("numberOfValidPixelBarrelHitsTrack", numberOfValidPixelBarrelHitsTrack, &b_numberOfValidPixelBarrelHitsTrack);
   fChain->SetBranchAddress("numberOfValidPixelEndcapHitsTrack", numberOfValidPixelEndcapHitsTrack, &b_numberOfValidPixelEndcapHitsTrack);
   fChain->SetBranchAddress("numberOfValidStripTIBHitsTrack", numberOfValidStripTIBHitsTrack, &b_numberOfValidStripTIBHitsTrack);
   fChain->SetBranchAddress("numberOfValidStripTIDHitsTrack", numberOfValidStripTIDHitsTrack, &b_numberOfValidStripTIDHitsTrack);
   fChain->SetBranchAddress("numberOfValidStripTOBHitsTrack", numberOfValidStripTOBHitsTrack, &b_numberOfValidStripTOBHitsTrack);
   fChain->SetBranchAddress("numberOfValidStripTECHitsTrack", numberOfValidStripTECHitsTrack, &b_numberOfValidStripTECHitsTrack);
   fChain->SetBranchAddress("truncatedDeDxTrack", truncatedDeDxTrack, &b_truncatedDeDxTrack);
   fChain->SetBranchAddress("truncatedDeDxErrorTrack", truncatedDeDxErrorTrack, &b_truncatedDeDxErrorTrack);
   fChain->SetBranchAddress("truncatedDeDxNoMTrack", truncatedDeDxNoMTrack, &b_truncatedDeDxNoMTrack);
   fChain->SetBranchAddress("medianDeDxTrack", medianDeDxTrack, &b_medianDeDxTrack);
   fChain->SetBranchAddress("medianDeDxErrorTrack", medianDeDxErrorTrack, &b_medianDeDxErrorTrack);
   fChain->SetBranchAddress("medianDeDxNoMTrack", medianDeDxNoMTrack, &b_medianDeDxNoMTrack);
   fChain->SetBranchAddress("harmonic2DeDxTrack", harmonic2DeDxTrack, &b_harmonic2DeDxTrack);
   fChain->SetBranchAddress("harmonic2DeDxErrorTrack", harmonic2DeDxErrorTrack, &b_harmonic2DeDxErrorTrack);
   fChain->SetBranchAddress("harmonic2DeDxNoMTrack", harmonic2DeDxNoMTrack, &b_harmonic2DeDxNoMTrack);
   fChain->SetBranchAddress("nGsfTrack", &nGsfTrack, &b_nGsfTrack);
   fChain->SetBranchAddress("pxGsfTrack", pxGsfTrack, &b_pxGsfTrack);
   fChain->SetBranchAddress("pyGsfTrack", pyGsfTrack, &b_pyGsfTrack);
   fChain->SetBranchAddress("pzGsfTrack", pzGsfTrack, &b_pzGsfTrack);
   fChain->SetBranchAddress("chargeGsfTrack", chargeGsfTrack, &b_chargeGsfTrack);
   fChain->SetBranchAddress("ptErrorGsfTrack", ptErrorGsfTrack, &b_ptErrorGsfTrack);
   fChain->SetBranchAddress("trackValidHitsGsfTrack", trackValidHitsGsfTrack, &b_trackValidHitsGsfTrack);
   fChain->SetBranchAddress("trackLostHitsGsfTrack", trackLostHitsGsfTrack, &b_trackLostHitsGsfTrack);
   fChain->SetBranchAddress("trackNormalizedChi2GsfTrack", trackNormalizedChi2GsfTrack, &b_trackNormalizedChi2GsfTrack);
   fChain->SetBranchAddress("qualityMaskGsfTrack", qualityMaskGsfTrack, &b_qualityMaskGsfTrack);
   fChain->SetBranchAddress("trackDxyGsfTrack", trackDxyGsfTrack, &b_trackDxyGsfTrack);
   fChain->SetBranchAddress("trackD0GsfTrack", trackD0GsfTrack, &b_trackD0GsfTrack);
   fChain->SetBranchAddress("trackDszGsfTrack", trackDszGsfTrack, &b_trackDszGsfTrack);
   fChain->SetBranchAddress("trackDzGsfTrack", trackDzGsfTrack, &b_trackDzGsfTrack);
   fChain->SetBranchAddress("trackDxyErrorGsfTrack", trackDxyErrorGsfTrack, &b_trackDxyErrorGsfTrack);
   fChain->SetBranchAddress("trackD0ErrorGsfTrack", trackD0ErrorGsfTrack, &b_trackD0ErrorGsfTrack);
   fChain->SetBranchAddress("trackDszErrorGsfTrack", trackDszErrorGsfTrack, &b_trackDszErrorGsfTrack);
   fChain->SetBranchAddress("trackDzErrorGsfTrack", trackDzErrorGsfTrack, &b_trackDzErrorGsfTrack);
   fChain->SetBranchAddress("trackDxyPVGsfTrack", trackDxyPVGsfTrack, &b_trackDxyPVGsfTrack);
   fChain->SetBranchAddress("trackDszPVGsfTrack", trackDszPVGsfTrack, &b_trackDszPVGsfTrack);
   fChain->SetBranchAddress("trackDzPVGsfTrack", trackDzPVGsfTrack, &b_trackDzPVGsfTrack);
   fChain->SetBranchAddress("trackVxGsfTrack", trackVxGsfTrack, &b_trackVxGsfTrack);
   fChain->SetBranchAddress("trackVyGsfTrack", trackVyGsfTrack, &b_trackVyGsfTrack);
   fChain->SetBranchAddress("trackVzGsfTrack", trackVzGsfTrack, &b_trackVzGsfTrack);
   fChain->SetBranchAddress("pxAtOuterGsfTrack", pxAtOuterGsfTrack, &b_pxAtOuterGsfTrack);
   fChain->SetBranchAddress("pyAtOuterGsfTrack", pyAtOuterGsfTrack, &b_pyAtOuterGsfTrack);
   fChain->SetBranchAddress("pzAtOuterGsfTrack", pzAtOuterGsfTrack, &b_pzAtOuterGsfTrack);
   fChain->SetBranchAddress("xAtOuterGsfTrack", xAtOuterGsfTrack, &b_xAtOuterGsfTrack);
   fChain->SetBranchAddress("yAtOuterGsfTrack", yAtOuterGsfTrack, &b_yAtOuterGsfTrack);
   fChain->SetBranchAddress("zAtOuterGsfTrack", zAtOuterGsfTrack, &b_zAtOuterGsfTrack);
   fChain->SetBranchAddress("pxAtInnerGsfTrack", pxAtInnerGsfTrack, &b_pxAtInnerGsfTrack);
   fChain->SetBranchAddress("pyAtInnerGsfTrack", pyAtInnerGsfTrack, &b_pyAtInnerGsfTrack);
   fChain->SetBranchAddress("pzAtInnerGsfTrack", pzAtInnerGsfTrack, &b_pzAtInnerGsfTrack);
   fChain->SetBranchAddress("xAtInnerGsfTrack", xAtInnerGsfTrack, &b_xAtInnerGsfTrack);
   fChain->SetBranchAddress("yAtInnerGsfTrack", yAtInnerGsfTrack, &b_yAtInnerGsfTrack);
   fChain->SetBranchAddress("zAtInnerGsfTrack", zAtInnerGsfTrack, &b_zAtInnerGsfTrack);
   fChain->SetBranchAddress("recHitsSizeGsfTrack", recHitsSizeGsfTrack, &b_recHitsSizeGsfTrack);
   fChain->SetBranchAddress("isPixB1GsfTrack", isPixB1GsfTrack, &b_isPixB1GsfTrack);
   fChain->SetBranchAddress("isPixB2GsfTrack", isPixB2GsfTrack, &b_isPixB2GsfTrack);
   fChain->SetBranchAddress("isPixE1GsfTrack", isPixE1GsfTrack, &b_isPixE1GsfTrack);
   fChain->SetBranchAddress("isPixE2GsfTrack", isPixE2GsfTrack, &b_isPixE2GsfTrack);
   fChain->SetBranchAddress("numberOfValidPixelBarrelHitsGsfTrack", numberOfValidPixelBarrelHitsGsfTrack, &b_numberOfValidPixelBarrelHitsGsfTrack);
   fChain->SetBranchAddress("numberOfValidPixelEndcapHitsGsfTrack", numberOfValidPixelEndcapHitsGsfTrack, &b_numberOfValidPixelEndcapHitsGsfTrack);
   fChain->SetBranchAddress("numberOfValidStripTIBHitsGsfTrack", numberOfValidStripTIBHitsGsfTrack, &b_numberOfValidStripTIBHitsGsfTrack);
   fChain->SetBranchAddress("numberOfValidStripTIDHitsGsfTrack", numberOfValidStripTIDHitsGsfTrack, &b_numberOfValidStripTIDHitsGsfTrack);
   fChain->SetBranchAddress("numberOfValidStripTOBHitsGsfTrack", numberOfValidStripTOBHitsGsfTrack, &b_numberOfValidStripTOBHitsGsfTrack);
   fChain->SetBranchAddress("numberOfValidStripTECHitsGsfTrack", numberOfValidStripTECHitsGsfTrack, &b_numberOfValidStripTECHitsGsfTrack);
   fChain->SetBranchAddress("chargeModeGsfTrack", chargeModeGsfTrack, &b_chargeModeGsfTrack);
   fChain->SetBranchAddress("pxModeGsfTrack", pxModeGsfTrack, &b_pxModeGsfTrack);
   fChain->SetBranchAddress("pyModeGsfTrack", pyModeGsfTrack, &b_pyModeGsfTrack);
   fChain->SetBranchAddress("pzModeGsfTrack", pzModeGsfTrack, &b_pzModeGsfTrack);
   fChain->SetBranchAddress("recoFlagsGsfTrack", recoFlagsGsfTrack, &b_recoFlagsGsfTrack);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("PVxPV", PVxPV, &b_PVxPV);
   fChain->SetBranchAddress("PVyPV", PVyPV, &b_PVyPV);
   fChain->SetBranchAddress("PVzPV", PVzPV, &b_PVzPV);
   fChain->SetBranchAddress("PVErrxPV", PVErrxPV, &b_PVErrxPV);
   fChain->SetBranchAddress("PVErryPV", PVErryPV, &b_PVErryPV);
   fChain->SetBranchAddress("PVErrzPV", PVErrzPV, &b_PVErrzPV);
   fChain->SetBranchAddress("SumPtPV", SumPtPV, &b_SumPtPV);
   fChain->SetBranchAddress("ndofPV", ndofPV, &b_ndofPV);
   fChain->SetBranchAddress("chi2PV", chi2PV, &b_chi2PV);
   fChain->SetBranchAddress("genPtHat", &genPtHat, &b_genPtHat);
   fChain->SetBranchAddress("genProcessId", &genProcessId, &b_genProcessId);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("genAlphaQCD", &genAlphaQCD, &b_genAlphaQCD);
   fChain->SetBranchAddress("genAlphaQED", &genAlphaQED, &b_genAlphaQED);
   Notify();
}

Bool_t JPsiBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void JPsiBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t JPsiBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef JPsiBase_cxx
