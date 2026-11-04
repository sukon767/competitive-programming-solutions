#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

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
vector<P> circleLine(P c, double r, P a, P b) {
	P ab = b - a, p = a + ab * (c-a).dot(ab) / ab.dist2();
	double s = a.cross(b, c), h2 = r*r - s*s / ab.dist2();
	if (h2 < 0) return {};
	if (h2 == 0) return {p};
	P h = ab.unit() * sqrt(h2);
	return {p - h, p + h};
}

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

struct Angle {
	int x, y;
	int t;
	Angle(int x, int y, int t=0) : x(x), y(y), t(t) {}
	Angle operator-(Angle b) const { return {x-b.x, y-b.y, t}; }
	int half() const {
		assert(x || y);
		return y < 0 || (y == 0 && x < 0);
	}
	Angle t90() const { return {-y, x, t + (half() && x >= 0)}; }
	Angle t180() const { return {-x, -y, t + half()}; }
	Angle t360() const { return {x, y, t + 1}; }
};
bool operator<(Angle a, Angle b) {
	// add a.dist2() and b.dist2() to also compare distances
	return make_tuple(a.t, a.half(), a.y * (ll)b.x) <
	       make_tuple(b.t, b.half(), a.x * (ll)b.y);
}

// Given two points, this calculates the smallest angle between
// them, i.e., the angle that covers the defined line segment.
pair<Angle, Angle> segmentAngles(Angle a, Angle b) {
	if (b < a) swap(a, b);
	return (b < a.t180() ?
	        make_pair(a, b) : make_pair(b, a.t360()));
}
Angle operator+(Angle a, Angle b) { // point a + vector b
	Angle r(a.x + b.x, a.y + b.y, a.t);
	if (a.t180() < r) r.t--;
	return r.t180() < a ? r.t360() : r;
}
Angle angleDiff(Angle a, Angle b) { // angle b - angle a
	int tu = b.t - a.t; a.t = b.t;
	return {a.x*b.x + a.y*b.y, a.x*b.y - a.y*b.x, tu - (b < a)};
}

double eps = 1e-8;

Point<double> Max(Point<double> O, Point<double> p1, Point<double> p2) {
    if((p2-O).cross(p1-O) >= -eps) return p2;
    else return p1;
}

Point<double> Max2(Point<double> d2, Point<double> p1, Point<double> p2) {
    if((p2-d2).dist2() - (p1-d2).dist2() <= eps) return p2;
    else return p1;
}

bool close(Point<double> p1, Point<double> p2) {
    return abs(p1.x - p2.x)<eps && abs(p1.y-p2.y)<eps;
}
int c = 0;

double solve(Point<double> p1, Point<double> p2, Point<double> p3, Point<double> p4, Point<double> p5) {
    int ty1 = 0, ty2 = 0;
    Point O = (p2+p4)/2.0;
    Point cl = p2, cr = p4;
    double r = (O-p2).dist();
    vector<Point<double>> L1 = circleLine(O, r, p1, p2), L2 = circleLine(O, r, p4, p5);
    
    auto cond = [&](auto& pt, auto& pt2) {
        return close(pt, pt2) || !(Max(O, pt, p4) == p4);
    };
    
    for(auto& pt : L1) {
        if(cond(pt, p2)) continue;
        // if(c==3) {
        //     cout << pt.x << " " << pt.y << endl;
        //     auto bb = Max(O, pt, cl);
        //     cout << bb.x << " " << bb.y << endl;
        // }
        if(!(cl == Max2(p4, pt, cl))) cl = pt;
    }
    for(auto& pt : L2) {
        if(cond(pt, p4)) continue;
        if(cr == Max2(p4, pt, cr)) cr = pt;
    }
    
    
    // if(c==2) {
    //     cout << "t1" << endl;
    //     for(auto& p : L1) cout << p.x << " " << p.y << endl;
    //     cout << "t2" << endl;
    //     for(auto& p : L2) cout << p.x << " " << p.y << endl;
    //     cout << "pts" << endl;
    //     cout << cl.x << " " << cl.y << endl;
    //     cout << cr.x << " " << cr.y << endl;
    // }

    Point rp1 = (p1-p2).perp()+p2, rp5 = (p5-p4).perp()+p4;
    L1 = circleLine(O, r, rp1, p2), L2 = circleLine(O, r, p4, rp5);
    
    for(auto& pt : L1) {
        if(cond(pt, p2)) continue;
        ty1 = 1;
        if(cr == Max2(p4, pt, cr)) cr = pt;
    }
    for(auto& pt : L2) {
        if(cond(pt, p4)) continue;
        ty2 = 1;
        if(!(cl == Max2(p4, pt, cl))) cl = pt;
    }
    
    double ans = 0;
    if(Max(O, cl, cr) == cr) {
        ans = max(ans, (p2-cl).dist()+(p4-cl).dist());
        ans = max(ans, (p2-cr).dist()+(p4-cr).dist());
        //check 90
        Point<double> mid = (p4-O).perp()+O;
        if(Max2(p4, cl, mid) == mid && Max2(p4, mid, cr) == cr) {
            ans = max(ans, (p2-mid).dist()+(p4-mid).dist());
        }
    } else if(ty1+ty2==0) {
        auto isc = lineInter(p1, p2, p4, p5);
        assert(isc.first==1);
        ans = max(ans, (p2-isc.second).dist()+(p4-isc.second).dist());
    }
    //  else assert(1==0);
    ans -= (p2-p3).dist()+(p4-p3).dist();

    // cout << c << " " << ans << endl;

    return max(ans, (double)0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    // int t = 1;

    int n; cin >> n;
    vector<Point<double>> pts(n);
    for(auto &p : pts) cin >> p.x >> p.y;
    
    double mx = 0;
    for(int i = 0; i < n; i++) {
        mx = max(mx, solve(pts[(i+2+n)%n], pts[(i+1+n)%n], pts[(i+n)%n], pts[(i-1+n)%n], pts[(i-2+n)%n]));
        c++;
    }
    cout << setprecision(20) << mx;
    // while(t--) {
    //     solve();
    //     if(t)   cout << "\n";
    // }
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