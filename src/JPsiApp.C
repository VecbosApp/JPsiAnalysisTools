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

#if Application == 2
#include "JPsiAnalysisTools/src/JPsiBasicStudies.cc"
#endif

#if Application == 3
#include "JPsiAnalysisTools/src/ClustersBasicStudies.cc"
#endif

#if Application == 4
#include "JPsiAnalysisTools/src/JPsiBasicStudiesEle.cc"
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

  // get the tree with the conditions from the first file
  TTree *treeCond = new TTree();
  
  int nfiles=1;
  while( !(inputFile->eof()) ){
    inputFile->getline(Buffer,500);
    if (!strstr(Buffer,"#") && !(strspn(Buffer," ") == strlen(Buffer))) {
      sscanf(Buffer,"%s",MyRootFile);
      theChain->Add(MyRootFile);
      if ( nfiles==1 ) {
	TFile *firstfile = TFile::Open(MyRootFile);
	treeCond = (TTree*)firstfile->Get("Conditions");
      }
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

#if Application == 2

  JPsiBasicStudies jpsi(theChain);
  jpsi.SetDatasetName(outputFileName);
  jpsi.Loop();
  jpsi.displayEfficiencies(outputFileName);

#endif

#if Application == 3

  ClustersBasicStudies clusters(theChain);

  TriggerMask mask(treeCond);
  mask.requireTrigger("HLT_PhysicsDeclared");
  std::vector<int> requiredTriggers = mask.getBits();
  clusters.requireTrigger(requiredTriggers);

  clusters.Loop();

#endif

#if Application == 4

  JPsiBasicStudiesEle jpsi(theChain);
  jpsi.SetDatasetName(outputFileName);
  jpsi.Loop();
  jpsi.displayEfficiencies(outputFileName);

#endif

  return 0;

}
