#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

priority_queue<int> Q, T;
int main() {
    int test=0, tests; cin >> tests;

    int D;   
    while(cin >> D) {
        Q = priority_queue<int>();
        for(int i=0; i<D; i++) {
            int temp; cin >> temp;
            Q.push(temp);        
        }
        
        int best = Q.top();
        for(int target=1; target<=Q.top(); target++) {
            //cerr << " " << target << " " << Q.top() << endl;
            T = Q;
            int steps = 0;
            while(T.top() > target) {
                int top = T.top(); T.pop();
                T.push(target);
                T.push(top-target);
                steps++;
                if (T.top() + steps < best) {
                    cout << " " << T.top() << " " << steps << " " << target << endl;
                }
                
                best = min(best, T.top()+steps);
            }
        }
        cout << "Case #" << ++test << ": " << best << endl;
    }
    
    
}
