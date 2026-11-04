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
    freopen("area1.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("area1.out", "w", stdout);

    int n;
    n = 3;
    // cin >> n;
    vector<pair<ll, ll>> pts(3);
    for(auto &p : pts) cin >> p.f >> p.s;

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += pts[i].f*pts[(i+1)%n].s-pts[i].s*pts[(i+1)%n].f;
    }

    cout << setprecision(20) << abs(ans)/2.0;
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