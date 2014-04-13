#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double S[501];
bool R[501];

int main() {
    int tt, t=0;
    cin >> tt;
    while(t++<tt) {
        int n; cin >> n;
        double X = 0;
        for(int i=0; i<n; i++) {
            cin >> S[i];
            R[i] = false;
            X += S[i];
        }   
        
        double Y = X, m = n;
        bool found = true;
        
        while(found) {
            found = false;
            for(int i=0; i<n; i++) {
                if ((X+Y)/m < S[i] && !R[i]) {
                    Y -= S[i];
                    m -= 1;
                    R[i] = true;
                    found = true;
                }
            }
            
        }
    
        cout << "Case #" << t << ":";
        
        for(int i=0; i<n; i++) {
            if (R[i]) {
                cout << " " << 0.0;            
            } else {
                cout << " " << fixed << setprecision(6) << 100 * ((X+Y)/m - S[i]) / X;
            }
        }
        cout << endl;
    }
}
