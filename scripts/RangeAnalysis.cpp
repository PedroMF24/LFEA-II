void RangeAnalysis(){
	//opens the file to be read
	fstream file;
	string filename = "../src/NaCl-Cut.xry";
	file.open(filename);

	//guarantees the file is open
	if(!file.is_open()){
		cout << "Error: File could not be opened" << endl;
		exit(-1);
	}

	//creates a new vector using only some data
	float start = 9.8; // pequeno erro, aparece valor +1 aqui e em end
	float end = 10.4;

	//reading buffer and aux string declaration
	string buffer, aux;

	//control variables declaration
	bool B = false;
	bool R = false;

	//data storage definition
	float Bmin, Bmax, Bstep;
	vector<double> rate;

	// Integral
	double sum = 0;

	//reads the file
	while(getline(file, buffer)){
		//reads the B angle related data
		if(buffer[1] == 'b'){
			//discards next (useless) line
			getline(file, buffer);

			//gets the relevant line and stores the information
			getline(file, buffer);

			//gets the Bmin value
			stringstream line(buffer);
			getline(line, aux, ' ');
			Bmin = stof(aux);

			//gets the Bmax value
			getline(line, aux, ' ');
			Bmax = stof(aux);

			//discards the next (useless) value
			getline(line, aux, ' ');

			//gets the Bstep value
			getline(line, aux, ' ');
			Bstep = stof(aux);

			//sets B as read
			B = true;
		}

		//reads the rate R related data
		if(buffer[0] == 'R'){
			//discards the next (useless) 2 lines
			getline(file, buffer);
			getline(file, buffer);

			//gets the number of entries that need to be read
			getline(file, buffer);
			stringstream line(buffer);
			getline(line, aux, ' ');
			getline(line, aux, ' ');
			int entries = stoi(aux);

			//reads the entries and stores them in the rate vector
			for(int i = 0; i < entries; ++i){
				getline(file, buffer);
				rate.push_back(stod(buffer));
				// sum += stod(buffer);
			}

			//sets R as read
			R = true;
		}

		//if both interest variables were read, stop reading the file
		if(B && R)
			break;
	}

	

	//makes a vector with all the measured angles
	vector<double> angle;

	for(int i = 0; i < rate.size(); ++i)
		angle.push_back((double)(Bmin + (float)i*Bstep));

	vector<double> sampleA, sampleR;

	for(int i = 0; i < rate.size(); ++i){
		if((Bmin + (float)i*Bstep) > start){
			sampleA.push_back(angle[i]);
			sampleR.push_back(rate[i]);
			sum += rate[i];
		}
		if((Bmin + (float)i*Bstep) > end)
			break;
	}

	cout << "Integral of Rates = " << sum << endl;

	//creates a TGraph with the data
	TCanvas *c = new TCanvas();
	TGraph *gr = new TGraph(sampleA.size(), &sampleA[0], &sampleR[0]);

	
	gr->GetXaxis()->CenterTitle();
	gr->SetTitle("NaCl Cut");
	gr->GetXaxis()->SetTitle("Angle [#circ]");
	gr->GetYaxis()->SetTitle("Rate [1/s]");
	gr->SetLineColor(kBlue);
	gr->SetLineWidth(2);
	gr->Draw();
	
	
	//fits the peaks into gaussians

	// TF1 *fit = new TF1("fit", "gaus", 6., 6.8); //Inserir formula para fazer o fit 
	// //fit->SetParameters(0.0261318, 5.39125, 0.0112239, 5.43733, 0.00893756, 5.47695, 47.2973, 265.494, 1387.72);
	// // TF1 *fit = new TF1("fit", "pol1", min, max);
	// // fit->SetParNames("Sigma_left", "Mean_left", "Sigma_mid", "Mean_mid", "Sigma_right", "Mean_right", "Const_left", "Const_mid", "Const_right");
	// gr->Fit("fit");
	// fit->Draw("same");

	// FIT LANDAU BREMSCHTRALUNG
	// TF1 *fit = new TF1("fit", "landau", Bmin, Bmax); //Inserir formula para fazer o fit 
	// //fit->SetParameters(0.0261318, 5.39125, 0.0112239, 5.43733, 0.00893756, 5.47695, 47.2973, 265.494, 1387.72);
	// // TF1 *fit = new TF1("fit", "pol1", min, max);
	// // fit->SetParNames("Sigma_left", "Mean_left", "Sigma_mid", "Mean_mid", "Sigma_right", "Mean_right", "Const_left", "Const_mid", "Const_right");
	// gr->Fit("fit");
	// fit->Draw("same");

	//saves the graph
	c->Update();
	c->SaveAs("../bin/Cenas.png");
	//saves the fit results
	
}
