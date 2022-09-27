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

	ifstream ifile;

	string name;
	string nametype;
	cout << "\nWrite file name!\n -> ";
	cin >> name;
	nametype = name;
	nametype.append(".txt");
	ifile.open(nametype.c_str());

	if (!ifile)
	{
		cout << "Error: file could not be opened or does not exist" << endl;
		exit(1);
	}

	TApplication app("app", NULL, NULL);
	TCanvas *c = new TCanvas();

	// int n_bin=6; //INSERIR
	// double min=115; //inserir canal minimo
	// double max=121; // inserir o canal maximo 

	// // HISTOGRAMAS

	// TH1D *hist = new TH1D("h",name.c_str(), n_bin, min, max);
	// hist->SetLineWidth(2);
	// double channel, contagem;

	// while(ifile >> channel >> contagem) {
	// 	for(int i=0; i<contagem; i++)
	// 		hist->Fill(channel);
	// }2

	// ifile.close();

	// hist->SetStats(kFALSE);
	// hist->SetTitle("");
	// hist->GetYaxis()->SetTitle("Events");
	// hist->GetXaxis()->SetTitle("Channels");
	// hist->GetXaxis()->CenterTitle();

	// // gStyle->SetOptStat();

	// hist->Draw("C");






	double x, y, ex, ey;
	x = y = ex = ey = 0;
	
	ex = 0.013;
	ey = 10;

	double min, max;
	min = 0;
	max = 180;

	int n = 1023;
	double vecx[n];
	double vecy[n];
	double vecex[n];
	double vecey[n];
	int i = 0;

	// cout << "Total counts = " << counts << endl;

	while(ifile >> x >> y) {
		// newX = 0.007434*x+0.159817;
		if (x >= min && x <= max) {
			ey = sqrt(y);
			ex = sqrt(pow(x*0.005,2) + pow(4.55*0.013,2) + 3*3);
			vecx[i] = x*4.55 + 100;
			vecy[i] = y;
			vecex[i] = ex;
			vecey[i] = ey;
			//max = x;
			i++;
		}
	};

	auto gr = new TGraphErrors(max, vecx, vecy, vecex, vecey);

	gr->SetLineWidth(2);
	gr->SetLineColor(4);
	
	// gr->SetMarkerColor(4);
	// gr->SetMarkerStyle(20);
	gr->GetXaxis()->CenterTitle();
	gr->SetTitle();
	gr->GetXaxis()->SetTitle("Energy [keV]");
	gr->GetYaxis()->SetTitle("Events");

	gr->Draw("ALP");





	// auto gr = new TGraph();
	// // gr->SetTitle("Calib");
	// double x, y;
	// // newX;
	// double min, max;
	// // newX;
	// int counts = 0;
	// min = 0;
	// max = 200;
	// while(ifile >> x >> y) {
	// 	// newX = 0.007434*x+0.159817;
	// 	if (x >= min && x <= max) {
	// 		counts += y;
	// 		gr->AddPoint(x*0.455 + 100, y);
	// 		// max = x;
	// 	}
	// };
	// cout << counts << endl;

	// gr->SetLineWidth(2);
	// gr->SetLineColor(4);
	// // gr->SetMarkerColor(4);
	// // gr->SetMarkerStyle(20);
	// gr->GetXaxis()->CenterTitle();
	// gr->GetXaxis()->SetTitle("Energy [keV]");
	// gr->GetYaxis()->SetTitle("Events");

	// gr->Draw();


	// In case I want to fit stuff!
	// TF1 *fit = new TF1("fit", "[6]*exp(-0.5*((x-[1])/[0])*((x-[1])/[0])) + [7]*exp(-0.5*((x-[3])/[2])*((x-[3])/[2])) + [8]*exp(-0.5*((x-[5])/[4])*((x-[5])/[4]))", min, max); //Inserir formula para fazer o fit 
	// fit->SetParameters(0.0261318, 5.39125, 0.0112239, 5.43733, 0.00893756, 5.47695, 47.2973, 265.494, 1387.72);
	// // TF1 *fit = new TF1("fit", "pol1", min, max);
	// fit->SetParNames("Sigma_left", "Mean_left", "Sigma_mid", "Mean_mid", "Sigma_right", "Mean_right", "Const_left", "Const_mid", "Const_right");
	// gr->Fit("fit");
	// fit->Draw("same");

	// TF1 *fit = new TF1("fit", "pol1", min, max);
	// // fit->SetParNames("m", "b");
	// gr->Fit("fit");
	// // double chi2 = fit->GetChisquare();
	// // cout << "chi2 = " << chi2 << endl;
	// fit->Draw("same");
	
	ifile.close();

	string dir = "bin/";
	dir.append(name);
	dir.append("_error.png");
	
	//gPad->SetLogy();

	// c->SetTickx();
	// c->SetTicky();
	// c->SetGridx();
	// c->SetGridy();
	c->Update();
	c->Draw();
	c->SaveAs(dir.c_str());

	TRootCanvas *rc = (TRootCanvas *)c->GetCanvasImp();
	rc->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");
	app.Run("true");
	
	return 0;
}