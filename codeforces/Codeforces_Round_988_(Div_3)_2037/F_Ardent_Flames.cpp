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
	int n, m, k; cin >> n >> m >> k;
	vector<int> h(n), x(n); for(int& i : h) cin >> i;
	for(int& i : x) cin >> i;
	int lo = 1, hi = 1e9+1;
	while(lo < hi) {
		int mid = lo + ((hi-lo)>>1);
		vector<int> h2 = h;
		for(int &i : h2) i = (i/mid + bool(i%mid));
		vector<pair<int, int>> vl;
		for(int i = 0; i < n; i++) {
			if(h2[i] <= m) {
				vl.push_back({x[i] - (m - h2[i]), 1});
				vl.push_back({x[i] + (m - h2[i]) + 1, -1});
			}
		}

		sort(all(vl));
		int l = 0;
		int window = 0;
		bool ok = 0;
		while(l < sz(vl)) {
			int cur = vl[l].f;
			while(l < sz(vl) && vl[l].f == cur) {
				window += vl[l].s; l++;
			}
			if(window >= k) {ok = 1; break;}
		}
		if(ok) hi = mid;
		else lo = mid+1;
	}
	cout << ((lo==1e9+1)?-1:lo);
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