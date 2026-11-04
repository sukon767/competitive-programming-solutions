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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (auto& a : v)
		for (int& i : a) cin >> i;
	vector<vector<int>> dp(n, vector<int>(m, INT_MAX / 2));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
				   greater<pair<int, pair<int, int>>>>
		pq;
	int x, y;
	cin >> x >> y;
	pq.push({dp[x - 1][y - 1] = v[x - 1][y - 1], {x - 1, y - 1}});
	while (pq.size()) {
		auto [c, p] = pq.top();
		pq.pop();
		if (c != dp[p.a][p.b]) continue;
		for (auto t : vector<pair<int, int>>{{p.a - 1, p.b},
											 {p.a + 1, p.b},
											 {p.a, p.b - 1},
											 {p.a, p.b + 1},
											 {p.a - 1, p.b - 1},
											 {p.a + 1, p.b - 1},
											 {p.a - 1, p.b + 1},
											 {p.a + 1, p.b + 1}}) {
			if (t.a >= 0 && t.a < n && t.b >= 0 && t.b < m &&
				dp[t.a][t.b] > max(v[t.a][t.b], c))
				pq.push({dp[t.a][t.b] = max(v[t.a][t.b], c), t});
		}
	}
	ll ans = 0;
	for (auto& a : dp)
		for (int& i : a)
			if (i < 0) ans -= i;
	cout << ans << "\n";
}