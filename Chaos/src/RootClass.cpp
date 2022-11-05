#include "RootClass.h"

RootClass::RootClass(int entries) {
	vector<double> data(3,0.0);
	// cout << data[0];
	for(int i = 0; i < entries; i++){
        Data.push_back(data);
    }
	for (int i = 0; i < Data.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < data.size(); j++)
			cout << Data[i][j];
	}
}

// void RootClass::GetGraph(string name, int n1, int n2) {

// 	auto c = new TCanvas("canvas", "Canvas", 0, 0, 800, 800); // size 800x800

// 	vector<double> x, y;

// 	x = RootClass[n1];
// 	y = RootClass[n2];

// 	TGraph *gr = new TGraph(x.size(), &x[0], &y[0]);

// 	gr->SetTitle(name.c_str());
// 	gr->SetMarkerColor(1);
// 	gr->SetMarkerStyle(20);
// 	gr->SetMarkerSize(0.2);
// 	gr->SetLineColor(1);
// 	gr->SetLineWidth(1);
// 	gr->Draw();
	
// 	//c->BuildLegend();
// 	c->Update(); // update display canvas
// 	c->SaveAs((name.append(".png")).c_str()); // save graphics in pdf format (eps, png, ...)
// 	c->Clear();

// 	delete gr;
// 	delete c;
// }

// void RootClass::GetAllGraphs() {

// 	auto c = new TCanvas("canvas", "Canvas", 0, 0, 800, 800); // size 800x800

// 	int number = MS.size(); // number of entries in map
// 	TGraph *gr[number];
// 	for (int i = 0; i < number; i++)
// 		gr[i] = new TGraph();

// 	TMultiGraph *mg = new TMultiGraph();
	
// 	// iterator with vector of ODEPoints
// 	auto itr = MS.begin();

// 	vector<double> x;
// 	vector<double> y;

// 	for (int j = 0; j < number; j++, itr++)
// 	{
// 		for (int i = 0; i < itr->second.size(); i++) {
// 			x.push_back(itr->second[i].GetT());
// 			y.push_back(itr->second[i].GetX()[0]);
// 		}
// 		gr[j] = new TGraph( itr->second.size(), &x[0], &y[0] );
// 		const char *name = itr->first.c_str();
// 		gr[j]->SetName(name);
// 		gr[j]->SetTitle(name); // Name of the method
// 		gr[j]->SetMarkerColor(j + 1); // 1 is black
// 		gr[j]->SetMarkerStyle(20);
// 		gr[j]->SetMarkerSize(0.2);
// 		gr[j]->SetLineColor(1);
// 		gr[j]->SetLineWidth(1);
// 		mg->Add( gr[j] );
// 		x.clear();
// 		y.clear();
// 	}
// 	mg->Draw("ALP");
//     // gPad->Modified();

// 	c->BuildLegend();

// 	c->Update(); // update display canvas
// 	c->SaveAs("AllGraphs.pdf"); // save graphics in pdf format (eps, png, ...)

// 	// House keeping!
// 	// for (int i = 0; i < number; i++)
//     //     delete gr[i];
// 	//delete mg;
// 	//delete c;
// }