void Map2D() {

int k, n;
float a;
float b;
double x;

    FILE *fp;

    fp=fopen("2DMap.txt","w");
    // definindo o valoar inicial de a
    a =  2.0;
    b = 1.0;
    for(k=0; k<499; k++)
    {
        a = a + 0.005;
        b = b + 0.005;
        x = 0.8;
        for(n=0; n<999; n++)
        {
            x = b+a*cos(x); //b + a*x*(1-x);
            printf("X = %lf\n", x);
            if (n>500)
                fprintf(fp,"%f \t %f \t %lf\n", a, b, x);
        }
    }   
    fclose(fp);

	fstream file;
    file.open("2DMap.txt");
    //guarantees the file is open
	if(!file.is_open()){
		cout << "Error: File could not be opened" << endl;
		exit(-1);
	}

    //initializes the data storage
    vector<vector<double>> Data;
    for(int i = 0; i < 3; i++){
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
	// TGraph *gr = new TGraph(Data[1].size(), &(Data[0][0]), &(Data[1][0])); // Time vs Channel
	
    TGraph2D *gr2D = new TGraph2D(Data[1].size(), &(Data[0][0]), &(Data[1][0]), &(Data[2][0]));
    // gStyle->SetPalette(1);
    gr2D->Draw();

	// gr->GetXaxis()->CenterTitle();
	// gr->SetTitle("ChaosMap");
	// gr->GetXaxis()->SetTitle("Time [#mu]");
	// gr->GetYaxis()->SetTitle("Channel [V]");
	// // gr->SetLineColor(kRed);
	// gr->SetLineWidth(2);
	// gr->Draw();

	//saves the graph
	c->Update();
	c->SaveAs("2DMap.png");

    return 0;
}