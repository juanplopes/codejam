#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int T, t=0;
    cin >> T;
    while(t++<T) {
        int n, s, p;
        cin >> n >> s >> p;
        
        int ra=0, rb=0;
        for(int i=0; i<n; i++) {
            int t; cin >> t;
            int value = (t/3) + (t%3==0?0:1);
            if (value >= p)
                ra++;
            else if (p-(t-p)/2 <= 2 && t>=2)
                rb++;
        }
        cout << "Case #" << t << ": " << ra+min(rb,s) << endl;
    }
}
