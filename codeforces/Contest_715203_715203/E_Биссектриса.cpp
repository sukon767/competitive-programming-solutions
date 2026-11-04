#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

const ld pi = acosl(-1.0L);


//sukon always reads the entire problem statement.
void solve() {
    freopen("bisector.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("bisector.out", "w", stdout);

    ll x, y;
    ll x1, y1, x2, y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    x1 -= x, x2 -= x;
    y1 -= y, y2 -= y;

    pair<ld, ld> pt1, pt2;
    pt1 = {ld(x1)/sqrtl(x1*x1 + y1*y1), ld(y1)/sqrtl(x1*x1 + y1*y1)};
    pt2 = {ld(x2)/sqrtl(x2*x2 + y2*y2), ld(y2)/sqrtl(x2*x2 + y2*y2)};
    

    pair<ld, ld> pt3 = {(pt1.f+pt2.f)/2, (pt1.s+pt2.s)/2};
    // cout << pt1.f << " " << pt1.s << " " << pt2.f << " " << pt2.s << endl;
    const ld eps = 1e-12;
    if(abs(pt3.f) < eps && abs(pt3.s) < eps) {
        //then we need to do the bullshit
        pt3 = {-y1, x1};
    }
    // cout << pt3.f << " " << pt3.s << endl;

    //pt3.s*(x - xa) - pt3.f*(y - xb) = 0;
    //pt3.s*x - pt3.f*y - xa*pt3.s + ya*pt3.f = 0;
    ld A = pt3.s, B = -pt3.f, C = -x*pt3.s + y*pt3.f;
    cout << setprecision(20) << A << " " << B << " " << C;
}

//king of the sun o_O
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