#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define v4 array<ll, 4>

//sukon always reads the entire problem statement.
void solve() {
	int n; ll x; cin >> n >> x;
	vector<vector<pair<ll, ll>>> ab(n);
	for(auto &v : ab) {
		int m; cin >> m;
		v.resize(m);
		for(auto &p : v) cin >> p.f;
		for(auto &p : v) cin >> p.s, p.s-=p.f;
	}
	//budget, profit.
	priority_queue<v4, vector<v4>, greater<v4>> pq;
	//build the actual profit segments.
	vector<vector<v4>> cnd(n);
	for(int i = 0; i < n; i++) {
		pair<ll, ll> cur; //budget, profit.
		for(int j = 0; j < sz(ab[i]); j++) {
			// cout << i << " " << j << endl;
			cur = {max(cur.f, ab[i][j].f - cur.s), cur.s + ab[i][j].s};
			if(cur.s >= 0) {
				//budget, negative profit.
				cnd[i].push_back({cur.f, -cur.s, i, j+1});
				cur = {0, 0};
			}
		}
	}
	vector<int> cflr(n);
	for(int i = 0; i < n; i++) if(sz(cnd[i])) pq.push(cnd[i][0]);
	// cout << "asdf" << endl;
	while(sz(pq) && x >= pq.top()[0]) {
		auto pp = pq.top(); pq.pop();
		int i = pp[2];
		x -= pp[1];
		cflr[i]++;
		if(cflr[i] < sz(cnd[i])) pq.push(cnd[i][cflr[i]]);
	}

	pair<int, int> bst; //num floor, -project index
	for(int i = 0; i < n; i++) {
		ll t = x;
		int cf = cflr[i]?cnd[i][cflr[i]-1][3]:0;
		while(cf < sz(ab[i]) && t >= ab[i][cf].f) {
			t += ab[i][cf].s;
			cf++;
		}
		bst = max(bst, {cf, -i});
	}
	cout << bst.f << " " << -bst.s+1;
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