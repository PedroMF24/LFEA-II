void FitChaos() {
    // // vector<double> f = {345.2, 346.7, 352.5, 353.7, 354.8, 357.3, 357.5, 364.4, 362.3, 364.5, 366.4, 366.6};                          
    // // vector<double> ef = {0.03, 0.03, 0.03, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02};

    // // vector<double> A = {803, 898, 1785, 2128, 2430, 2537, 2169, 1474, 915, 775, 758};
    // // vector<double> eA = {34, 34, 30, 35, 37, 42, 28, 35, 35, 38, 34, 35};

    // vector<double> A = {0, 101, 144, 202, 564, 1030, 1497, 2067, 2568, 3073, 3526, 4028, 4528, 552};
    // vector<double> eA = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    // vector<double> P = {0.28, 0.48, 0.52, 0.54, 0.56, 0.56, 0.52, 0.50, 0.50, 0.46, 0.38, 0.36, 0.36, 0.64};
    // vector<double> eP = {0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4};

// vector<double> A = {0, 101, 144, 202, 564, 1030, 1497, 2067, 2568, 3073, 3526, 4028, 4528, 552};
// vector<double> eA = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

// vector<double> P = {0.28, 0.48, 0.52, 0.54, 0.56, 0.56, 0.52, 0.50, 0.50, 0.46, 0.38, 0.36, 0.36, 0.64};
// vector<double> eP = {0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4};

// vector<double> f = {345.2, 346.7, 352.5, 353.7, 354.8, 357.3, 357.8, 361.4, 362.3, 364.5, 366.4, 366.6};                          
// vector<double> ef = {0.03, 0.03, 0.03, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02};

// vector<double> A = {8.03, 8.98, 17.85, 21.28, 24.30, 25.37, 21.69, 14.74, 11.49, 9.15, 7.79, 7.58};
// vector<double> eA = {0.34, 0.34, 0.30, 0.35, 0.37, 0.42, 0.28, 0.35, 0.35, 0.38, 0.34, 0.35};


// vector <double> w;
// vector <double> ew;
// vector <double> amp;
// vector <double> eamp;

// for (auto &i : f)
// {
//     w.push_back(2*TMath::Pi()*i*1000);
// }

// for (auto &i : ef)
// {
//     ew.push_back(2*TMath::Pi()*i*1000);
// }


// for (auto &i : A)
// {
//     amp.push_back(i/1000);
// }

// for (auto &i : eA)
// {
//     eamp.push_back(i/1000);
// }

    TCanvas *c = new TCanvas();

//     // TF1* func = new TF1("func","[0]/sqrt([1]*[1]+pow(x*[2]+1.0/(x*[3]), 2))"); //, 2160, 2350
//     // func->SetParNames("a", "R", "L", "C");
//     // func->SetParameters(5077,440.6,6.7*0.001,15.9*pow(10,-12)); // 6.7
// TF1* func = new TF1("func","[0]/sqrt(440.6*440.6+pow(x*6.7*0.001+1.0/(x*15.9*pow(10,-12)), 2))"); //, 2160, 2350
//     // func->SetParNames("a");
//     // func->SetParameters(5077);
    //TF1* solit = new TF1("solit", "[0]/cosh(-[1](1.0+[0]/(2[2])) * sqrt(3[0]/(4[2][2][2])) *(x-[3]))");
    //solit->SetParNames("n0", "c0", "h", "t0");

    // DEPENDENCIA DE H
    vector<double> v = {0.77515, 0.861325, 0.910464, 0.959003};
    vector<double> n = {31,11,8,6};
    vector<double> h = {0.02,0.04,0.05,0.06};

    vector<double> rv = {0.731035, 0.863821, 0.902604};
    vector<double> rn = {8,3,5};
    vector<double> rh = {0.04,0.05,0.06};

    // DEPENDENCIA DE A
    // vector<double> v = {0.704721, 0.743872, 0.861325, 0.939628};
    // vector<double> n = {7,8,11,13};
    // vector<double> a = {0.02,0.03,0.06,0.08};

    // vector<double> rv = {0.700913, 0.731035, 0.82055};
    // vector<double> rn = {2,8,10};
    // vector<double> ra = {0.03,0.06,0.08};

    // DEPENDENCIA EM B
    // vector<double> v = {0.861325,0.861325,0.861325};
    // vector<double> n = {6,11,16};
    // vector<double> b = {0.1,0.2,0.3};

    // vector<double> rv = {0.721495,0.82055,0.788371};
    // vector<double> rn = {4,10,13};
    // vector<double> rb = {0.1,0.2,0.3};

    TF1* func = new TF1("func", "[0]*x*x+[1]*x+[2]");
    func->SetParNames("a","m","b");
    TF1* fun = new TF1("fun", "[0]*x+[1]");
    fun->SetParNames("m","b");
    // solit->SetParNames("n0", "c0", "h", "t0");

    // TGraphErrors *gr = new TGraphErrors(w.size(), &w[0], &A[0],&ew[0], &eA[0]);
    TGraph *gn = new TGraph(h.size(), &h[0], &n[0]);
    TGraph *gr1 = new TGraph(rh.size(), &rh[0], &rn[0]);

    TGraph *gv = new TGraph(h.size(), &h[0], &v[0]);
    TGraph *gr2 = new TGraph(rh.size(), &rh[0], &rv[0]);

    TMultiGraph *mg = new TMultiGraph();

    // TGraph *gr = new TGraph(h.size(), &h[0], &v[0]);

    gr1->SetMarkerStyle(4);
    gr2->SetMarkerStyle(4);

    gn->SetMarkerStyle(3);
    gv->SetMarkerStyle(3);

    // gr1->Fit("fun");
    // mg->Add(gr1);
    // mg->Add(gn);
    // mg->SetTitle("H Number Fit");
    // mg->GetXaxis()->SetTitle("H [m]");
    // mg->GetYaxis()->SetTitle("Number of Solitons");
    // mg->Draw("AP");
    // c->SaveAs("FitNumber_Linear_DependH.png");

    gr2->Fit("fun");
    mg->Add(gr2);
    mg->Add(gv);
    mg->SetTitle("H Velocity Fit");
    mg->GetXaxis()->SetTitle("H [m]");
    mg->GetYaxis()->SetTitle("Soliton Speed [m/s]");
    mg->Draw("AP");
    c->SaveAs("FitVelocity_Linear_DependH.png");




    // gr->GetXaxis()->SetTitle("Height h [m]");
    // gr->GetYaxis()->SetTitle("Speed c [m/s]");
    // //gr->GetXaxis()->SetTitle("Angular Frequency [rad/s]");
    // //gr->GetYaxis()->SetTitle("Amplitude [V]");
    // gr->Draw("AP");



    
}