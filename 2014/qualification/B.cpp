#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int tests; cin >> tests;
    for(int test = 1; test<=tests; test++) {
        double C, F, X;
        cin >> C >> F >> X;
        
        double minn = 1e100;
        
        double FT = 0;
        for(int i=0; i<=X; i++) {
            double answer = FT+X/(2+i*F);
            minn = min(minn, answer);
            
            FT += C/(2+i*F);
        }

        cout << "Case #" << test << ": ";
        cout << fixed << setprecision(7) << minn << endl;

    }
}
