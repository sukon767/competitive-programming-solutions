#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int>> pt(n);
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
				   greater<pair<int, pair<int, int>>>>
		pq;
	int x = 0;
	vector<int> len(n);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		int x1, x2;
		cin >> x1 >> x2;
		pt[i].resize(k);
		for (int& j : pt[i]) cin >> j;
		x = max(x, x1);
		len[i] = x2 - x1 - accumulate(pt[i].begin(), pt[i].end(), 0);
		pq.push({x1 + len[i], {i, 0}});
	}
	int ans = 0;
	while (1) {
		ans = max(ans, pq.top().a - x);
		auto c = pq.top();
		pq.pop();
		if (c.b.b == pt[c.b.a].size()) break;
		int v = pt[c.b.a][c.b.b];
		x = max(x, c.a + v - len[c.b.a]);
		pq.push({c.a + v, {c.b.a, c.b.b + 1}});
	}
	cout << ans << "\n";
}