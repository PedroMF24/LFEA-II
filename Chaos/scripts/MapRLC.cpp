void MapRLC() {

int k, n;
float mi;
double x;

    // FILE *fp;

    // fp=fopen("../data/Feigenbaum.txt","w");
    // // definindo o valoar inicial de mi
    // mi =  2.0; // 2.0;
    // for(k=0; k<499; k++)
    // {
    //     mi = mi + 0.004;
    //     x = 0.8;
    //     for(n=0; n<499; n++) // n<999 - n>500
    //     {
    //         x = mi*x*(1-x);
    //         if (n>434)
    //             fprintf(fp,"%f \t %lf\n", mi, x);
    //     }
    // }   
    // fclose(fp);

	fstream file;
    file.open("../data/Feigenbaum.txt");
    //guarantees the file is open
	if(!file.is_open()){
		cout << "Error: File could not be opened" << endl;
		exit(-1);
	}

    //initializes the data storage
    vector<vector<double>> Data;
    for(int i = 0; i < 2; i++){
        vector<double> dados;
        Data.push_back(dados);
    }

    // reads data
    string s;
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

    TCanvas *c = new TCanvas();
	TGraph *gr = new TGraph(Data[1].size(), &(Data[0][0]), &(Data[1][0])); // Time vs Channel
	
	gr->GetXaxis()->CenterTitle();
	gr->SetTitle("Feigenbaum");
	gr->GetXaxis()->SetTitle("Time [#mu]");
	gr->GetYaxis()->SetTitle("Channel [V]");
    gr->SetMarkerColor(kBlue);
    // gr->SetMarkerStyle(kFullDotSmall);
	// gr->SetLineColor(kRed);
	// gr->SetLineWidth(2);
	gr->Draw("AP"); // No option draws lines, "AP" only draws points

	//saves the graph
	c->Update();
	c->SaveAs("../bin/Feigenbaum.png");

    return 0;


}