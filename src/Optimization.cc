// C++ includes
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

// ROOT includes
#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include "JPsiAnalysisTools/include/OptimizationToyMC.hh"

int main(int argc, char* argv[]) {

  char signalFileName[150];
  char backgroundFileName[150];
  if ( argc < 3 ) {
    std::cout << "missing argument: insert inputFile with list of root files and oputputfile name" << std::endl; 
    std::cout << "JPsiApp signalFile bkgFile" << std::endl;
    return 1;
  }
  strcpy(signalFileName, argv[1]);
  strcpy(backgroundFileName,argv[2]);
  
  // -------------------------
  // loading file:
  TChain *theChainSig = new TChain("T1");
  TChain *theChainBkg = new TChain("T1");
  char Buffer[500];
  char MyRootFile[2000];  
  std::cout << "signal: " << signalFileName << std::endl;
  ifstream *signalFile = new ifstream(signalFileName);
  ifstream *backgroundFile = new ifstream(backgroundFileName);

  int nfiles=1;
  while( !(signalFile->eof()) ){
    signalFile->getline(Buffer,500);
    if (!strstr(Buffer,"#") && !(strspn(Buffer," ") == strlen(Buffer))) {
      sscanf(Buffer,"%s",MyRootFile);
      theChainSig->Add(MyRootFile);
      std::cout << "chaining Sig " << MyRootFile << std::endl;
      nfiles++;
    }
  }
  signalFile->close();
  delete signalFile;

  while( !(backgroundFile->eof()) ){
    backgroundFile->getline(Buffer,500);
    if (!strstr(Buffer,"#") && !(strspn(Buffer," ") == strlen(Buffer))) {
      sscanf(Buffer,"%s",MyRootFile);
      theChainBkg->Add(MyRootFile);
      std::cout << "chaining Bkg " << MyRootFile << std::endl;
      nfiles++;
    }
  }
  backgroundFile->close();
  delete backgroundFile;

  std::cout << "Now doing Toy MC for signal isolation" << std::endl;
  OptimizationToyMC toyMcSignal(theChainSig);
  toyMcSignal.createOutRootTree("signal_isolation_toyMC.root");
  toyMcSignal.Loop();

  std::cout << "Now doing Toy MC for background isolation" << std::endl;
  OptimizationToyMC toyMcBkg(theChainBkg);
  toyMcBkg.createOutRootTree("background_isolation_toyMC.root");
  toyMcBkg.Loop();
  
  return 0;

}
