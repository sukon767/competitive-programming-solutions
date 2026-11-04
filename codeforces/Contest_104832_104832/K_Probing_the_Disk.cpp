#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<double> P;
double ccRadius(P A, P B, P C) {
	return (B-A).dist()*(C-B).dist()*(A-C).dist()/
			abs((B-A).cross(C-A))/2;
}
P ccCenter(P A, P B, P C) {
	P b = C-A, c = B-A;
	return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}

void solve() {
    const int N = 1e5;
    const int d = 199;

    int r;
    int x, y;
    for(int i = d; i <= N; i+=d) {
        cout << "query " << i << " " << 0 << " " << i << " " << N << endl;
        double c; cin >> c;
        if(c != 0) {
            if(i != 0) {
                cout << "query " << i-1 << " " << 0 << " " << i-1 << " " << N << endl;
                double c2; cin >> c2;
                if(c2 != 0) {
                    c/=2; c2/=2;
                    x = round(ccCenter(Point<double>(i, -c), Point<double>(i, c), Point<double>(i-1, c2)).x);
                    r = round(ccRadius(Point<double>(i, -c), Point<double>(i, c), Point<double>(i-1, c2)));
                    // cout << x << endl;
                    // cout << r << endl;
                    break;
                }
            }

            cout << "query " << i+1 << " " << 0 << " " << i+1 << " " << N << endl;
            double c2; cin >> c2;
            assert(c2 != 0);
            c/=2; c2/=2;
            x = round(ccCenter(Point<double>(i, -c), Point<double>(i, c), Point<double>(i+1, c2)).x);
            r = round(ccRadius(Point<double>(i, -c), Point<double>(i, c), Point<double>(i+1, c2)));
            break;
        }
    }

    //y
    for(int i = d; i <= N; i+=d) {
        cout << "query " << 0 << " " << i << " " << N << " " << i << endl;
        double c; cin >> c;
        if(c != 0) {
            if(i != 0) {
                cout << "query " << 0 << " " << i-1 << " " << N << " " << i-1 << endl;
                double c2; cin >> c2;
                if(c2 != 0) {
                    //iknow it looks sus but
                    c/=2; c2/=2;
                    y = round(ccCenter(Point<double>(i, -c), Point<double>(i, c), Point<double>(i-1, c2)).x);
                    break;
                }
            }

            cout << "query " << 0 << " " << i+1 << " " << N << " " << i+1 << endl;
            double c2; cin >> c2;
            assert(c2 != 0);
            //iknow it looks sus but
            c/=2; c2/=2;
            y = round(ccCenter(Point<double>(i, -c), Point<double>(i, c), Point<double>(i+1, c2)).x);
            break;
        }
    }
    
    cout << "answer " << x << " " << y << " " << r << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

 /* new testament
 * nick belov always reads the entire problem statement.
 */