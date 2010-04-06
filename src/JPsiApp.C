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
#include "JPsiAnalysisTools/include/Application.hh"
#include "CommonTools/include/TriggerMask.hh"

#if Application == 1
#include "JPsiAnalysisTools/src/JPsiSelection.cc"
#endif

int main(int argc, char* argv[]) {

  char inputFileName[150];
  char outputFileName[150];
  if ( argc < 3 ){
    std::cout << "missing argument: insert inputFile with list of root files and oputputfile name" << std::endl; 
    std::cout << "JPsiApp inputFile outputFile" << std::endl;
    return 1;
  }
  strcpy(inputFileName, argv[1]);
  strcpy(outputFileName,argv[2]);
  
  // -------------------------
  // loading file:
  TChain *theChain = new TChain("ntp1");
  char Buffer[500];
  char MyRootFile[2000];  
  std::cout << "input: " << inputFileName << std::endl;
  ifstream *inputFile = new ifstream(inputFileName);

  int nfiles=1;
  while( !(inputFile->eof()) ){
    inputFile->getline(Buffer,500);
    if (!strstr(Buffer,"#") && !(strspn(Buffer," ") == strlen(Buffer))) {
      sscanf(Buffer,"%s",MyRootFile);
      theChain->Add(MyRootFile);
      std::cout << "chaining " << MyRootFile << std::endl;
      nfiles++;
    }
  }
  inputFile->close();
  delete inputFile;

#if Application == 1

  JPsiSelection jpsi(theChain);
  jpsi.SetDatasetName(outputFileName);
  jpsi.Loop();
  jpsi.displayEfficiencies(outputFileName);

#endif

  return 0;

}
