#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, l, x, y;
	cin >> n >> m >> l >> x >> y;
	vector<pair<int, double>> v;
	while (n--) {
		int s, t;
		cin >> s >> t;
		v.push_back({s, (t - s) / (double)x + (l - t) / (double)y});
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < v.size(); i++) v[i].b = min(v[i].b, v[i - 1].b);
	cout << fixed << setprecision(7);
	while (m--) {
		int r;
		cin >> r;
		int lo = -1, hi = v.size() - 1;
		while (lo < hi) {
			int m = (lo + hi + 1) >> 1;
			if (v[m].a <= r)
				lo = m;
			else
				hi = m - 1;
		}
		cout << min((l - r) / (double)y, lo == -1 ? l : v[lo].b) << "\n";
	}
}