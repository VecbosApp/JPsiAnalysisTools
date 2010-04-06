class TFile;
class TTree;

class G3EventProxy;

class RedJPsiTree {
public:
   RedJPsiTree(const char * filename = "eleID.root");
  ~RedJPsiTree();

  void fillAll(float im, float tim, float dr, float pt1, float pt2, float eta1, float eta2, int rf1, int rf2);
  void fillRunInfo(int run, int lumi, int event);
  void store();
  void save();

private:
  int myRun, myLumi, myEvent;
  float myInvMass;
  float myTrackerInvMass;
  float myDeltaR;
  float mypt1, mypt2, myeta1, myeta2;
  int myrf1, myrf2;

  TFile* myFile;
  TTree* myTree;
 
};

