#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 1e9 + 7;
const int MAXN = 1e6;
int dsu[MAXN];
int find(int x) { return dsu[x] < 0 ? x : dsu[x] = find(dsu[x]); }
void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (dsu[a] > dsu[b]) swap(a, b);
	dsu[a] += dsu[b];
	dsu[b] = a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> v(n);
		for (auto& a : v) cin >> a;
		fill(dsu, dsu + n * m, -1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (v[i][j] == '#') {
					if (i && v[i - 1][j] == '#')
						unite(i * m + j, (i - 1) * m + j);
					if (j && v[i][j - 1] == '#')
						unite(i * m + j, i * m + j - 1);
				}
		int ans = -*min_element(dsu, dsu + n * m);
		for (int i = 0; i < n; i++) {
			set<int> s;
			int add = 0;
			for (int j = 0; j < m; j++)
				if (v[i][j] == '#') {
					s.insert(find(i * m + j));
				} else {
					add++;
					if (i && v[i - 1][j] == '#')
						s.insert(find((i - 1) * m + j));
					if (i != n - 1 && v[i + 1][j] == '#')
						s.insert(find((i + 1) * m + j));
				}
			for (int j : s) add -= dsu[j];
			ans = max(ans, add);
		}
		for (int j = 0; j < m; j++) {
			set<int> s;
			int add = 0;
			for (int i = 0; i < n; i++)
				if (v[i][j] == '#') {
					s.insert(find(i * m + j));
				} else {
					add++;
					if (j && v[i][j - 1] == '#') s.insert(find(i * m + j - 1));
					if (j != m - 1 && v[i][j + 1] == '#')
						s.insert(find(i * m + j + 1));
				}
			for (int i : s) add -= dsu[i];
			ans = max(ans, add);
		}
		cout << ans << "\n";
	}
}