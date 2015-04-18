#include <iostream>
#define ull unsigned long long
using namespace std;

ull T[10010];

ull customersFor(int B, ull minutes) {
    ull customers = 0;
    for(int i=0; i<B; i++)
        customers += minutes/T[i]+1;
    return customers;
}

ull minutes(int B, ull N) {
    ull first = 0, count = 1ull<<63, step;
    while (count>0) {
        ull it = first; step=count/2; it+=step;
        //cerr << " -> " << it << " " << customersFor(B, it) << endl;
        if (customersFor(B, it)<N) {
            first=++it;
            count-=step+1;
        }
        else count=step;
    }
   // cerr << " -> 2 " << first << " " << customersFor(B, first) << endl;
    return first;
}

int main() {
    int test=0, tests; cin >> tests;
    int B, N;
    while(cin >> B >> N) {
        for(int i=0; i<B; i++)
            cin >> T[i];

        ull RA = minutes(B, N);
        //cerr << " -- " << RA << endl;
        ull RB = customersFor(B, RA-1);
        if (N<=RB) cerr << "ERROR! " << test << " " << N << " " << RA << " " << RB << endl;
        
        RB = N-RB;
        int answer;
        for(int i=0; i<B; i++) {
            if (RA%T[i]==0 and --RB == 0) {
                answer = i+1;
                break;
            }
        }
        
        cout << "Case #" << ++test << ": " << answer << endl;
    }
}
