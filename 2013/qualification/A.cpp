#include <iostream>
#include <string>
#include <cstring>
#define MAX 3000
using namespace std;

int R[4][MAX], C[4][MAX], D1[4], D2[4];

int id(char type) {
    if (type == 'X')
        return 0;
    if (type == 'O')
        return 1;
    if (type == 'T')
        return 2;
    if (type == '.')
        return 3;
}

int main() {
    int cc=0, cases; 
    cin >> cases;
    string s;
    while(cc++ < cases) {
        memset(R, 0, sizeof(R));
        memset(C, 0, sizeof(C));
        memset(D1, 0, sizeof(D1));
        memset(D2, 0, sizeof(D2));
        for(int i=0; i<4; i++) {
            cin >> s;
            for(int j=0; j<4; j++) {
                char c = s[j];
                R[id(c)][i]++;
                C[id(c)][j]++;
                if (i-j==0)
                    D1[id(c)]++;
                if (i+j==3)
                    D2[id(c)]++;
            }
        }
        bool wO=D1[id('O')]+D1[id('T')]==4 || D2[id('O')]+D2[id('T')]==4;
        bool wX=D1[id('X')]+D1[id('T')]==4 || D2[id('X')]+D2[id('T')]==4;
        bool wFull=true;
        for(int i=0; i<4; i++) {
            wO |= R[id('O')][i]+R[id('T')][i] == 4 || C[id('O')][i]+C[id('T')][i] == 4;
            wX |= R[id('X')][i]+R[id('T')][i] == 4 || C[id('X')][i]+C[id('T')][i] == 4;
            wFull &= R[id('.')][i] == 0;
        }

        cout << "Case #" << cc << ": ";
        if (wO)
            cout << "O won" << endl;
        else if (wX)
            cout << "X won" << endl;
        else if (wFull)
            cout << "Draw" << endl;
        else
            cout << "Game has not completed" << endl;
    }
}
