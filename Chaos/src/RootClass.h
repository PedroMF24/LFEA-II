#ifndef __ROOTCLASS__
#define __ROOTCLASS__

#include "TCanvas.h" // include class TCanvas from RootClass library
#include "TGraph.h" // graf
#include "TMultiGraph.h"
#include "TH1D.h"
#include "TH2F.h"           // histogram 2D
#include "TF1.h"
#include "TF2.h"

#include "TFitResultPtr.h"
#include "TFitResult.h"

#include "TMath.h"
#include "TRandom3.h"
#include "TAxis.h"
#include "THStack.h"

#include "TRootCanvas.h"
#include "TApplication.h"

#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

class RootClass {
public:
    // constructor
    RootClass(int entries);

    // void GetGraph(string name, int n1, int n2);
// fazer graphs 1d e 2d
// fazer hists, 1d e 2d
// fazer multigraph a partir de gráficos feitos
// funções
// fittar funções feitas

private:
    vector<vector<double>> Data;
// vector<TGraph*> gr;
// TMultiGraph *mg;
// map<int, TH1D*> Hists;
// map<int, TH2F*> Hists2D;
// map<int, TGraph*> Graphs;
// map<int, TMultiGraph*> MultiGraphs;
// map<int, TF1*> Functions;
//vector<vector<TGraph*>> Graphs;
};

#endif