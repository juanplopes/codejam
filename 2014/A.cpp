#include <iostream>
#include <set>
using namespace std;

set<int> P;

int main() {
    int tests; cin >> tests;
    for(int test = 1; test<=tests; test++) {
        P.clear();
        int row;
        cin >> row;
        for(int i=1; i<=4; i++) {
            for(int j=1; j<=4; j++) {
                int temp; cin >> temp;
                if (i==row) P.insert(temp);
            } 
        }
        cin >> row;
        for(int i=1; i<=4; i++) {
            for(int j=1; j<=4; j++) {
                int temp; cin >> temp;
                if (i!=row) P.erase(temp);
            } 
        }
        
        cout << "Case #" << test << ": ";
        if (P.size() == 1) {
            cout << *P.begin() << endl;
        } else if (P.size() == 0) {
            cout << "Volunteer cheated!" << endl;
        } else {
            cout << "Bad magician!" << endl;
        }
    }
}
