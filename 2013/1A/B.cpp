#include <iostream>
#include <string>
#include <cstring>
#define MAX 10010
#define ull unsigned long long
using namespace std;

int V[MAX];
int T[MAX];
int Q[MAX];


int main() {
    int cc=0, cases; 
    cin >> cases;
    while(cc++ < cases) {
        int e, r, n;
        cin >> e >> r >> n;
        for(int i=0; i<n; i++) {
            cin >> V[i];
            T[i] = r;
            Q[i] = r;
        }
        T[0] = e;
        Q[0] = e;
        
        r = min(r, e);
        for(int i=n-1; i>=0; i--) {
            cout << " T =";
            for(int j=0; j<n; j++) {
                cout << " " << T[j] ;
            }
            cout << endl << " Q =";
            for(int j=0; j<n; j++) {
                cout << " " << Q[j] ;
            }
            cout << endl;
            for(int j=i-1; j>=0; j--) {      
                if (V[j] >= V[i]) break;   
                int much = min(e-T[i], T[j]-r);
                much = min(much, much);

                T[j] -= much;
                T[i] += much;

                Q[i] += much;
                Q[j] = Q[j+1];
                
                /*if (Q[j] > e || Q[i] > e) {
                    int other = max(Q[j]-e, Q[i]-e);
                    T[j] += other;
                    T[i] -= other;

                    Q[i] -= other;
                    Q[j] = Q[j+1]-r+T[j];   
                }*/
            }
        }
        
        ull answer = 0;
        for(int i=0; i<n; i++) {
            cout << " " << T[i] ;
            answer += T[i] * V[i];
        }
        cout << endl;
        
        
        
        cout << "Case #" << cc << ": " << answer << endl;
    }
}
