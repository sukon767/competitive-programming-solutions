#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
	vector<ll> z(3); for(ll& i : z) cin >> i;
	sort(all(z));
	ll ans = z[2] - z[0];
	for(int i = 0; i < 3; i++) {
		rotate(z.begin(), z.begin()+1, z.end());
		ans = min(ans, z[1]+z[2] - min(z[1], z[2]));
	}
	cout << ans;
}

//king of the sun o_O
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	//int t = 1;
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