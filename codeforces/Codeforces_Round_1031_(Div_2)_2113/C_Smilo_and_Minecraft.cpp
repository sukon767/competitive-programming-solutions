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
	int n, m, k; cin >> n >> m >> k; k--;
	vector<string> g(n); for(auto &s : g) cin >> s;
	vector<vector<int>> p(n, vector<int>(m));
	//2d prefix sums.
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(g[i][j] == 'g') p[i][j]++;
			if(i) p[i][j] += p[i-1][j];
			if(j) p[i][j] += p[i][j-1];
			if(i && j) p[i][j] -= p[i-1][j-1];
		}
	}
	
	int cnt = p.back().back();
	int ans = cnt;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(g[i][j] == '.') {
				int r2 = min(i+k, n-1), c2 = min(j+k, m-1);
				int r1 = max(i-k, 0), c1 = max(j-k, 0);
				// cout << "asdf" << endl;
				int cur = p[r2][c2];
				if(r1) cur -= p[r1-1][c2];
				if(c1) cur -= p[r2][c1-1];
				if(r1 && c1) cur += p[r1-1][c1-1];
				ans = min(ans, cur);
			}
		}
	}
	
	cout << cnt - ans;
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