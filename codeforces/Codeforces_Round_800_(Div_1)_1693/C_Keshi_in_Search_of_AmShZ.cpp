#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
using ll = long long;
const int mod = 1e9 + 7;
ll pw(ll a, ll b) {
	ll x = 1;
	while (b) {
		if (b & 1) x = x * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n), r(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		g[--a].push_back(--b);
		r[b].push_back(a);
	}
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
				   greater<pair<int, pair<int, int>>>>
		pq;
	vector<int> dp(n, INT_MAX >> 1);
	dp[n - 1] = 0;
	vector<int> cnt(n);
	vector<int> check(n);
	pq.push({0, {n - 1, 0}});
	while (pq.size()) {
		auto x = pq.top();
		int c = x.b.a;
		pq.pop();
		if (x.b.b != check[c]) continue;
		for (int i : r[c]) {
			int o = dp[c] + g[i].size() - cnt[i];
			cnt[i]++;
			if (o < dp[i]) pq.push({dp[i] = o, {i, ++check[i]}});
		}
	}
	cout << dp[0] << "\n";
}