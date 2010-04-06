//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jan 28 18:21:05 2010 by ROOT version 5.22/00d
// from TTree T1/eleID tree
// found on file: signal-eleId.root
//////////////////////////////////////////////////////////

#ifndef OptimizationToyMC_h
#define OptimizationToyMC_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <THnSparse.h>

class OptimizationToyMC {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           classification[2];
   Int_t           recoFlag[2];
   Float_t         pt[2];
   Float_t         eta[2];
   Float_t         fbrem[2];
   Float_t         hOverE[2];
   Float_t         eOverP[2];
   Float_t         eOverPout[2];
   Float_t         deltaEtaAtCalo[2];
   Float_t         deltaPhiAtCalo[2];
   Float_t         sigmaIEtaIEta[2];
   Float_t         sumPt04[2];
   Float_t         sumEtJurFP04[2];
   Float_t         sumEtScFP04[2];
   Float_t         EoPModePFEle[2];
   Float_t         EoPoutModePFEle[2];
   Float_t         EBremoDeltaPPFEle[2];
   Float_t         DeltaEtaAtCaloPFEle[2];
   Float_t         DeltaPhiAtCaloPFEle[2];
   Float_t         HOverHEPFEle[2];
   Float_t         HOverPPFEle[2];
   Float_t         MvaPFEle[2];

   // List of branches
   TBranch        *b_classification;   //!
   TBranch        *b_recoFlag;   //!
   TBranch        *b_pt;   //!
   TBranch        *b_eta;   //!
   TBranch        *b_fbrem;   //!
   TBranch        *b_hOverE;   //!
   TBranch        *b_eOverP;   //!
   TBranch        *b_eOverPout;   //!
   TBranch        *b_deltaEtaAtCalo;   //!
   TBranch        *b_deltaPhiAtCalo;   //!
   TBranch        *b_sigmaIEtaIEta;   //!
   TBranch        *b_sumPt04;   //!
   TBranch        *b_sumEtJurFP04;   //!
   TBranch        *b_sumEtScFP04;   //!
   TBranch        *b_EoPModePFEle;   //!
   TBranch        *b_EoPoutModePFEle;   //!
   TBranch        *b_EBremoDeltaPPFEle;   //!
   TBranch        *b_DeltaEtaAtCaloPFEle;   //!
   TBranch        *b_myDeltaPhiAtCaloPFEle;   //!
   TBranch        *b_HOverHEPFEle;   //!
   TBranch        *b_HOverPPFEle;   //!
   TBranch        *b_MvaPFEle;   //!

   OptimizationToyMC(TTree *tree=0);
   virtual ~OptimizationToyMC();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

  // Optimization histograms
  int   theBins[2], theBinsID[3];
  double theMin[2], theMax[2];
  double theMinID_EB[3], theMaxID_EB[3], theMinID_EE[3], theMaxID_EE[3];

  THnSparseF *HH_NVarDim_EB, *HL_NVarDim_EB, *HH_NVarDim_EE, *HL_NVarDim_EE;

  // variables of the out tree
  TFile *myFile;
  TTree *myTree, *myTreeID;
  
  float my_H_tk04_EB, my_H_ecalGT04_EB, my_L_tk04_EB, my_L_ecalGT04_EB;
  float my_H_tk04_EE, my_H_ecalGT04_EE, my_L_tk04_EE, my_L_ecalGT04_EE;

  float my_H_deta_EB, my_H_see_EB, my_H_eopout_EB, my_L_deta_EB, my_L_see_EB, my_L_eopout_EB;
  float my_H_deta_EE, my_H_see_EE, my_H_eopout_EE, my_L_deta_EE, my_L_see_EE, my_L_eopout_EE;

  void createOutRootTree(const char* filename);
  void fillAllOutTree(float H_tk04_EB, float H_ecalGT04_EB, float L_tk04_EB, float L_ecalGT04_EB,
                      float H_tk04_EE, float H_ecalGT04_EE, float L_tk04_EE, float L_ecalGT04_EE);      
  void fillAllOutTreeID(float H_deta_EB, float H_see_EB, float H_eopout_EB, float L_deta_EB, float L_see_EB, float L_eopout_EB,
                        float H_deta_EE, float H_see_EE, float H_eopout_EE, float L_deta_EE, float L_see_EE, float L_eopout_EE);

};

#endif

#ifdef OptimizationToyMC_cxx
OptimizationToyMC::OptimizationToyMC(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("signal-eleId.root");
      if (!f) {
         f = new TFile("signal-eleId.root");
      }
      tree = (TTree*)gDirectory->Get("T1");

   }
   Init(tree);
}

OptimizationToyMC::~OptimizationToyMC()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t OptimizationToyMC::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t OptimizationToyMC::LoadTree(Long64_t entry)
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

void OptimizationToyMC::Init(TTree *tree)
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

   fChain->SetBranchAddress("class", classification, &b_classification);
   fChain->SetBranchAddress("recoFlag", recoFlag, &b_recoFlag);
   fChain->SetBranchAddress("pt", pt, &b_pt);
   fChain->SetBranchAddress("eta", eta, &b_eta);
   fChain->SetBranchAddress("fbrem", fbrem, &b_fbrem);
   fChain->SetBranchAddress("hOverE", hOverE, &b_hOverE);
   fChain->SetBranchAddress("eOverP", eOverP, &b_eOverP);
   fChain->SetBranchAddress("eOverPout", eOverPout, &b_eOverPout);
   fChain->SetBranchAddress("deltaEtaAtCalo", deltaEtaAtCalo, &b_deltaEtaAtCalo);
   fChain->SetBranchAddress("deltaPhiAtCalo", deltaPhiAtCalo, &b_deltaPhiAtCalo);
   fChain->SetBranchAddress("sigmaIEtaIEta", sigmaIEtaIEta, &b_sigmaIEtaIEta);
   fChain->SetBranchAddress("sumPt04", sumPt04, &b_sumPt04);
   fChain->SetBranchAddress("sumEtJurFP04", sumEtJurFP04, &b_sumEtJurFP04);
   fChain->SetBranchAddress("sumEtScFP04", sumEtScFP04, &b_sumEtScFP04);
   fChain->SetBranchAddress("EoPModePFEle", EoPModePFEle, &b_EoPModePFEle);
   fChain->SetBranchAddress("EoPoutModePFEle", EoPoutModePFEle, &b_EoPoutModePFEle);
   fChain->SetBranchAddress("EBremoDeltaPPFEle", EBremoDeltaPPFEle, &b_EBremoDeltaPPFEle);
   fChain->SetBranchAddress("DeltaEtaAtCaloPFEle", DeltaEtaAtCaloPFEle, &b_DeltaEtaAtCaloPFEle);
   fChain->SetBranchAddress("DeltaPhiAtCaloPFEle", DeltaPhiAtCaloPFEle, &b_myDeltaPhiAtCaloPFEle);
   fChain->SetBranchAddress("HOverHEPFEle", HOverHEPFEle, &b_HOverHEPFEle);
   fChain->SetBranchAddress("HOverPPFEle", HOverPPFEle, &b_HOverPPFEle);
   fChain->SetBranchAddress("MvaPFEle", MvaPFEle, &b_MvaPFEle);
   Notify();
}

Bool_t OptimizationToyMC::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void OptimizationToyMC::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t OptimizationToyMC::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

#endif // #ifdef OptimizationToyMC_cxx
