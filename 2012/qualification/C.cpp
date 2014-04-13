#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <cstring>
#define MAX 2000007
using namespace std;

int D[10];
set<int> S;

int main() {
    int tt, t=0;

    cin >> tt;
    while(t++<tt) {
        int a, b, solution=0;
        cin >> a >> b;
        for(int i=a; i<=b; i++) {
            int ii = i;
            int digits=0;
            
            while(ii) {
                D[digits++] = ii%10;
                ii/=10;
            }
            
            S.clear();
            for(int j=digits-2; j>=0; j--) {
                if (D[j] == 0) continue;
                int ndigit=0;
                for(int k=0; k<digits; k++) {
                    int curr=j-k;
                    if (curr < 0) curr += digits;
                    ndigit = ndigit * 10 + D[curr];
                }
                if (ndigit >= a && ndigit < i && S.find(ndigit) == S.end()) {
                     solution++;
                     S.insert(ndigit);
                }
            }
        }
        cout << "Case #" << t << ": " << solution << endl;
    }
}
