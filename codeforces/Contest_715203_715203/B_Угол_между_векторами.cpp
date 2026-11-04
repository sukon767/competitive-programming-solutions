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
    freopen("angle2.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("angle2.out", "w", stdout);
    ll x, y; cin >> x >> y;
    ld c = atan2(ld(y), ld(x));
    if(c < 0) c += 2*pi;
    ll x2, y2; cin >> x2 >> y2;
    ld c2 = atan2(ld(y2), ld(x2));
    if(c2 < 0) c2 += 2*pi;

    ld d = c2-c;
    if(d < 0) d += 2*pi;
    cout << setprecision(20) << min(d, 2*pi-d);
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