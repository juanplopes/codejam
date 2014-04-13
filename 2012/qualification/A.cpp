#include <iostream>
#include <string>
using namespace std;

string map = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
    int T, t=0;
    string s, s2;
    cin >> T;
    getline(cin, s);
    while(t++<T) {
        cout << "Case #" << t << ": ";
        getline(cin, s);
        for(int i=0; i<s.size(); i++) {
            if (s[i] == ' ') { cout << ' '; continue; }
            cout << map[s[i]-'a'];
        }
        cout << endl;
    }
}
