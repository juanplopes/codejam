#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double T[100010];

int main() {
    int tt, t=0;
    cin >> tt;
    while(t++<tt) {
        int a, b; cin >> a >> b;
        
        T[0] = 1;
        for(int i=1; i<=a; i++) {
            cin >> T[i];
            T[i] *= T[i-1];
        }
        
        double minn = b+2;
        for(int i=0; i<=a; i++) {
            double x = T[i], y = 1-T[i];
            int wx = (b-a)+2*(a-i)+1;
            int wy = wx+b+1;
            
            minn = min(minn, x*wx+y*wy);
        }

        cout << "Case #" << t << ": " << fixed << setprecision(6) << minn << endl;
    }
}
