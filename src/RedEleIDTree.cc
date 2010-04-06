#include "../include/RedEleIDTree.h"

// C++
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

// Root
#include "TFile.h"
#include "TTree.h"

RedEleIDTree::RedEleIDTree(const char * filename) {

  myFile = new TFile(filename,"RECREATE");
  myTree = new TTree("T1","eleID tree");
  
  myTree->Branch("class",          myClass,          "class[2]/I");  
  myTree->Branch("recoFlag",       myRecoFlag,       "recoFlag[2]/I");  
  myTree->Branch("pt",             myPt,             "pt[2]/F");  
  myTree->Branch("eta",            myEta,            "eta[2]/F");  
  myTree->Branch("fbrem",          myFBrem,          "fbrem[2]/F");
  myTree->Branch("hOverE",         myHOverE,         "hOverE[2]/F");  
  myTree->Branch("eOverP",         myEOverP,         "eOverP[2]/F");  
  myTree->Branch("eOverPout",      myEOverPout,      "eOverPout[2]/F");  
  myTree->Branch("deltaEtaAtCalo",  myDeltaEtaAtCalo,  "deltaEtaAtCalo[2]/F");  
  myTree->Branch("deltaPhiAtCalo",  myDeltaPhiAtCalo,  "deltaPhiAtCalo[2]/F");  
  myTree->Branch("sigmaIEtaIEta",  mySigmaIEtaIEta,  "sigmaIEtaIEta[2]/F");  
}


RedEleIDTree::~RedEleIDTree() {

  delete myFile;
}

void RedEleIDTree::addIsolation() {
  myTree->Branch("sumPt04",       mySumPt04,      "sumPt04[2]/F");
  myTree->Branch("sumEtJurFP04",  mySumEtJurFP04, "sumEtJurFP04[2]/F");
  myTree->Branch("sumEtScFP04",   mySumEtScFP04,  "sumEtScFP04[2]/F");  
}

void RedEleIDTree::addPFEleID() {
  myTree->Branch("EoPModePFEle",        myEoPModePFEle,        "EoPModePFEle[2]/F");
  myTree->Branch("EoPoutModePFEle",     myEoPoutModePFEle,     "EoPoutModePFEle[2]/F");
  myTree->Branch("EBremoDeltaPPFEle",   myEBremoDeltaPPFEle,   "EBremoDeltaPPFEle[2]/F");
  myTree->Branch("DeltaEtaAtCaloPFEle", myDeltaEtaAtCaloPFEle, "DeltaEtaAtCaloPFEle[2]/F");
  myTree->Branch("DeltaPhiAtCaloPFEle", myDeltaPhiAtCaloPFEle, "myDeltaPhiAtCaloPFEle[2]/F");
  myTree->Branch("HOverHEPFEle",        myHOverHEPFEle,        "HOverHEPFEle[2]/F");
  myTree->Branch("HOverPPFEle",         myHOverPPFEle,         "HOverPPFEle[2]/F");
  myTree->Branch("MvaPFEle",            myMvaPFEle,            "MvaPFEle[2]/F");
}

void RedEleIDTree::store() {
  
  myTree->Fill();
}


void RedEleIDTree::save() {

  myFile->cd();
  myTree->Write();
  myFile->Close();
}


void RedEleIDTree::fillAll(int cl[2], int recoflag[2], float pt[2], float eta[2], float hoe[2], float eop[2], float eopo[2], float deta[2], float dphi[2], float see[2], float fbrem[2]) {

  for(int i=0; i<2; i++) {
    myClass[i]         = cl[i];
    myRecoFlag[i]      = recoflag[i];
    myPt[i]            = pt[i];
    myEta[i]           = eta[i];
    myFBrem[i]         = fbrem[i];
    myHOverE[i]        = hoe[i];
    myEOverP[i]        = eop[i];
    myEOverPout[i]     = eopo[i];
    myDeltaEtaAtCalo[i] = deta[i];
    myDeltaPhiAtCalo[i] = dphi[i];
    mySigmaIEtaIEta[i] = see[i];
  }

}

void RedEleIDTree::fillIsolation(float sumPt04[2], float sumEtJurFP04[2], float sumEtScFP04[2]) {

  for(int i=0; i<2; i++) {  
    mySumPt04[i] = sumPt04[i];
    mySumEtJurFP04[i] = sumEtJurFP04[i];
    mySumEtScFP04[i] = sumEtScFP04[i];
  }

}

void RedEleIDTree::fillPFEleID(float EoPModePFEle[2], float EoPoutModePFEle[2], float EBremoDeltaPPFEle[2], float deltaEtaAtCaloPFEle[2], float deltaPhiAtCaloPFEle[2], float hOverHEPFEle[2], float hOverPPFEle[2], float mva[2]) {

  for(int i=0; i<2; i++) {
    myEoPModePFEle[i] = EoPModePFEle[i];
    myEoPoutModePFEle[i] = EoPoutModePFEle[i];
    myEBremoDeltaPPFEle[i] = EBremoDeltaPPFEle[i];
    myDeltaEtaAtCaloPFEle[i] = deltaEtaAtCaloPFEle[i];
    myDeltaPhiAtCaloPFEle[i] = deltaPhiAtCaloPFEle[i];
    myHOverHEPFEle[i] = hOverHEPFEle[i];
    myHOverPPFEle[i] = hOverPPFEle[i];
    myMvaPFEle[i] = mva[2];
  }

}
