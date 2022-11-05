#include "FileManager.cpp"
#include "RootClass.cpp"

int main() {
    FManager FM("../data/", "../bin/", "ola", 2);
    RootClass T(3);
    // printf("Entries = %d, Name = %s\n", FM.GetdataEntries(), FM.GetName());
    // printf("inFile = %s, outFile = %s\n", FM.GetInFolder(), FM.GetOutFolder());
    // printf("inFileType = %s, outFileType = %s\n", FM.GetInFileType(), FM.GetOutFileType());

    // FM.MakeFilePath();

    return 0;
}