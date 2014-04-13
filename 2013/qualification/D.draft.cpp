#include <iostream>
#include <cstring>
#define MAX 1000
using namespace std;

int K[MAX], CT[MAX], CN[MAX], CK[MAX][MAX], B[MAX], V[MAX], n;
int TK[MAX];

bool backtrack(int i) {
    if (i==n) {
        for(int j=0; j<n; j++)
            cout << " " << B[j]+1;
        return true;
    }
    for(int j=0; j<n; j++) {
        if (V[j] || K[CT[j]] <= 0) continue;

        for(int k=0; k<CN[j]; k++) K[CK[j][k]]++;
        K[CT[j]]--;
        V[j] = true;
        B[i] = j;

        if (backtrack(i+1))
            return true;

        for(int k=0; k<CN[j]; k++) K[CK[j][k]]--;
        K[CT[j]]++;
        V[j] = false;

    }
    return false;
}

bool impossible() {
    for(int i=0; i<MAX; i++) {
        if (TK[i] < 0)
            return true;
    }
    return false;
}

int main() {
    int cc=0, cases; 
    cin >> cases;
    while(cc++ < cases) {
        memset(K, 0, sizeof(K));
        memset(TK, 0, sizeof(TK));
        memset(V, 0, sizeof(V));
        int k;
        cin >> k >> n;
        for(int i=0; i<k; i++) {
            int temp; cin >> temp;
            K[temp]++;
            TK[temp]++;
        }

        for(int i=0; i<n; i++) {
            cin >> CT[i] >> CN[i];
            TK[CT[i]]--;
            for(int j=0; j<CN[i]; j++) {
                cin >> CK[i][j];
                TK[CK[i][j]]++;
            }    
        }
        
        cout << "Case #" << cc << ":";
        if (impossible() || !backtrack(0))
            cout << " IMPOSSIBLE";
        cout << endl;
    }
}
