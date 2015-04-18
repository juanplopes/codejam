#include <iostream>
#include <string>
using namespace std;

int main() {
    int test=0, tests; cin >> tests;
    int a; string s;
    
    while(cin >> a >> s) {
        int sum = 0, total = 0;
        for(int i=0; i<s.size(); i++) {
            //cout << " " << i << " " << sum << endl;
            total += max(i-sum, 0);
            sum = max(sum, i);
            sum += s[i]-'0';
        }
        
        cout << "Case #" << ++test << ": " << total << endl;
    }
    
    
}
