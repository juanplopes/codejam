#include <iostream>
#include <cstring>
using namespace std;

int T[60][60];
int R, C, M;

bool check(int x, int y) {
    if (x<0 || x>=R || y<0 || y>=C) return 0;
    return T[x][y] == 1 ? 1 : 0;
}

int touch(int x, int y) {
    if (x<0 || x>=R || y<0 || y>=C) return 0;
    if (T[x][y] != 0) return 0;

    T[x][y] = 2;
    
    int sum = 0;
    sum += check(x-1, y-1);
    sum += check(x-1, y);
    sum += check(x-1, y+1);
    sum += check(x, y-1);
    sum += check(x, y+1);
    sum += check(x+1, y-1);
    sum += check(x+1, y);
    sum += check(x+1, y+1);

    int touched = 1;
    
    if (sum == 0) {
        touched += touch(x-1, y-1);
        touched += touch(x-1, y);
        touched += touch(x-1, y+1);
        touched += touch(x, y-1);
        touched += touch(x, y+1);
        touched += touch(x+1, y-1);
        touched += touch(x+1, y);
        touched += touch(x+1, y+1); 
    }
    
    return touched;
}

bool try1(int k) {
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if (T[i][j] == 1) 
                continue;

            if (k-- > 0)
                T[i][j] = 1;
        }
    }
    if (k > 0) return false;
    return true;
}

bool try2(int k) {
    for(int j=0; j<C; j++) {
        for(int i=0; i<R; i++) {
            if (T[i][j] == 1) 
                continue;

            if (k-- > 0)
                T[i][j] = 1;
        }
    }
    if (k > 0) return false;
    return true;
}

int main() {
    int tests; cin >> tests;
    for(int test = 1; test<=tests; test++) {
        cin >> R >> C >> M;

        cout << "Case #" << test << ":" << endl;

        bool possible = M == 0;

        memset(T, 0, sizeof T);

        int F = R*C-M;
        for(int k=0; !possible && k<M; k++) {
            memset(T, 0, sizeof T);
            if (try1(k) && try2(M-k) && touch(R-1, C-1) == F)
                possible = true;
        }
        for(int k=0; !possible && k<M; k++) {
            memset(T, 0, sizeof T);
            if (try2(k) && try1(M-k) && touch(R-1, C-1) == F)
                possible = true;
        }

        if (!possible) {
            cout << "Impossible" << endl;
        } else {
            for(int i=0; i<R; i++) {
                for(int j=0; j<C; j++) {
                    cout << (T[i][j] == 1 ? '*' : i==R-1 && j==C-1 ? 'c' : '.');
                }
                cout << endl;
            }
       }
 
    }
}
