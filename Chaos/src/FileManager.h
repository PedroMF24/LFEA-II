#ifndef __FILEMANAGER__
#define __FILEMANAGER__

#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

class FManager {
public:
    // constructors
    // FManager() = default;
    FManager(string fileDir, string outDir, string name, string inputFileType, string outputFileType, int entries);
    FManager(string fileDir, string outDir, string name, int entries);

    // getters
    const char* GetName() {return fileName.c_str();}
    const char* GetInFolder() {return FilePath.c_str();}
    const char* GetOutFolder() {return outFolder.c_str();}
    int GetdataEntries() {return dataEntries;}

    // methods
    void ChangeInFolder() {string newInFolder};
    void ChangeOutFolder() {string newOutFolder};



private:
    string FilePath;
    string outFolder;
    string fileName;
    int dataEntries = 0;
    vector<vector<double>> Data;
};

#endif