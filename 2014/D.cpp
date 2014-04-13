#include <iostream>
#include <algorithm>
using namespace std;

double N[2000], K[2000];

int main() {
    int tests; cin >> tests;
    for(int test = 1; test<=tests; test++) {
        int n;
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> N[i];
        for(int i=0; i<n; i++)
            cin >> K[i];
        
        sort(N, N+n);
        sort(K, K+n);

        int Y=0, Z=0;
        for(int i=0, j=0; i<n; i++) {
            if (N[i] > K[j]) {
                Y++;
                j++;
            } 
        }
        
        for(int i=0, j=0; j<n; j++) {
            if (N[i] > K[j]) {
                Z++;
            } else {
                i++;
            }
        }

       
        cout << "Case #" << test << ": " << Y << " " << Z << endl;

        
    }
}
