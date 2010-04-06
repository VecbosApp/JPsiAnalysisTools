ROOTCFLAGS    = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --libs)
ROOTGLIBS     = $(shell root-config --glibs)

CXX           = g++
CXXFLAGS      = -g -fPIC -Wno-deprecated -O -ansi -D_GNU_SOURCE -g -O2
LD            = g++
LDFLAGS       = -g
SOFLAGS       = -shared


ARCH         := $(shell root-config --arch)
PLATFORM     := $(shell root-config --platform)


CXXFLAGS      += $(ROOTCFLAGS)
LIBS           = $(ROOTLIBS) 

NGLIBS         = $(ROOTGLIBS) 
NGLIBS        += -lMinuit -lMinuit2
GLIBS          = $(filter-out -lNew, $(NGLIBS))

INCLUDEDIR       = ./
INCLUDEDIRCOMMON = ../
CXX	         += -I$(INCLUDEDIR) -I$(INCLUDEDIRCOMMON) -I.
OUTLIB	         = $(INCLUDEDIR)/lib/
OUTLIBCOMMON     = $(INCLUDEDIRCOMMON)/CommonTools/lib/

.SUFFIXES: .cc,.C,.hh,.h
.PREFIXES: ./lib/


$(OUTLIB)JPsiBase.o: $(INCLUDEDIR)/src/JPsiBase.C \
	$(INCLUDEDIR)/src/JPsiSelection.cc \
	$(INCLUDEDIR)/src/RedEleIDTree.cc \
	$(INCLUDEDIR)/src/RedJPsiTree.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)JPsiBase.o $<
$(OUTLIBCOMMON)Conditions.o: $(INCLUDEDIRCOMMON)/CommonTools/src/Conditions.C
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIRCOMMON) -o $(OUTLIBCOMMON)Conditions.o $<
$(OUTLIBCOMMON)Utils.o: $(INCLUDEDIRCOMMON)/CommonTools/src/Utils.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIBCOMMON)Utils.o $<
$(OUTLIBCOMMON)Counters.o: $(INCLUDEDIRCOMMON)/CommonTools/src/Counters.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIRCOMMON) -o $(OUTLIBCOMMON)Counters.o $<
$(OUTLIBCOMMON)Selection.o: $(INCLUDEDIRCOMMON)/CommonTools/src/Selection.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIRCOMMON) -o $(OUTLIBCOMMON)Selection.o $<
$(OUTLIBCOMMON)EfficiencyEvaluator.o: $(INCLUDEDIRCOMMON)/CommonTools/src/EfficiencyEvaluator.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIRCOMMON) -o $(OUTLIBCOMMON)EfficiencyEvaluator.o $<
$(OUTLIBCOMMON)Monitor.o: $(INCLUDEDIRCOMMON)/CommonTools/src/Monitor.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIRCOMMON) -o $(OUTLIBCOMMON)Monitor.o $<
$(OUTLIBCOMMON)TriggerMask.o: $(INCLUDEDIRCOMMON)/CommonTools/src/TriggerMask.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIRCOMMON) -o $(OUTLIBCOMMON)TriggerMask.o $<
$(OUTLIB)CutBasedEleIDSelector.o: $(INCLUDEDIRCOMMON)/EgammaAnalysisTools/src/CutBasedEleIDSelector.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIRCOMMON) -o $(OUTLIB)CutBasedEleIDSelector.o $<
$(OUTLIB)JPsiSelection.o: $(INCLUDEDIR)/src/JPsiSelection.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)JPsiSelection.o $<
$(OUTLIB)RedEleIDTree.o: $(INCLUDEDIR)/src/RedEleIDTree.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)RedEleIDTree.o $<
$(OUTLIB)RedJPsiTree.o: $(INCLUDEDIR)/src/RedJPsiTree.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)RedJPsiTree.o $<
$(OUTLIB)OptimizationToyMC.o: $(INCLUDEDIR)/src/OptimizationToyMC.cc
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDEDIR) -o $(OUTLIB)OptimizationToyMC.o $<

# ==================== JPsiApp =============================================
JPsiApp:  $(INCLUDEDIR)/src/JPsiApp.C \
	$(OUTLIB)JPsiBase.o \
	$(OUTLIB)RedEleIDTree.o \
	$(OUTLIB)RedJPsiTree.o \
	$(OUTLIBCOMMON)Conditions.o \
	$(OUTLIBCOMMON)Selection.o \
	$(OUTLIBCOMMON)EfficiencyEvaluator.o \
	$(OUTLIBCOMMON)Counters.o \
	$(OUTLIBCOMMON)Monitor.o \
	$(OUTLIBCOMMON)TriggerMask.o \
	$(OUTLIBCOMMON)Utils.o \
	$(OUTLIB)CutBasedEleIDSelector.o
	$(CXX) $(CXXFLAGS) -ldl -o JPsiApp $(OUTLIB)/*.o $(OUTLIBCOMMON)/*o $(GLIBS) $(LDFLAGS) $ $<
JPsiApp.clean:
	rm -f JPsiApp

OptimizationToyMC: $(INCLUDEDIR)/src/Optimization.cc \
	$(OUTLIB)OptimizationToyMC.o
	$(CXX) $(CXXFLAGS) -ldl -o OptimizationToyMC $(OUTLIB)/OptimizationToyMC.o $(GLIBS) $(LDFLAGS) $ $<

isolationTableToy:  $(INCLUDEDIR)/src/isolationTableToy.cpp
	$(CXX) $(CXXFLAGS) -o isolationTableToy $(GLIBS) $ $<

eleIDTableToy:  $(INCLUDEDIR)/src/eleIDTableToy.cpp
	$(CXX) $(CXXFLAGS) -o eleIDTableToy $(GLIBS) $ $<

clean:
	rm -f $(OUTLIB)*.o $(OUTLIBCOMMON)*.o
	rm -f JPsiApp OptimizationToyMC isolationTableToy eleIDTableToy

all:  JPsiApp
