#include "FileManager.h"

FManager::FManager(string fileDir, string outDir, string name, string inputFileType, string outputFileType, int entries) {
    FilePath = fileDir;
    outFolder = outDir;
    fileName = name;
    dataEntries = entries;

    FilePath.append(fileName);  
    FilePath.append(inputFileType);
    cout << "Path to input file: " << FilePath << endl;

    outFolder.append(fileName);
    outFolder.append(outputFileType);
    cout << "Path to output file: " << outFolder << endl;

    for(int i = 0; i < entries; i++){
        vector<double> filler;
        Data.push_back(filler);
    }
}
    
    
FManager::FManager(string fileDir, string outDir, string name, int entries) {
    FilePath = fileDir;
    outFolder = outDir;
    fileName = name;
    dataEntries = entries;

    FilePath.append(fileName);  
    FilePath.append(".txt");
    cout << "Path to input file: " << FilePath << endl;

    outFolder.append(fileName);
    outFolder.append(".png");
    cout << "Path to output file: " << outFolder << endl;

    for(int i = 0; i < entries; i++){
        vector<double> filler;
        Data.push_back(filler);
    }
}

void FManager::ChangeInFolder(string newInFolder) {
    FilePath = newInFolder;
    cout << "New input file path: " << FilePath << endl;
}

void FManager::ChangeOutFolder(string newOutFolder) {
    outFolder = newOutFolder;
    cout << "New output file path: " << outFolder << endl;
}