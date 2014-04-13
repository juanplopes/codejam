#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#define PI 3.14159265
using namespace std;

struct Ray {

    double x,y,mx,my,d;
    Ray(double x, double y, double mx, double my, double d) : x(x), y(y), mx(mx), my(my), d(d) { }

    bool isValid(double h, double w, double d) {
        return x >= 0 and x <= w and x >= 0 and y <= h and this->d <= d;
    }
    
    Ray crossX(double ox, double h, double w) {
        if (mx == 0) return Ray(-1000, -1000, 0, 0, 0);
        double t = (ox-x)/mx;
        if (t<0) return Ray(-1000, -1000, 0, 0, 0);
        double oy = y+my*t;
        if (eq(ox, x) and eq(oy, y)) return Ray(-1000, -1000, 0, 0, 0);
        if (eq(oy, h) or eq(oy, 0))
            return Ray(ox, oy, -mx, -my, distance(ox, oy));
        else
            return Ray(ox, oy, -mx, my, distance(ox, oy));
    }
    
    Ray crossY(double oy, double h, double w) {
        if (my == 0) return Ray(-1000, -1000, 0, 0, 0);
        double t = (oy-y)/my;
        if (t<0) return Ray(-1000, -1000, 0, 0, 0);
        double ox = x+mx*t;
        if (eq(ox, x) and eq(oy, y)) return Ray(-1000, -1000, 0, 0, 0);
        if (eq(ox, w) or eq(ox, 0))
            return Ray(-1000, -1000, 0, 0, 0);
        else
            return Ray(ox, oy, mx, -my, distance(ox, oy));
    }

    bool eq(double a, double b) {
        return abs(a-b) < 0.000001;
    }
    
    bool meets(double ox, double oy) {
        if (eq(ox, x) and eq(oy, y)) return false;
        double tx = (ox-x)/mx;
        double ty = (oy-y)/my;
        return ((eq(my, 0) and eq(oy, y) and tx > 0.0001) or
               (eq(mx, 0) and eq(ox, x) and ty > 0.0001) or
               eq(tx, ty));
    }
    
    double distance(double ox, double oy) {
        return d+pow(pow(ox-x, 2.0)+pow(oy-y, 2.0), 0.5);
    }
    
    void trace(double h, double w, double d) {
        cout << x << " " << y << " " << mx << " " << my << " " << this->d << " " << isValid(h, w, d) << endl;
    }
};

stack<Ray> Q;

int main() {
    int T, t=0;
    cin >> T;
    
    while(t++<T) {
        int h, w, d; char c;
        double sh, sw;
        cin >> h >> w >> d;
        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                cin >> c;
                if (c=='X') {
                    sh = i-0.5;
                    sw = j-0.5;
                }
            }
        }
        h-=2; w-=2;

        Q = stack<Ray>();
        for(double i=-1; i<=1; i+=0.01) {
            for(double j=-1; j<=1; j+=0.01) {
                Q.push(Ray(sw, sh, i, j, 0));
            }
        }

        int answer = 0;
        while(!Q.empty()) {
            Ray ray = Q.top(); Q.pop();
            if (!ray.isValid(h, w, d)) continue;
           // ray.trace(h, w, d);
            
            if (ray.meets(sw, sh)) {
                if (ray.distance(sw, sh) > d) continue;
                answer++;
            } else {
                Ray r1 = ray.crossX(0, h, w);
                Ray r2 = ray.crossX(w, h, w);
                Ray r3 = ray.crossY(0, h, w);
                Ray r4 = ray.crossY(h, h, w);
                int test = r1.isValid(h, w, d) + r2.isValid(h, w, d) + r3.isValid(h, w, d) + r4.isValid(h, w, d);
                if (test > 1) ray.trace(h, w, d);
                Q.push(r1);
                Q.push(r2);
                Q.push(r3);
                Q.push(r4);
            }
        }
       
        cout << "Case #" << t << ": " << answer << endl;
    }
}
