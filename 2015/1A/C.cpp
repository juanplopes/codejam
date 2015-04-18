#include <iostream>
#include <algorithm>
#define ull long long
using namespace std;

struct Point {
    ull x, y;
    int i, a;
    Point() { }
    
    inline bool operator<(const Point& b) const {
        return x!=b.x ? x<b.x : y<b.y;
    }
};

Point P[10000];
int H[10000];
int hull;

inline bool byI(const Point& a, const Point& b) {
    return a.i < b.i;
}


Point m(int i) {
    return P[H[hull-i]];
}

ull sign(Point a, Point b, Point c) {
    return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x));
}

bool isLeft(Point a, Point b, Point c) {
    return sign(a, b, c) > 0;
}

bool isRight(Point a, Point b, Point c) {
    return sign(a, b, c) < 0;
}

bool makeHull(int N) {
    hull = 0;
    for(int i=0; i<N; i++) {
        while(hull >= 2 && isLeft(m(1), m(2), P[i])) hull--;
        H[hull++] = i;
    }
    hull--;
    
    for(int i=N-1, k=hull; i>=0; i--) {
        while(hull >= k+2 && isLeft(m(1), m(2), P[i])) hull--;
        H[hull++] = i;
    }
    hull--;
}

int main() {
    int test=0, tests; cin >> tests;
    int N;


    while(cin >> N) {
        for(int i=0; i<N; i++) {
            cin >> P[i].x >> P[i].y;
            P[i].i = i;
            P[i].a = N-1;
        }
        sort(P, P+N);
        makeHull(N);
       
        for(int i=0; i<N; i++) { 
            cerr << " " << test+1 << " " << i << "/" << N << endl;
            for(int j=0; j<N; j++) {
                if (i==j) continue;
                int left=0, right=0;
                for(int k=0; k<N; k++) {
                    if (k==i or k==j) continue;
                    if (isLeft(P[i], P[j], P[k])) left++;
                    if (isRight(P[i], P[j], P[k])) right++;
                }
                P[i].a = min(P[i].a, min(left, right));
            }
        }

        sort(P, P+N, byI);
        
        cout << "Case #" << ++test << ":" << endl;
        for(int i=0; i<N; i++) { 
            cout << P[i].a << endl;
        }       
    }
}
