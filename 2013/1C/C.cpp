#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#define ull long long
using namespace std;

struct Node { 
    int a;
    Node* left;
    Node* right;

    Node(int a) : a(a), left(NULL), right(NULL) { }

    Node change(int v) {
        a = max(a, v);
        return *this;
    }
    
    void what() {
        this->a = min(left->a, right->a);
    }
};

struct Segtree {
    Node* top;

    Segtree() {
        clear();
    }
    
    void clear() {
        top = new Node(0);
    }
    
    
    int update(Node* v, ull a, ull b, ull i, ull j, int up) {
        if (a>b) return 1e9;
        if (i>b || j<a) return 1e9;

        if (i<=a && b<=j) {
            v->change(up);
            return v->a;
        }
        if (v->left == NULL) v->left = new Node(0);
        if (v->right == NULL) v->right = new Node(0);
        
//        cout << " " << a << " " << b << " " << i << " " << j << endl;
        int answer = min(
            update(v->left, a, (a+b)/2, i, j, max(v->a, up)), 
            update(v->right, (a+b)/2+1, b, i, j, max(v->a, up)));
        
        v->what();
        
        return answer;
    }

    int update(ull i, ull j, int up) {
        return update(top, -(1<<20), (1<<20)-1, i, j, up);
    }

    int query(ull i, ull j) {
        return update(top, -(1<<20), (1<<20)-1, i, j, 0);
    }

};

struct Attack {
    ull d, n, w, e, s, dd, dp, ds;
        
    inline bool operator<(const Attack& o) const {
        return d>o.d;
    }
    
    Attack next() {
        Attack o = *this;
        o.d += dd;
        o.n -= 1;
        o.w += dp;
        o.e += dp;
        o.s += ds;
        return o;
    }
};

priority_queue<Attack> Q;
queue<Attack> T;
Segtree W;

bool attack(Attack a) {
    cout << " Q===>> " << a.d << " " << a.s << " " << W.query(a.w, a.e) << endl;
    return W.query(a.w, a.e) < a.s;
}

void build(Attack a) {
    //cout << " B===>> " << a.d << " " << W.update(a.w, a.e, a.s) << endl;
    cout << "---" << endl;
    W.update(a.w, a.e, a.s);
}

int main() {
    int cc=0, cases; 
    cin >> cases;
    while(cc++ < cases) {
        int n; cin >> n;
        W.clear();
        for(int i=0; i<n; i++) {
            Attack a;
            cin >> a.d >> a.n >> a.w >> a.e >> a.s >> a.dd >> a.dp >> a.ds;
            a.w *= 2;
            a.e *= 2;
            a.dp *= 2;
            
            Q.push(a);
        }
        
        int answer = 0;
        while(Q.size()) {
            Attack a = Q.top(); Q.pop();
            T.push(a);
            if (attack(a)) answer++;

            while(Q.size() && Q.top().d == a.d) {
                a = Q.top(); Q.pop();
                T.push(a);
                if (attack(a)) answer++;
            }
            
            while(T.size()) {
                Attack a = T.front(); T.pop();
                build(a);
                Attack o = a.next();
                if (o.n > 0)
                    Q.push(o);
            }
        }
        
        cout << "Case #" << cc << ": " << answer << endl;
    }
}
