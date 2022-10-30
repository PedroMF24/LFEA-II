#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "TF1.h"
#include "TH1D.h"
#include "TGraph.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TRootCanvas.h"
#include "TApplication.h"
#include "TGraphErrors.h"

using namespace std;

int main(){

    TApplication app("app", NULL, NULL);
    TCanvas *c = new TCanvas();

    c->Update();
    c->Draw();
    c->SaveAs("ola.png");


    TRootCanvas *rc = (TRootCanvas *)c->GetCanvasImp();
    rc->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");
    app.Run("true");
}