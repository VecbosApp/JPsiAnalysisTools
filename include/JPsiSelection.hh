#ifndef JPsiSelection_h
#define JPsiSelection_h

#include <vector>
#include "CommonTools/include/Selection.hh"
#include "CommonTools/include/Counters.hh"
#include "CommonTools/include/Monitor.hh"
#include "EgammaAnalysisTools/include/CutBasedEleIDSelector.hh"
#include "JPsiAnalysisTools/include/JPsiBase.h"
#include "JPsiAnalysisTools/include/RedEleIDTree.h"
#include "JPsiAnalysisTools/include/RedJPsiTree.h"
#include <TVector3.h>
#include <TLorentzVector.h>

class JPsiSelection : public JPsiBase{
public:
  
  //! constructor
  JPsiSelection(TTree *tree=0);
  //! destructor
  virtual ~JPsiSelection();
  //! loop over events
  void Loop();
  //! set the name for dataset in output
  void SetDatasetName(std::string filename) {_datasetName=filename;};
  //! display the efficiency table
  void displayEfficiencies(std::string filename);
  
private:

  //! for MC
  bool findMcTree();
  //! electrons in eta and pt acceptance
  void getElectronsInEta();
  void getElectronsInPt();
  //! set and reset the kinematic quantities at the beginning of event
  void setKinematics();  
  void resetKinematics();
  //! get the two hardest electrons with opposite charge
  std::pair<int,int> getBestElectronPair();
  //! returns the output of the custom cut electron ID
  bool isEleID(int eleIndex, bool isTheHard);
  //! returns the index of PFElectron, if found. Otherwise returns -1
  int getPFElectron(int gsfElectron);
  
  //! fill the electron ID reduced tree
  void fillEleIdTree(int hard, int slow);

  //! contains the preselection cuts
  Selection* _selection;
  //! counters for the efficiencies display, based on electron candidates
  Counters* counter;

  //! generated electrons  
  int _theGenEle, _theGenPos;
  
  //! reco ele in acceptance 
  std::vector<int> eleInEta;
  std::vector<int> eleInPt;

  //! vectors to store indices of best candidates
  std::vector<int> *_bestElectrons;
  
  //! kinematics of the event  
  TLorentzVector *m_p4ElectronPlus;
  TLorentzVector *m_p4ElectronMinus;
  int theElectron,  thePositron;
  float invariantMass, invariantMassTracker;
  float deltaR;

  //! to evaluate eleID
  CutBasedEleIDSelector EgammaCutBasedID_Hard;
  CutBasedEleIDSelector EgammaCutBasedID_Slow;

  //! name of rootfile with dataset
  std::string _datasetName;

  //! reduced trees 
  RedEleIDTree *myEleIdTree;
  RedJPsiTree  *myKineTree;

  //! if the 2nd ele falls in deltaR from first, remove its pT
  float getSumPtSecondFP04(int first, int second);
  
};
#endif
