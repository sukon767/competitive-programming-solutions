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
    freopen("distance1.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("distance1.out", "w", stdout);

    ll x, y;
    ll a, b, c; cin >> x >> y >> a >> b >> c;

    ld ans = (a*x + b*y + c)/sqrtl(a*a + b*b);
    cout << setprecision(20) << abs(ans);
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