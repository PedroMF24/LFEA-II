#include <iostream>
#include <vector>

using namespace std;

int main() {

    // FEIGENBAUM DELTA

    // b = a - x^2
    // bl = -2x

    vector<double> aVec;
    vector<double> blVec;

    double a1 = 1;
    double a2 = 0;
    double d1 = 3.2;
    double d = 0;

    double bl = 0;
    double b = 0;
    double bl1 = 0;

    int iMax = 13;
    int jMax = 10;

    for (int i = 2; i <= iMax; ++i)
    {
        double a = a1 + (a1 - a2)/d1; // 0.7
        for (int j = 0; j <= jMax; ++j)
        {
            bl = 0;
            b = 0;
            bl1 = 0;
            for (int k = 1; k <= 1 << i; ++k)
            {
                bl = 1 - 2*bl*b; // 0.9
                b = a - b*b;
            }
            a -= b/bl; // 0.8
            // for (int k = 1; k <= 1; ++k)
            // {
            //     b = a - b*b;
            //     bl1 = 1 - 2*bl*b;
            // }
            // lim = bl1/bl;
        }
        blVec.push_back(bl);
        aVec.push_back(a);
        d = (a1 - a2)/(a - a1);
        // double alpha = d/lim;
        printf("%2d \t %.8f\n", i, d);
        d1 = d;
        a2 = a1;
        a1 = a;
    }

    // cout << blVec.size() << " " << aVec.size() << endl;  
    double alpha = 0;
    printf("");
    for (int i = 1; i <= blVec.size(); i++)
    {
        alpha = -d / (blVec[blVec.size() - 1] / blVec[blVec.size() - 2]);
        printf("%2d \t %.8f\n", i, alpha);
    }
    
    

    return 0;
}