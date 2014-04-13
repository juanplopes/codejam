#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int A[60], B[60];

bool eq(double a, double b) {
    return abs(a-b) <= 1e-5;
}

bool col(double s1, double s2) {
    double e1 = s1+5, e2=s2+5;
    return ((s1 >= s2) and s1 < e2) or
           ((s2 >= s1) and s2 < e1);
}

int main() {
    int tt, t=0;
    cin >> tt;
    while(t++<tt) {
        int n; cin >> n;
        for(int i=0; i<n; i++) {
            char ig;
            cin >> ig >> A[i] >> B[i];
        }
        
        double mint = 10000000;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if (i==j) continue;
                if (A[i] < A[j] or eq(A[i],A[j])) continue;
                int dem = A[i]-A[j];
                int num = -(B[i]+5-B[j]);
                if (dem == 0) continue;
                double time = (double)num/(double)dem;
                if (time < 0) continue;
                double istart = A[i]*time+B[i];                    
                double jstart = A[j]*time+B[j];

                bool cani = false, canj = false;
                for(int k=0; k<n; k++) {
                    if (j==k or i==k) continue;
                    double kstart = A[k]*time+B[k];

                    cout << i << " " << j << " " << k << " " << time << " -> "
                             << istart << " " << jstart << " " << kstart << " : "
                             << col(istart, kstart) << " " << col(jstart, kstart) << endl;    

                    cani = cani || col(istart, kstart);
                    canj = canj || col(jstart, kstart);
                }
                cout << "***" << cani << " " << canj << endl;
                if (cani and canj)
                    mint = min(mint, time);
            }
        }
        cout << "Case #" << t << ": " << mint << endl;
    }
}
