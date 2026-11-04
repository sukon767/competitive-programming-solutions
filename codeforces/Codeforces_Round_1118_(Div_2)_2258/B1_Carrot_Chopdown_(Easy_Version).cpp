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
	int n, m; cin >> n >> m;
	// vector<int> a(n); for(int & i : a) cin >> i;
	vector<int> f(m+1);
	for(int i = 0; i < n; i++) {
		int x; cin >> x; f[x]++;
	}
	vector<int> suf = f;
	reverse(all(suf)); partial_sum(all(suf), suf.begin()); reverse(all(suf));
	int ans = 0;
	for(int i = m; i >= 1; i--) {
		ans = max(ans, suf[i] + (2*i <= m ? f[2*i] : 0));
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