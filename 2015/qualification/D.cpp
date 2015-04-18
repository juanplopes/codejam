#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int test=0, tests; cin >> tests;

    int X, R, C;
    while(cin >> X >> R >> C) {
        cout << "Case #" << ++test << ": " << (X>max(R, C) or (int)sqrt(X)>min(R, C) or R*C%X!=0 or (X>2 and X>=2*min(R, C)) ? "RICHARD" : "GABRIEL") << endl;
    }
}
