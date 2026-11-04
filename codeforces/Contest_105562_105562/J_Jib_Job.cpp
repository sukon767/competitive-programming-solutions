#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
	return (a.first - b.first) * (a.first - b.first) +
		   (a.second - b.second) * (a.second - b.second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin >> n;
	vector<ll> h(n), ans(n);
	vector<pair<ll, ll>> cs, cs2;
	for (ll& i : h) {
		ll x, y;
		cin >> x >> y;
		cs.push_back({x, y});
		cs2.push_back({x, y});
		cin >> i;
	}

	for (int i = 0; i < n; i++) {
		ll d = LLONG_MAX;
		for (int j = 0; j < n; j++)
			if (i != j && h[i] < h[j]) d = min(d, dist(cs[i], cs[j]));
		ll lo = 0, hi = 2e9;
		while (lo < hi) {
			ll m = (lo + hi + 1) >> 1;
			if (m * m <= d)
				lo = m;
			else
				hi = m - 1;
		}
		ans[i] = min(h[i], lo);
	}
	for (ll i : ans) cout << i << "\n";
}