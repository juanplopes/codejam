#include <iostream>
#define ull long long
using namespace std;

struct Point {
    ull x, y;
};

Point P[10000];

inline ull sign(Point a, Point b, Point c) {
    return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x));
}

int main() {
    int test=0, tests; cin >> tests;
    int N;

    while(cin >> N) {
        for(int i=0; i<N; i++) {
            cin >> P[i].x >> P[i].y;
        }
       
        cout << "Case #" << ++test << ":" << endl;
        for(int i=0; i<N; i++) { 
            cerr << " " << test << " " << i << "/" << N << endl;
            
            int answer = N-1;
            for(int j=0; j<N; j++) {
                if (i==j) continue;
                int left=0;
                for(int k=0; k<N; k++) {
                    if (k==i or k==j) continue;
                    if (sign(P[i], P[j], P[k])<0) left++;
                }
                answer = min(answer, left);
            }
            cout << answer << endl;
        }
    }
}
