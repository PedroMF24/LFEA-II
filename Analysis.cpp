void Analysis(){
	//opens the file to be read
	fstream file;
	string filename = "NaCl-n1.xry";
	file.open(filename);

	//guarantees the file is open
	if(!file.is_open()){
		cout << "Error: File could not be opened" << endl;
		exit(-1);
	}

	//reading buffer and aux string declaration
	string buffer, aux;

	//control variables declaration
	bool B = false;
	bool R = false;

	//data storage definition
	float Bmin, Bmax, Bstep;
	vector<double> rate;

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

	//creates a TGraph with the data
	TCanvas *c = new TCanvas();
	TGraph *gr = new TGraph(angle.size(), &angle[0], &rate[0]);
	
	gr->GetXaxis()->CenterTitle();
	gr->SetTitle("NaCl Preliminar");
	gr->GetXaxis()->SetTitle("Angle [#circ]");
	gr->GetYaxis()->SetTitle("Rate [1/s]");
	gr->SetLineColor(kBlue);
	gr->SetLineWidth(2);
	gr->Draw();
	
	
	//fits the peaks into gaussians

	TF1 *fit = new TF1("fit", "gaus", 6., 6.8); //Inserir formula para fazer o fit 
	//fit->SetParameters(0.0261318, 5.39125, 0.0112239, 5.43733, 0.00893756, 5.47695, 47.2973, 265.494, 1387.72);
	// TF1 *fit = new TF1("fit", "pol1", min, max);
	// fit->SetParNames("Sigma_left", "Mean_left", "Sigma_mid", "Mean_mid", "Sigma_right", "Mean_right", "Const_left", "Const_mid", "Const_right");
	gr->Fit("fit");
	fit->Draw("same");

	// FIT LANDAU BREMSCHTRALUNG
	// TF1 *fit = new TF1("fit", "landau", Bmin, Bmax); //Inserir formula para fazer o fit 
	// //fit->SetParameters(0.0261318, 5.39125, 0.0112239, 5.43733, 0.00893756, 5.47695, 47.2973, 265.494, 1387.72);
	// // TF1 *fit = new TF1("fit", "pol1", min, max);
	// // fit->SetParNames("Sigma_left", "Mean_left", "Sigma_mid", "Mean_mid", "Sigma_right", "Mean_right", "Const_left", "Const_mid", "Const_right");
	// gr->Fit("fit");
	// fit->Draw("same");

	//saves the graph
	c->Update();
	c->SaveAs("NaCl-n1.png");
	//saves the fit results
	
}
