void KdV() {

    string name, folder, nametype;
	cout << "\nWrite file name!\n -> ";
	cin >> name;
	folder = "../data/Solitons/";
	folder.append(name);
	nametype = folder;
	nametype.append(".txt");
    
    fstream file;
	file.open(nametype.c_str());

    //guarantees the file is open
	if(!file.is_open()){
		cout << "Error: File could not be opened" << endl;
		exit(-1);
	}
    // fstream F("src/Trat-h6a6b30_corr.txt", ios::in); // input file

    // discards the first 2 lines
    string s;
    for (int i=0; i<3; i++)
        getline(file,s);
    

    //initializes the data storage
    vector<vector<double>> Data;

    for(int i = 0; i < 5; i++){
        vector<double> data;
        Data.push_back(data);
    }
    
    // reads data
    while (getline(file,s)) { // true is returned if values are read
        int jj = 0;    

        stringstream line(s); // split line into words(separated by a space)
        string word;

        while(line >> word){
            // word = word.replace(/,/g, '.')
            Data[jj].push_back(stod(word)); // change word to double and input in Data )*1000.0)
            jj++;
        }
    }
    file.close();

    TCanvas *c = new TCanvas();
    TMultiGraph *mg = new TMultiGraph();
    // auto legend = new TLegend();

    TGraph *g1 = new TGraph(Data[1].size(), &(Data[0][0]), &(Data[1][0]));
    g1->SetLineColor(kRed);
    g1->SetLineWidth(2);
    g1->SetTitle("Posicao em X do lazer Verde em Funcao do Tempo");
    g1->GetXaxis()->SetTitle("Tempo [ms]");
    g1->GetYaxis()->SetTitle("Posicao [mm]");
    mg->Add(g1);

    TGraph *g2 = new TGraph(Data[2].size(), &(Data[0][0]), &(Data[2][0]));
    g2->SetLineColor(kOrange);
    g2->SetLineWidth(2);
    g2->SetTitle("Posicao em Y do lazer Verde em Funcao do Tempo");
    g2->GetXaxis()->SetTitle("Tempo [ms]");
    g2->GetYaxis()->SetTitle("Posicao [mm]");
    mg->Add(g2);

    TGraph *g3 = new TGraph(Data[3].size(), &(Data[0][0]), &(Data[3][0]));
    g3->SetLineColor(kBlue);
    g3->SetLineWidth(2);
    g3->SetTitle("Posicao em X do lazer Azul em Funcao do Tempo");
    g3->GetXaxis()->SetTitle("Tempo [ms]");
    g3->GetYaxis()->SetTitle("Posicao [mm]");
    mg->Add(g3);

    TGraph *g4 = new TGraph(Data[4].size(), &(Data[0][0]), &(Data[4][0]));
    g4->SetLineColor(kViolet);
    g4->SetLineWidth(2);
    g4->SetTitle("Posicao em Y do lazer Azul em Funcao do Tempo");
    g4->GetXaxis()->SetTitle("Tempo [ms]");
    g4->GetYaxis()->SetTitle("Posicao [mm]");
    mg->Add(g4);

    mg->SetTitle(name.c_str());
    mg->GetXaxis()->SetTitle("Time [ms]");
    mg->GetYaxis()->SetTitle("Position [mm]");
    mg->Draw("ACP");

    // gr->GetXaxis()->CenterTitle();
	// gr->SetTitle(name.c_str());
	// gr->GetXaxis()->SetTitle("Angle [#circ]");
	// gr->GetYaxis()->SetTitle("Rate [1/s]");
	// gr->SetLineColor(kBlue);
	// gr->SetLineWidth(2);
	// gr->Draw();

    string dir = "../bin/";
	dir.append(name);
	dir.append(".png");

    c->Update();
    c->SaveAs(dir.c_str());
}