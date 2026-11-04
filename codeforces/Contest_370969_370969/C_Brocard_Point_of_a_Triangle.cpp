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

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

void solve(int tc) {
    vector<Point<double>> pt(3);
    for(auto& p : pt) cin >> p.x >> p.y;

    double lo = 0;
    double hi = 180;
    Point<double> ans(0, 0);
    double eps = 1e-12;
    while(abs(lo-hi) > eps) {
        double m = (lo+hi)/2;
        vector<Point<double>> rot(3);
        bool ok = 1;
        for(int i = 0; i < 3; i++) {
            rot[i] = (pt[(i+1)%3] - pt[i]).rotate(m) + pt[i];
            if((pt[(i+2)%3]-pt[i]).cross(rot[i]-pt[i]) > 0) {
                ok = 0; break;
            }
        }

        Point i1 = lineInter(pt[0], rot[0], pt[2], rot[2]).s;
        Point i2 = lineInter(pt[1], rot[1], pt[2], rot[2]).s;
        if((i1-pt[2]).dist2() < (i2-pt[2]).dist2()) ok = 0;
        ans = i1;

        if(ok) lo = m;
        else hi = m;
    }

    cout << fixed << setprecision(5) << tc << " " << ans.x << " " << ans.y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        int tc; cin >> tc;
        solve(tc);
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