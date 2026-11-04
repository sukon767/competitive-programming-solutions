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
	//say n is even.
	//k <= n*(m//2).
	//trivial

	int n, m, k; cin >> n >> m >> k;
	if(k > n*(m/2)) {cout << "NO\n"; return;}
	vector<vector<int>> ans(n, vector<int>(m));
	auto check = [&](int i, int j, int v) {
		for(int r = -1; r <= 1; r++) {
			for(int s = -1; s <= 1; s++) {
				if(r == 0 && s == 0) continue;
				if(i+r < 0 || i+r >= n || j+s < 0 || j+s >= m) continue;
				if(ans[i+r][j+s] == v) return 1;
			}
		}
		return 0;
	};
	auto insert = [&](int i, int j, int i2, int j2) {
		int c = 1;
		while(check(i, j, c) || check(i2, j2, c)) c++;
		ans[i][j] = ans[i2][j2] = c;
	};

	if(n&1) {
		if(k < (m>>1)) {cout << "NO\n"; return;}
		if((k&1) != ((m>>1)&1)) {cout << "NO\n"; return;}
		for(int j = 0; j < m; j+=2) {
			insert(0, j, 0, j+1);
			k--;
		}
	} else if((k&1) != 0) {cout << "NO\n"; return;}

	for(int i = n&1; i < n; i+=2) {
		for(int j = 0; j+1 < m; j+=2) {
			if(k==0) break;
			insert(i, j, i, j+1);
			insert(i+1, j, i+1, j+1);
			k -= 2;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(ans[i][j] == 0) insert(i, j, i+1, j);
		}
	}

	cout << "YES\n";
	for(auto &v : ans) {
		for(auto &i : v) {
			cout << char('a'+i-1);
		}
		cout << "\n";
	}
}

//king of the sun o_O
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	//int t = 1;
	while(t--) {
		solve();
		// if(t)   cout << "\n";
	}
}

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */