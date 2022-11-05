#include <iostream>

using namespace std;

int main() {
    const int max_it = 13; // 13
    const int max_it_j = 10; // 10
    double a1 = 1.0, a2 = 0.0, d1 = 3.2;

    cout << " i       d\n";
    for (int i = 2; i <= max_it; ++i) {
        double a = a1 + (a1 - a2) / d1;
        cout << "a at start " << a << endl;
        for (int j = 1; j <= max_it_j; ++j) {
            double x = 0.0;
            double y = 0.0;
            for (int k = 1; k <= 1 << i; ++k) {
                y = 1.0 - 2.0*y*x;
                x = a - x * x;
                // cout << "X = " << x << " Y = " << y << endl;
            }
            a -= x / y;
            cout << "a at the end " << a << endl;
            cout << "---" << endl;
        }
        double d = (a1 - a2) / (a - a1);
        printf("%2d    %.8f\n", i, d);
        d1 = d;
        a2 = a1;
        a1 = a;
        cout << "New d1, a2, a1: " << d1 << "\t" << a2 << "\t" << a1 << endl;
    }

    return 0;
}