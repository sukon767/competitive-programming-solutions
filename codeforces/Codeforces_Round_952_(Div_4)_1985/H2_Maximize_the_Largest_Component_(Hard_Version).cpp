#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 1e9 + 7;
vector<string> v;
int n, m;
pair<int, pair<pair<int, int>, pair<int, int>>> comb(
	pair<int, pair<pair<int, int>, pair<int, int>>>& a,
	pair<int, pair<pair<int, int>, pair<int, int>>> b) {
	return {a.a + b.a,
			{{min(a.b.a.a, b.b.a.a), max(a.b.a.b, b.b.a.b)},
			 {min(a.b.b.a, b.b.b.a), max(a.b.b.b, b.b.b.b)}}};
}
pair<int, pair<pair<int, int>, pair<int, int>>> dfs(int x, int y) {
	pair<int, pair<pair<int, int>, pair<int, int>>> ans = {1, {{x, x}, {y, y}}};
	v[x][y] = '.';
	if (x != 0 && v[x - 1][y] == '#') ans = comb(ans, dfs(x - 1, y));
	if (y != 0 && v[x][y - 1] == '#') ans = comb(ans, dfs(x, y - 1));
	if (x != n - 1 && v[x + 1][y] == '#') ans = comb(ans, dfs(x + 1, y));
	if (y != m - 1 && v[x][y + 1] == '#') ans = comb(ans, dfs(x, y + 1));
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		v.resize(n);
		for (auto& a : v) cin >> a;
		vector<int> x(n), y(m);
		vector<vector<int>> sub(n, vector<int>(m));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (v[i][j] == '.') {
					x[i]++;
					y[j]++;
					sub[i][j] = 1;
				}
		vector<vector<int>> psum(n, vector<int>(m));
		function<void(int, int, int, int, int)> add =
			[&](int x1, int y1, int x2, int y2, int v) {
				psum[x1][y1] += v;
				if (y2 != m - 1) psum[x1][y2 + 1] -= v;
				if (x2 != n - 1) psum[x2 + 1][y1] -= v;
				if (y2 != m - 1 && x2 != n - 1) psum[x2 + 1][y2 + 1] += v;
			};
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (v[i][j] == '#') {
					auto [cnt, v] = dfs(i, j);
					auto [x, y] = v;
					auto [xmin, xmax] = x;
					auto [ymin, ymax] = y;
					if (xmin != 0) xmin--;
					if (ymin != 0) ymin--;
					if (xmax != n - 1) xmax++;
					if (ymax != m - 1) ymax++;
					add(xmin, 0, xmax, m - 1, cnt);
					add(0, ymin, n - 1, ymax, cnt);
					add(xmin, ymin, xmax, ymax, -cnt);
					ans = max(ans, cnt);
				}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				psum[i][j] += (i ? psum[i - 1][j] : 0) +
							  (j ? psum[i][j - 1] : 0) -
							  (i && j ? psum[i - 1][j - 1] : 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				ans = max(ans, psum[i][j] + x[i] + y[j] - sub[i][j]);
		cout << ans << "\n";
	}
}