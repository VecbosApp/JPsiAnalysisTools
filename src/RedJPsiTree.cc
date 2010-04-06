#include "../include/RedJPsiTree.h"

// C++
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

// Root
#include "TFile.h"
#include "TTree.h"

RedJPsiTree::RedJPsiTree(const char * filename) {

  myFile = new TFile(filename,"RECREATE");
  myTree = new TTree("T1","kine tree");

  myTree->Branch("run", &myRun, "run/I");
  myTree->Branch("lumi", &myLumi, "lumi/I");
  myTree->Branch("event", &myEvent, "event/I");
  myTree->Branch("invMass",        &myInvMass,        "invMass/F");  
  myTree->Branch("trackerInvMass", &myTrackerInvMass, "trackerInvMass/F");  
  myTree->Branch("gsfTrackInvMass",  &myGsfTrackInvMass,  "gsfTrackInvMass/F");
  myTree->Branch("deltaR",         &myDeltaR,         "deltaR/F");  
  myTree->Branch("pt1", &mypt1, "pt1/F");
  myTree->Branch("pt2", &mypt2, "pt2/F");
  myTree->Branch("eta1", &myeta1, "eta1/F");
  myTree->Branch("eta2", &myeta2, "eta2/F");
  myTree->Branch("rf1", &myrf1, "rf1/I");
  myTree->Branch("rf2", &myrf2, "rf2/I");
}


RedJPsiTree::~RedJPsiTree() {

  delete myFile;
}

void RedJPsiTree::store() {
  
  myTree->Fill();
}


void RedJPsiTree::save() {

  myFile->cd();
  myTree->Write();
  myFile->Close();
}


void RedJPsiTree::fillAll(float im, float tim, float gsftim, float dr, float pt1, float pt2, float eta1, float eta2, int rf1, int rf2) {

  myInvMass        = im;
  myTrackerInvMass = tim;
  myGsfTrackInvMass  = gsftim;
  myDeltaR         = dr;
  mypt1 = pt1;
  mypt2 = pt2;
  myeta1 = eta1;
  myeta2 = eta2;
  myrf1 = rf1;
  myrf2 = rf2;

}

void RedJPsiTree::fillRunInfo(int run, int lumi, int event) {

  myRun = run;
  myLumi = lumi;
  myEvent = event;

}
