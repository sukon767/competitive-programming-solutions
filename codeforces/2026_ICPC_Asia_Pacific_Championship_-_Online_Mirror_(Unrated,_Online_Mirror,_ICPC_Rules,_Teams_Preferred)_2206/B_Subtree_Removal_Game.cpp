#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
using ll = long long;
const int MAXN = 5e5;
int n;
vector<int> g[MAXN];
int dfs(int s, int m) {
	if (g[s].size() == 0) return s < m ? 1 : -1;
	int sm = 0;
	for (int i : g[s]) sm += dfs(i, m);
	return sm > 0 ? 1 : sm ? -1 : 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		g[p - 1].push_back(i);
	}
	int lo = 0, hi = n;
	while (lo < hi) {
		int m = (lo + hi) >> 1;
		if (dfs(0, m) == -1)
			lo = m + 1;
		else
			hi = m;
	}
	cout << lo << "\n";
}