void DrawGraph(){

    //LFEA-II
    
    // read text file with fstream
    fstream F("src/Trat-h6a6b30_corr.txt", ios::in); // input file

    // discards the first 2 lines
    string s;
    for (int i=0; i<2; i++)
        getline(F,s);
    

    //initializes the data storage
    vector<vector<double>> Data;
    for(int i = 0; i < 5; i++){
        vector<double> dados;
        Data.push_back(dados);
    }

    
    // reads data
    while (getline(F,s)) { // true is returned if values are read
        int jj = 0;    

        stringstream linha(s); // split line into words(separated by a space)
        string word;

        while(linha >> word){
            Data[jj].push_back(stod(word)*1000.0); // change word to double and input in Data
            jj++;
        }
    }
    F.close();
    
    //TCanvas *c = new TCanvas();
    
    TGraph *g1 = new TGraph(Data[1].size(), &(Data[0][0]), &(Data[1][0]));
    g1->SetLineColor(kGreen);
    g1->SetTitle("Posicao em X do lazer Verde em Funcao do Tempo");
    g1->GetXaxis()->SetTitle("Tempo [ms]");
    g1->GetYaxis()->SetTitle("Posicao [mm]");

    TGraph *g2 = new TGraph(Data[2].size(), &(Data[0][0]), &(Data[2][0]));
    g2->SetLineColor(kGreen);
    g2->SetTitle("Posicao em Y do lazer Verde em Funcao do Tempo");
    g2->GetXaxis()->SetTitle("Tempo [ms]");
    g2->GetYaxis()->SetTitle("Posicao [mm]");
    
    TGraph *g3 = new TGraph(Data[3].size(), &(Data[0][0]), &(Data[3][0]));
    g3->SetLineColor(kBlue);
    g3->SetTitle("Posicao em X do lazer Azul em Funcao do Tempo");
    g3->GetXaxis()->SetTitle("Tempo [ms]");
    g3->GetYaxis()->SetTitle("Posicao [mm]");

    TGraph *g4 = new TGraph(Data[4].size(), &(Data[0][0]), &(Data[4][0]));
    g3->SetLineColor(kBlue);
    g3->SetTitle("Posicao em Y do lazer Azul em Funcao do Tempo");
    g3->GetXaxis()->SetTitle("Tempo [ms]");
    g3->GetYaxis()->SetTitle("Posicao [mm]");

    g4->Draw();
    

    //LFE
    auto c = new TCanvas();
    auto mg = new TMultiGraph();
    auto legend = new TLegend();

    //V=12
    vector<double> lambda12 = {609.4, 637.2, 730.2, 805.4, 1042.0, 1164.5, 1733.5, 2193.2, 3985.1, 5703.8, 1733};
    vector<double> elambda12 = {6.1, 5.3, 10.6, 10.3, 13.7, 30.5, 61.1, 66.1, 155.1, 249.8, 61};
   
    vector<double> V_Vm12 = {0.028, 0.049, 0.162, 0.278, 0.604, 0.786, 1.000, 0.950, 0.630, 0.419, 0.982};
    vector<double> eV_Vm12 = {0.007, 0.002, 0.004, 0.005, 0.007, 0.007, 0.007, 0.005, 0.01, 0.004, 0.005};

    /*vector<double> I_Im12 = {0.18, 0.23, 0.41, 0.56, 0.92, 1.00, 0.83, 0.56, 0.12, 0.039, 0.828};
    vector<double> eI_Im12 = {0.02, 0.02, 0.05, 0.05, 0.06, 0.06, 0.07, 0.06, 0.02, 0.007, 0.0714};*/

    auto V12 = new TGraphErrors(lambda12.size(), &lambda12[0], &V_Vm12[0],&elambda12[0], &eV_Vm12[0]);
    V12->SetLineColor(kBlue);
    mg->Add(V12);
    legend->AddEntry(V12, "V/Vm - T = (2281 +/- 8) K");

    /*auto I12 = new TGraphErrors(lambda12.size(), &lambda12[0], &I_Im12[0],&elambda12[0], &eI_Im12[0]);
    I12->SetLineColor(kRed);
    mg->Add(I12);
    legend->AddEntry(I12, "I/Im - T = (2281 +/- 8) K");*/

    //V=10
    vector<double> lambda10 = {652, 730, 805.4, 1042, 1164.5, 1733.5, 2193.2, 3985.1, 5703.8, 2027};
    vector<double> elambda10 = {6, 11, 10, 14, 31, 61, 66, 155, 250, 59};
   
    vector<double> V_Vm10 = {0.07, 0.13, 0.22, 0.56, 0.78, 0.99, 0.97, 0.66, 0.47, 1.00};
    vector<double> eV_Vm10 = {0.004, 0.004, 0.006, 0.007, 0.01, 0.006, 0.013, 0.007, 0.007, 0.01};

    /*vector<double> I_Im10 = {0.244, 0.395, 0.547, 0.912, 1.000, 0.844, 0.580, 0.128, 0.041, 0.694};
    vector<double> eI_Im10 = {0.02, 0.036, 0.04, 0.043, 0.045, 0.061, 0.05, 0.018, 0.007, 0.122};*/

    auto V10 = new TGraphErrors(lambda10.size(), &lambda10[0], &V_Vm10[0],&elambda10[0], &eV_Vm10[0]);
    V10->SetLineColor(kViolet);
    mg->Add(V10);
    legend->AddEntry(V10, "V/Vm - T = (2256 +/- 4) K");

    /*auto I10 = new TGraphErrors(lambda10.size(), &lambda10[0], &I_Im10[0],&elambda10[0], &eI_Im10[0]);
    I10->SetLineColor(kGreen);
    mg->Add(I10);
    legend->AddEntry(I10, "I/Im - T = (2256 +/- 4) K");*/


    //V=8
    vector<double> lambda8 = {623.6, 730.15, 805.4, 1042.0, 1164.5, 1733.5, 2193.2, 3985.1, 5703.8, 2027};
    vector<double> elambda8 = {5, 11, 10, 14, 31, 61, 66, 155, 249.75, 59};
   
    vector<double> V_Vm8 = {0.04, 0.06, 0.16, 0.44, 0.64, 0.97, 0.96, 0.7, 0.53, 1};
    vector<double> eV_Vm8 = {0.011, 0.008, 0.010, 0.014, 0.023, 0.045, 0.032, 0.024, 0.024, 0.05};

    /*vector<double> I_Im8 = {0.109, 0.254, 0.379, 0.747, 0.867, 0.858, 0.630, 0.154, 0.051, 1};
    vector<double> eI_Im8 = {0.017, 0.043, 0.056, 0.085, 0.099, 0.096, 0.080, 0.028, 0.011, 1.22};*/

    auto V8 = new TGraphErrors(lambda8.size(), &lambda8[0], &V_Vm8[0], &elambda8[0], &eV_Vm8[0]);
    V8->SetLineColor(kRed);
    mg->Add(V8);
    legend->AddEntry(V8, "V/Vm - T = (2065 +/- 9) K");

    /*auto I8 = new TGraphErrors(lambda8.size(), &lambda8[0], &I_Im8[0], &elambda8[0], &eI_Im8[0]);
    I8->SetLineColor(kGreen);
    mg->Add(I8);
    legend->AddEntry(I8, "I/Im - T = (2065 +/- 9) K");*/


    //V=6
    vector<double> lambda6 = {707.3, 730.2, 805.4, 1042.0, 1164.5, 1733.5, 2193.2, 3985.1, 5703.8};
    vector<double> elambda6 = {7, 11, 10, 14, 31, 61, 66, 155, 250};
   
    vector<double> V_Vm6 = {0.07, 0.07, 0.11, 0.36, 0.55, 0.93, 0.96, 0.74, 0.54};
    vector<double> eV_Vm6 = {0.01, 0.01, 0.007, 0.012, 0.013, 0.019, 0.017, 0.02, 0.009};

    /*vector<double> I_Im6 = {};
    vector<double> eI_Im6 = {};*/

    auto V6 = new TGraphErrors(lambda6.size(), &lambda6[0], &V_Vm6[0], &elambda6[0], &eV_Vm6[0]);
    V6->SetLineColor(kGreen);
    mg->Add(V6);
    legend->AddEntry(V6, "V/Vm - T = (1865 +/- 11) K");

    /*auto I6 = new TGraphErrors(lambda6.size(), &lambda6[0], &I_Im6[0], &elambda6[0], &eI_Im6[0]);
    I6->SetLineColor(kGreen);
    mg->Add(I6);
    legend->AddEntry(I6, "I/Im - T = (1865 +/- 11) K");*/


    mg->Draw("AP");
    legend->Draw();
}