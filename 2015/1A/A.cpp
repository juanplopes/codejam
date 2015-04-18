#include <iostream>
using namespace std;

int T[10010];

int main() {
    int test=0, tests; cin >> tests;
    int N;
    while(cin >> N) {
        for(int i=0; i<N; i++)
            cin >> T[i];

        int MD = 0;
        int A1 = 0;
        for(int i=1; i<N; i++) {
            A1 += max(T[i-1]-T[i], 0);
            MD = max(MD, T[i-1]-T[i]);
        }

        int A2 = 0;
        for(int i=0; i<N-1; i++) {
            A2 += min(T[i], MD);
        }        

        cout << "Case #" << ++test << ": " << A1 << " " << A2 << endl;
    }
}
