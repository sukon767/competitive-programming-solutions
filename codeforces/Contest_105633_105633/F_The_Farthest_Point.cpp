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

const ld eps = 1e-12;
pair<Point<ld>, Point<ld>> ln(pair<ld, ld> L1, pair<ld, ld> L2) {
    auto [r1, s1] = L1;
    auto [r2, s2] = L2;

    if(abs(s2-s1) < eps) {
        ld c = (s2*s2 - s1*s1 + r2*r2 - r1*r1)/(2*(r1-r2));
        return {Point<ld>(c, 0), Point<ld>(c, 1)};
    }
    pair<Point<ld>, Point<ld>> ans;
    for(int i = 0; i < 2; i++) {
        ans.f = Point<ld>(i, (2*(r1 - r2)*i + r1*r1 - r2*r2 + s1*s1 - s2*s2)/(2*(s2 - s1)));
        swap(ans.f, ans.s);
    }
    return ans;
}

ld ans = 0;

void solve() {
    vector<int> s(3); cin >> s[0] >> s[1] >> s[2];
    for(int t = 0; t < 6; t++) {
        ld a = s[0], b = s[1], c = s[2];
        vector<pair<ld, ld>> cont;
        cont.push_back({a+b/2, c+a/2});
        cont.push_back({c+b/2, -a/2});
        cont.push_back({b/2, -c-a/2});
        cont.push_back({-c-b/2, -b-a/2});

        vector<pair<ld, ld>> pt;
        // vector<pair<ld, ld>> pt = {{b/2, a/2}, {b/2, -a/2}, {-b/2, a/2}, {-b/2, -a/2}};

        for(int i = 0; i < 4; i++) {
            for(int j = i+1; j < 4; j++) {
                for(int k = j+1; k < 4; k++) {
                    pair<Point<ld>, Point<ld>> c1 = ln(cont[i], cont[j]), c2 = ln(cont[j], cont[k]);
                    pair<int, Point<ld>> p = lineInter(c1.f, c1.s, c2.f, c2.s);
                    if(p.f == 1) {
                        pt.push_back({max((ld)-b/2, min(b/2, p.s.x)), max((ld)-a/2, min(a/2, p.s.y))});
                    }
                }
            }
        }

        auto solve = [&](ld x, ld y) {
            ld ans = INFINITY;
            for(auto &[r, s] : cont) {
                ans = min(ans, (x+r)*(x+r) + (y+s)*(y+s));
            }
            return ans;
        };

        for(auto &[x, y] : pt) {
            ans = max(ans, solve(x, y));
        }

        next_permutation(all(s));
    }

    cout << setprecision(20) << sqrtl(ans);
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