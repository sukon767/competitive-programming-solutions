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
	ll k, a, b, x, y; cin >> k >> a >> b >> x >> y;
	if(x > y) {
		swap(x, y); swap(a, b);
	}
	ll ans = k>=a ? (k-a)/x + 1 : 0;
	k -= ans*x;
	ans += k>=b ? (k-b)/y + 1 : 0;
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