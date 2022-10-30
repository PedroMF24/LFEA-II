void RLC() {

    string name, folder, nametype;
	cout << "\nWrite file name!\n => ";
	cin >> name;
	folder = "../data/RLC/";
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
    cout << "Reading file...\n";
    // fstream F("src/Trat-h6a6b30_corr.txt", ios::in); // input file

    // discards the first 2 lines
    string s;
    for (int i=0; i<3; i++)
        getline(file,s);

    //initializes the data storage
    vector<vector<double>> Data;
    for(int i = 0; i < 2; i++){
        vector<double> dados;
        Data.push_back(dados);
    }

    // reads data
    while (getline(file,s)) { // true is returned if values are read
        int jj = 0;    

        stringstream line(s); // split line into words(separated by a space)
        string word;

        while(line >> word){
            Data[jj].push_back(stod(word)); // change word to double and input in Data )*1000.0)
            jj++;
        }
    }
    file.close();
    
    cout << "Creating graph...\n";
    //creates a TGraph with the data
	TCanvas *c = new TCanvas();
	TGraph *gr = new TGraph(Data[1].size(), &(Data[0][0]), &(Data[1][0])); // Time vs Channel
	
	gr->GetXaxis()->CenterTitle();
	gr->SetTitle(name.c_str());
	gr->GetXaxis()->SetTitle("Time [#mu]");
	gr->GetYaxis()->SetTitle("Channel [V]");
	gr->SetLineColor(kBlue);
	gr->SetLineWidth(2);
	gr->Draw();

	//saves the graph
	c->Update();
	c->SaveAs("../bin/Cenas.png");
}