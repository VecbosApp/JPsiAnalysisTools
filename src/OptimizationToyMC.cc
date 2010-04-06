#define OptimizationToyMC_cxx
#include "JPsiAnalysisTools/include/OptimizationToyMC.hh"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TRandom.h>
#include <iostream>
#include <math.h>

using namespace std;

void OptimizationToyMC::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L OptimizationToyMC.C
//      Root > OptimizationToyMC t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

  // N dimensions histo (isolation)
  theBins[0] = 50;
  theBins[1] = 50;
  // 
  theMin[0] = -2.0;
  theMin[1] = 0.0; 
  //
  theMax[0] = 15.0;
  theMax[1] = 15.0;

  // N dimensions histo (electron ID)
  theBinsID[0] = 50; // delta eta
  theBinsID[1] = 50; // sigmaIeIe
  theBinsID[2] = 50; // E/Pout
  //
  theMinID_EB[0] = -0.02;
  theMinID_EB[1] = 0.005;
  theMinID_EB[2] = 0.2;

  theMaxID_EB[0] = 0.02;
  theMaxID_EB[1] = 0.025;
  theMaxID_EB[2] = 2.0;
  //
  theMinID_EE[0] = -0.02;
  theMinID_EE[1] = 0.0;
  theMinID_EE[2] = 0.2;

  theMaxID_EE[0] = 0.02;
  theMaxID_EE[1] = 0.08;
  theMaxID_EE[2] = 2.0;

  // isolation
  THnSparseF *HH_NVarDim_EB = new THnSparseF("HH_NVarDim_EB", "HH_NVarDim_EB", 2, theBins, theMin, theMax);
  THnSparseF *HL_NVarDim_EB = new THnSparseF("HL_NVarDim_EB", "HL_NVarDim_EB", 2, theBins, theMin, theMax);

  THnSparseF *HH_NVarDim_EE = new THnSparseF("HH_NVarDim_EE", "HH_NVarDim_EE", 2, theBins, theMin, theMax);
  THnSparseF *HL_NVarDim_EE = new THnSparseF("HL_NVarDim_EE", "HL_NVarDim_EE", 2, theBins, theMin, theMax);
  
  // electron ID
  THnSparseF *HH_NVarDimID_EB = new THnSparseF("HH_NVarDimID_EB", "HH_NVarDimID_EB", 3, theBinsID, theMinID_EB, theMaxID_EB);
  THnSparseF *HL_NVarDimID_EB = new THnSparseF("HL_NVarDimID_EB", "HL_NVarDimID_EB", 3, theBinsID, theMinID_EB, theMaxID_EB);

  THnSparseF *HH_NVarDimID_EE = new THnSparseF("HH_NVarDimID_EE", "HH_NVarDimID_EE", 3, theBinsID, theMinID_EE, theMaxID_EE);
  THnSparseF *HL_NVarDimID_EE = new THnSparseF("HL_NVarDimID_EE", "HL_NVarDimID_EE", 3, theBinsID, theMinID_EE, theMaxID_EE);

  Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      double toFillH_EB[2], toFillL_EB[2], toFillH_EE[2], toFillL_EE[2];
      double toFillIDH_EB[3], toFillIDL_EB[3], toFillIDH_EE[3], toFillIDL_EE[3];

      if(fabs(eta[0])<1.479) {
        toFillH_EB[0] = sumPt04[0];
        toFillH_EB[1] = sumEtScFP04[0];
        if(recoFlag[0]!=1) { // ecal driven
          toFillIDH_EB[0] = deltaEtaAtCalo[0];
          toFillIDH_EB[1] = sigmaIEtaIEta[0];
          toFillIDH_EB[2] = eOverPout[0];
        } else { // tracker driven only
          toFillIDH_EB[0] = DeltaEtaAtCaloPFEle[0];
          toFillIDH_EB[1] = sigmaIEtaIEta[0];
          toFillIDH_EB[2] = EoPoutModePFEle[0];          
        }
      } else {
        toFillH_EE[0] = sumPt04[0];
        toFillH_EE[1] = sumEtScFP04[0];
        if(recoFlag[0]!=1) { // ecal driven
          toFillIDH_EE[0] = deltaEtaAtCalo[0];
          toFillIDH_EE[1] = sigmaIEtaIEta[0];
          toFillIDH_EE[2] = eOverPout[0];
        } else { // tracker driven only
          toFillIDH_EE[0] = DeltaEtaAtCaloPFEle[0];
          toFillIDH_EE[1] = sigmaIEtaIEta[0];
          toFillIDH_EE[2] = EoPoutModePFEle[0];          
        }
      }

      if(fabs(eta[1])<1.479) {
        toFillL_EB[0] = sumPt04[1];
        toFillL_EB[1] = sumEtScFP04[1];
        if(recoFlag[1]!=1) { // ecal driven
          toFillIDL_EB[0] = deltaEtaAtCalo[1];
          toFillIDL_EB[1] = sigmaIEtaIEta[1];
          toFillIDL_EB[2] = eOverPout[1];
        } else { // tracker driven only
          toFillIDL_EB[0] = DeltaEtaAtCaloPFEle[1];
          toFillIDL_EB[1] = sigmaIEtaIEta[1];
          toFillIDL_EB[2] = EoPoutModePFEle[1];          
        }
      } else {
        toFillL_EE[0] = sumPt04[1];
        toFillL_EE[1] = sumEtScFP04[1];        
        if(recoFlag[1]!=1) { // ecal driven
          toFillIDL_EE[0] = deltaEtaAtCalo[1];
          toFillIDL_EE[1] = sigmaIEtaIEta[1];
          toFillIDL_EE[2] = eOverPout[1];
        } else { // tracker driven only
          toFillIDL_EE[0] = DeltaEtaAtCaloPFEle[1];
          toFillIDL_EE[1] = sigmaIEtaIEta[1];
          toFillIDL_EE[2] = EoPoutModePFEle[1];          
        }
      }

      if(fabs(eta[0])<1.479) HH_NVarDim_EB->Fill(toFillH_EB);
      if(fabs(eta[1])<1.479) HL_NVarDim_EB->Fill(toFillL_EB);
      if(fabs(eta[0])>1.479) HH_NVarDim_EE->Fill(toFillH_EE);
      if(fabs(eta[1])>1.479) HL_NVarDim_EE->Fill(toFillL_EE);

      // optimization sensible only for ecal driven electrons
      if(recoFlag[0]!=1 && fabs(eta[0])<1.479) HH_NVarDimID_EB->Fill(toFillIDH_EB);
      if(recoFlag[1]!=1 && fabs(eta[1])<1.479) HL_NVarDimID_EB->Fill(toFillIDL_EB);
      if(recoFlag[0]!=1 && fabs(eta[0])>1.479) HH_NVarDimID_EE->Fill(toFillIDH_EE);
      if(recoFlag[1]!=1 && fabs(eta[1])>1.479) HL_NVarDimID_EE->Fill(toFillIDL_EE);

   }

  // generating a random distribution according to the sampled one
   TDatime *now = new TDatime();  
   for(int scan =0; scan<1000000; scan++){
     if(scan%1000==0) cout << "random: " << scan << endl;
     
     // randomly generated electron and positron 
     int today = now->GetDate();  
     int clock = now->GetTime();  
     int seed  = today+clock+scan;
     gRandom->SetSeed(seed);
     double theRndHigh_EB[2], theRndLow_EB[2], theRndHigh_EE[2], theRndLow_EE[2];
     double theRndHighID_EB[3], theRndLowID_EB[3], theRndHighID_EE[3], theRndLowID_EE[3];

     HH_NVarDim_EB->GetRandom(theRndHigh_EB);
     HL_NVarDim_EB->GetRandom(theRndLow_EB);
     HH_NVarDim_EE->GetRandom(theRndHigh_EE);
     HL_NVarDim_EE->GetRandom(theRndLow_EE);

     HH_NVarDimID_EB->GetRandom(theRndHighID_EB);
     HL_NVarDimID_EB->GetRandom(theRndLowID_EB);
     HH_NVarDimID_EE->GetRandom(theRndHighID_EE);
     HL_NVarDimID_EE->GetRandom(theRndLowID_EE);

     // filling the reduced tree with toy MC electrons
     this->fillAllOutTree(theRndHigh_EB[0],theRndHigh_EB[1],theRndLow_EB[0],theRndLow_EB[1],
                          theRndHigh_EE[0],theRndHigh_EE[1],theRndLow_EE[0],theRndLow_EE[1]);

     // filling the reduced ID tree with toy MC electrons
     this->fillAllOutTreeID(theRndHighID_EB[0],theRndHighID_EB[1],theRndHighID_EB[2],theRndLowID_EB[0],theRndLowID_EB[1],theRndLowID_EB[2],
                            theRndHighID_EE[0],theRndHighID_EE[1],theRndHighID_EE[2],theRndLowID_EE[0],theRndLowID_EE[1],theRndLowID_EE[2]);
     myTree->Fill();
     myTreeID->Fill();
   }

   myFile->cd();
   myTree->Write();
   myTreeID->Write();
   myFile->Close();

}

void OptimizationToyMC::createOutRootTree(const char* filename) {

  myFile = new TFile(filename,"RECREATE");
  myTree = new TTree("T1","isolation optimization tree");
  
  myTree->Branch("H_tk04_EB",  &my_H_tk04_EB, "H_tk04_EB/F");
  myTree->Branch("H_ecalGT04_EB",  &my_H_ecalGT04_EB, "H_ecalGT04_EB/F");
  myTree->Branch("L_tk04_EB",  &my_L_tk04_EB, "L_tk04_EB/F");
  myTree->Branch("L_ecalGT04_EB",  &my_L_ecalGT04_EB, "L_ecalGT04_EB/F");
  myTree->Branch("H_tk04_EE",  &my_H_tk04_EE, "H_tk04_EE/F");
  myTree->Branch("H_ecalGT04_EE",  &my_H_ecalGT04_EE, "H_ecalGT04_EE/F");
  myTree->Branch("L_tk04_EE",  &my_L_tk04_EE, "L_tk04_EE/F");
  myTree->Branch("L_ecalGT04_EE",  &my_L_ecalGT04_EE, "L_ecalGT04_EE/F");

  myTreeID = new TTree("T2","ele ID optimization tree"); 

  myTreeID->Branch("H_deta_EB", &my_H_deta_EB, "H_deta_EB/F");
  myTreeID->Branch("H_see_EB", &my_H_see_EB, "H_see_EB/F");
  myTreeID->Branch("H_eopout_EB", &my_H_eopout_EB, "H_eopout_EB/F");
  myTreeID->Branch("L_deta_EB", &my_L_deta_EB, "L_deta_EB/F");
  myTreeID->Branch("L_see_EB", &my_L_see_EB, "L_see_EB/F");
  myTreeID->Branch("L_eopout_EB", &my_L_eopout_EB, "L_eopout_EB/F");
  myTreeID->Branch("H_deta_EE", &my_H_deta_EE, "H_deta_EE/F");
  myTreeID->Branch("H_see_EE", &my_H_see_EE, "H_see_EE/F");
  myTreeID->Branch("H_eopout_EE", &my_H_eopout_EE, "H_eopout_EE/F");
  myTreeID->Branch("L_deta_EE", &my_L_deta_EE, "L_deta_EE/F");
  myTreeID->Branch("L_see_EE", &my_L_see_EE, "L_see_EE/F");
  myTreeID->Branch("L_eopout_EE", &my_L_eopout_EE, "L_eopout_EE/F");

}

void OptimizationToyMC::fillAllOutTree(float H_tk04_EB, float H_ecalGT04_EB, float L_tk04_EB, float L_ecalGT04_EB, 
                                       float H_tk04_EE, float H_ecalGT04_EE, float L_tk04_EE, float L_ecalGT04_EE) {

  my_H_tk04_EB = H_tk04_EB;
  my_H_ecalGT04_EB = H_ecalGT04_EB;
  my_L_tk04_EB = L_tk04_EB;
  my_L_ecalGT04_EB = L_ecalGT04_EB;
  my_H_tk04_EE = H_tk04_EE;
  my_H_ecalGT04_EE = H_ecalGT04_EE;
  my_L_tk04_EE = L_tk04_EE;
  my_L_ecalGT04_EE = L_ecalGT04_EE;
  
}

void OptimizationToyMC::fillAllOutTreeID(float H_deta_EB, float H_see_EB, float H_eopout_EB, float L_deta_EB, float L_see_EB, float L_eopout_EB,
                                         float H_deta_EE, float H_see_EE, float H_eopout_EE, float L_deta_EE, float L_see_EE, float L_eopout_EE) {
  my_H_deta_EB = H_deta_EB;
  my_H_see_EB = H_see_EB;
  my_H_eopout_EB = H_eopout_EB;
  my_L_deta_EB = L_deta_EB;
  my_L_see_EB = L_see_EB;
  my_L_eopout_EB = L_eopout_EB;
  my_H_deta_EE = H_deta_EE;
  my_H_see_EE = H_see_EE;
  my_H_eopout_EE = H_eopout_EE;
  my_L_deta_EE = L_deta_EE;
  my_L_see_EE = L_see_EE;
  my_L_eopout_EE = L_eopout_EE;

}
