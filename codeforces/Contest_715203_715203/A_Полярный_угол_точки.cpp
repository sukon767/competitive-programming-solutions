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
    freopen("angle1.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("angle1.out", "w", stdout);
    ll x, y; cin >> x >> y;
    ld c = atan2(ld(y), ld(x));
    if(c < 0) c += 2*pi;
    cout << setprecision(20) << c;
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