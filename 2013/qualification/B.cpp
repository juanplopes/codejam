#include <iostream>
#include <cstring>
#define MAX 200
using namespace std;

int T[MAX][MAX], R[MAX], C[MAX];

int main() {
    int cc=0, cases; cin >> cases;
    while(cc++ < cases) {
        memset(R, 0, sizeof(R));
        memset(C, 0, sizeof(C));
        
        int n, m; 
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> T[i][j];
                R[i] = max(R[i], T[i][j]);
                C[j] = max(C[j], T[i][j]);
            }
        }

        bool possible = true;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                possible &= T[i][j] >= R[i] || T[i][j] >= C[j];
            
    
        cout << "Case #" << cc << ": " << (possible?"YES": "NO") << endl;
    }
}
