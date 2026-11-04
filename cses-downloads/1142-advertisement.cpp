#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
ll slv(vector<int> a) {
    int n = sz(a);
    vector<pair<int, int>> ivl(n);
	vector<int> stk;
	for(int i = 0; i < n; i++) {
		while(sz(stk) && a[i] < a[stk.back()]) {
			ivl[stk.back()].s = i-1;
			stk.pop_back();
		}
		stk.push_back(i);
	}
	while(sz(stk)) {
		ivl[stk.back()].s = n-1;
		stk.pop_back();
	}
	for(int i = n-1; i >= 0; i--) {
		while(sz(stk) && a[i] < a[stk.back()]) {
			ivl[stk.back()].f = i+1;
			stk.pop_back();
		}
		stk.push_back(i);
	}
    ll ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, ll(a[i])*(ivl[i].s - ivl[i].f + 1));
    return ans;
}
//sukon always reads the entire problem statement.
void solve() {
	int n; cin >> n;
	vector<int> a(n); for(int& i : a) cin >> i;
	cout << slv(a);
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
