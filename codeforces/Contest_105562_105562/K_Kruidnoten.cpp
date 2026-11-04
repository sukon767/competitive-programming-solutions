#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> g(n);
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		g[--a].push_back({--b, w});
		g[b].push_back({a, w});
	}
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
		pq;
	vector<ll> dp1(n, LLONG_MAX), dp2(n, LLONG_MAX);
	pq.push({dp1[0] = 0, 0});
	while (!pq.empty()) {
		auto x = pq.top();
		pq.pop();
		if (x.a != dp1[x.b]) continue;
		for (auto& a : g[x.b])
			if (x.a + a.b < dp1[a.a]) pq.push({dp1[a.a] = x.a + a.b, a.a});
	}
	pq.push({dp2[n - 1] = 0, n - 1});
	while (!pq.empty()) {
		auto x = pq.top();
		pq.pop();
		if (x.a != dp2[x.b]) continue;
		for (auto& a : g[x.b])
			if (x.a + a.b < dp2[a.a]) pq.push({dp2[a.a] = x.a + a.b, a.a});
	}
	vector<pair<ll, double>> v(k);
	bool w = 0;
	for (auto& a : v) {
		int x;
		cin >> x;
		x--;
		a.a = dp1[x] + dp2[x];
		cin >> a.b;
		if (a.b == 1) w = 1;
	}
	if (!w) {
		cout << "impossible\n";
		return 0;
	}
	sort(v.begin(), v.end());
	long double ans = 0, prob = 1;
	for (auto& a : v) {
		ans += a.a * prob * a.b;
		prob *= 1 - a.b;
	}
	cout << fixed << setprecision(7) << ans << "\n";
}