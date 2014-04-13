#include <iostream>
#include <algorithm>
using namespace std;

struct Level {
    int a,b;
    bool donea, doneb;
    Level() {}
    Level(int a, int b) : a(a), b(b), donea(false), doneb(false) {}
};

Level V[1000];

int main() {
    int T, t=0;
    cin >> T;
    while(t++<T) {
        int n; cin >> n;
        int stars = 0, completed = 0, tries=0;
        bool failed = false;
        for(int i=0; i<n; i++) {
            int a,b; cin >> a >> b;
            V[i] = Level(a,b);
        } 

        while(completed < n) {
            tries++;
            bool found = false;
            for(int i=0; i<n; i++) {
                if (V[i].b <= stars and not V[i].doneb) {
                    stars += V[i].donea ? 1 : 2;
                    V[i].donea = true;
                    V[i].doneb = true;
                    found = true;
              //      cout << i << " B" << endl;
                    completed += 1;
                    break;
                }
            }
            if (found) continue;
            
            int bmax = 0;
            int imax = -1;
            for(int i=0; i<n; i++) {
                if (V[i].a <= stars and not V[i].donea and V[i].b >= bmax) {
                    bmax = V[i].b;
                    imax = i;
                }
            }
            
            if (imax == -1) {
                failed = true;
                break;
            } 

           // cout << imax << " A" << endl;
            stars += 1;
            V[imax].donea = true;
        }        

        cout << "Case #" << t << ": ";
        if (failed) {
            cout << "Too Bad" << endl;
        } else {
            cout << tries << endl;
        }
    }
}
