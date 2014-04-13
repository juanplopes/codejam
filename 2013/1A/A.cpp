#include <iostream>
#include <string>
#include <cstring>
#define PI 3.14159265359
#define ull unsigned long long
using namespace std;

int main() {
    int cc=0, cases; 
    cin >> cases;
    while(cc++ < cases) {
        ull r, t;
        cin >> r >> t;
        int answer = 0;

        ull available = t;        
        while(true) {
            ull needed = 2*r+1;
            cout << " " << available << " " << (ull)needed << endl;
            if (available<needed) break;

            r += 2;
            available -= needed;
            answer++;
        }
        
        
        cout << "Case #" << cc << ": " << (ull)answer << endl;
    }
}
