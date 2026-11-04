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
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; i++) {
		int pu; cin >> pu;
		adj[--pu].push_back(i);
	}
	int m; cin >> m;
	vector<bool> a(n);
	for(int i = 0; i < m; i++) {
		int x; cin >> x;
		a[--x] = 1;
	}

	bool ok = 0;
	int c = 0;
	//find a special node with no special parents. just dfs
	auto dfs = [&](auto &&self, int x) -> void {
		if(ok) return;
		if(a[x]) {
			a[x] = 0;
			ok = 1;
			c++;
			return;
		}
		for(int y : adj[x]) {
			self(self, y);
		}
	};

	dfs(dfs, 0);
	assert(c == 1);

	cout << m-1 << " ";
	for(int i = 0; i < n; i++) if(a[i]) cout << i+1 << " ";
	
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