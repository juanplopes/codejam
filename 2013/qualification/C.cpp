#include <iostream>
#include <set>
#include <cmath>
#define ull unsigned long long
using namespace std;

set<ull> S;

ull make_it(int base, bool odd) {
    ull result = base;
    if (odd) base /= 10;
    while(base) {
        result *= 10;
        result += base%10;
        base/=10;
    }
    return result*result;
}

ull invert(ull n) {
    ull result = 0;
    while(n) {
        result *= 10;
        result += n%10;
        n /= 10;
    }  
    return result;
}
    
void add(int base, bool odd) {
    ull n = make_it(base, odd);
    if (n==invert(n)) {
        S.insert(n);
    }
}

int main() {
    for(int i=1; i<1000000; i++) {
        add(i, false);
        add(i, true);
    }

    int cc=0, cases; 
    cin >> cases;
    while(cc++ < cases) {
        ull a, b;
        cin >> a >> b;
        
        set<ull>::iterator begin = S.lower_bound(a);
        set<ull>::iterator end = S.upper_bound(b);
    
        int count = 0;
        for (; begin!=end; ++begin) {
            count++;
        }
        
        cout << "Case #" << cc << ": " << count << endl;
    }
}
