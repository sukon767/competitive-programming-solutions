// CutSandstone always reads the entire problem statement.
#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
using ll = long long;
const ll oo = 1e18;
template <class T>
T uMin(T& a, T b) {
	return a = min(a, b);
}
template <class T>
T uMax(T& a, T b) {
	return a = max(a, b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	map<string, int> mp;
	vector<string> ord;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp[s] = i;
		ord.push_back(s);
	}
	vector<vector<int>> g(n);
	for (int r = 0; r < n; r++) {
		string s;
		cin >> s;
		int i = mp[s];
		int k;
		cin >> k;
		while (k--) {
			cin >> s >> s;
			while (s.back() == ',') {
				g[i].push_back(mp[s.substr(0, s.size() - 1)]);
				cin >> s;
			}
			g[i].push_back(mp[s]);
		}
	}
	vector<vector<int>> dp(n, vector<int>(2));
	vector<vector<pair<int, int>>> bk(n, vector<pair<int, int>>(2));
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) dp[j][0] = dp[j][1] = -1;
		dp[i][0] = 0;
		queue<pair<int, int>> bfs;
		bfs.push({i, 0});
		while (bfs.size()) {
			auto c = bfs.front();
			bfs.pop();
			for (int j : g[c.a]) {
				if (dp[j][c.b] == -1) {
					dp[j][c.b] = dp[c.a][c.b] + 1;
					bk[j][c.b] = c;
					bfs.push({j, c.b});
				} else if (c.b == 0 && dp[j][1] == -1) {
					dp[j][1] = dp[c.a][0] + 1;
					bk[j][1] = c;
					bfs.push({j, 1});
				}
			}
		}
		if (dp[i][1] != -1 && (ans.size() == 0 || dp[i][1] < ans.size())) {
			ans.clear();
			pair<int, int> c = {i, 1};
			while (dp[c.a][c.b] != 0) {
				ans.push_back(c.a);
				c = bk[c.a][c.b];
			}
			reverse(ans.begin(), ans.end());
		}
	}
	if (ans.size() == 0)
		cout << "SHIP IT";
	else
		for (int i : ans) cout << ord[i] << " ";
	cout << "\n";
}