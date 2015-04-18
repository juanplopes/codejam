#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#define ull long long

#define I 2
#define J 3
#define K 4
using namespace std;

ull valueof(char c) {
    if (c=='i') return I;
    if (c=='j') return J;
    if (c=='k') return K;
    cerr << "ERROR0" << endl;
}

ull op(ull a, ull b) {
    ull sign = a*b>=0?1:-1;
    a = abs(a);
    b = abs(b);
    if (a==1) return sign*( 
        b==1? 1:
        b==I? I:
        b==J? J:
        b==K? K:((cerr << "ERROR1" << " " << b << endl), 0));
    if (a==I) return sign*(
        b==1? I:
        b==I?-1:
        b==J? K:
        b==K?-J:((cerr << "ERROR2" << endl), 0));
    if (a==J) return sign*( 
        b==1? J:
        b==I?-K:
        b==J?-1:
        b==K? I:((cerr << "ERROR3" << endl), 0));
    if (a==K) return sign*( 
        b==1? K:
        b==I? J:
        b==J?-I:
        b==K?-1:((cerr << "ERROR4" << endl), 0));
    cerr << "ERROR5" << endl;
    return 0;
}

ull value(string& s) {
    ull result = 1;
    for(ull i=0; i<s.size(); i++) {
        result = op(result, valueof(s[i]));
    }
    return result;
}

string name(ull value) {
    string s = value>=0?"":"-";
    value = abs(value);
    s += value == 1 ? "1" :
         value == I ? "i" :
         value == J ? "j" :
         value == K ? "k" : ((cerr << "ERROR6" << endl), "?");
    
    return s;
}

string repeat(string s, ull n) {
    ostringstream os;
    for (ull i = 0; i < n; i++) {
        os << s;
    }
    return os.str();
}

bool find(string& s) {
    ull ax = 1;
    for(ull i=0; i<s.size(); i++) {
        ax = op(ax, valueof(s[i]));
        if (ax != I) continue;

        ull bx = 1;
        for(ull j=i+1; j<s.size()-1; j++) {
            bx = op(bx, valueof(s[j]));
            if (bx == J) return true;
        }
    }
    return false;
}

ull powdd(ull value, ull power) {
    ull free = 1;
    while(power > 1) {
        if (power % 2 == 1)
            free = op(free, value);
        value = op(value, value);
        power /= 2;
    }
    return op(value, free);
}

int main() {
    ull test=0, tests; cin >> tests;

    ull L, X; string s;
    while(cin >> L >> X >> s) {
        cout << "Case #" << ++test << ": ";
        X = (X%4+4)%4;
        string q = repeat(s, X);
        if (value(q) != -1) {
            cout << "NO" << endl;
            continue;
        }

        cout << (find(q) ? "YES" : "NO") << endl;
    }
    
    
}
