#include <iostream>
#include <string>
#include <cstring>
#define ull unsigned long long
using namespace std;

bool consoant(char c) {
    return c!='a' && c!='e' && c!='i' && c!='o' && c!='u';
}

int main() {
    int cc=0, cases; 
    cin >> cases;
    while(cc++ < cases) {
        string s; int n;
        cin >> s >> n;
        
        int count = 0;
        int last = -1;
        ull result = 0;
        for(int i=0; i<s.size(); i++) {
            char c = s[i];
            if (consoant(c)) {
                count++;
            } else {
                count = 0;
            }
            
            if (count >= n) {
                int begin = i-n+1;
                
                result += (begin - last) * (s.size() - i);

                last = begin;
            }
        }
        
        
        cout << "Case #" << cc << ": " << result << endl;
    }
}
