class TFile;
class TTree;

class G3EventProxy;

class RedEleIDTree {
public:
   RedEleIDTree(const char * filename = "eleID.root");
  ~RedEleIDTree();

  void fillAll(int cl[2], int recoflag[2], float pt[2], float eta[2], float hoe[2], float eop[2], float eopo[2], float deta[2], float dphi[2], float see[2], float fbrem[2]);

  void addIsolation();
  void fillIsolation(float sumPt04[2], float sumEtJurFP04[2], float sumEtScFP04[2]);

  void addPFEleID();
  void fillPFEleID(float EoPModePFEle[2], float EoPoutModePFEle[2], float EBremoDeltaPPFEle[2], float deltaEtaAtCaloPFEle[2], float deltaPhiAtCaloPFEle[2], float hOverHEPFEle[2], float hOverPPFEle[2], float mva[2]);
  
  void store();
  void save();

private:

  // kinematics
  int myRecoFlag[2];
  float myPt[2];
  float myEta[2];
  float myFBrem[2];

  // electron ID variables
  int myClass[2];
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
  float myMvaPFEle[2];
  
  // electron isolation variables
  float mySumPt04[2];
  float mySumEtJurFP04[2], mySumEtScFP04[2];

  TFile* myFile;
  TTree* myTree;
 
};

