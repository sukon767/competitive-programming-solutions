// CutSandstone always reads the entire problem statement.
#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
using ll = long long;
const ll oo = 1e12;
template <class T>
T uMin(T& a, T b) {
	return a = min(a, b);
}
template <class T>
T uMax(T& a, T b) {
	return a = max(a, b);
}
struct Solver {
	int n;
	ll k;
	vector<vector<int>> g;
	vector<int> leaf;
	vector<vector<int>> jp;
	vector<int> dep;
	vector<ll> dp;
	vector<int> prev;
	vector<int> ord;
	vector<int> inds;
	void dfs(int s, int p) {
		prev[s] = leaf.size();
		if (g[s].size() == 0) leaf.push_back(s);
		inds[s] = ord.size();
		ord.push_back(s);
		jp[s][0] = p;
		for (int i : g[s])
			if (i != p) {
				dep[i] = dep[s] + 1;
				dfs(i, s);
			}
	}
	Solver(vector<vector<int>> gr, int kr) : g(gr), k(kr) {
		n = g.size();
		jp.resize(n, vector<int>(33 - __builtin_clz(n), -1));
		dep.resize(n);
		prev.resize(n);
		inds.resize(n);
		dfs(0, -1);
		for (int i = 1; i < jp[0].size(); i++)
			for (int j = 0; j < n; j++)
				jp[j][i] = jp[j][i - 1] == -1 ? -1 : jp[jp[j][i - 1]][i - 1];
		dp = {1};
		ll l = 1;
		while (dp.back() < oo) {
			if ((n - 1) > oo / l)
				dp.push_back(oo);
			else
				dp.push_back((n - 1) * l + dp.back());
			if (l > oo / leaf.size())
				l = oo;
			else
				l *= leaf.size();
		}
	}
	ll getSize() { return k + 1 >= dp.size() ? oo : dp[k + 1]; }
	int findNode(ll a, ll k) {
		int lo = 0, hi = n - 1;
		while (lo < hi) {
			int m = (lo + hi + 1) / 2;
			ll r = m + (k >= dp.size() ? oo : dp[k] - 1) * prev[ord[m]];
			if (a < r)
				hi = m - 1;
			else
				lo = m;
		}
		return ord[lo];
	}
	ll findDis(int a, int b) {
		ll ans = dep[a] + dep[b];
		if (dep[a] > dep[b]) swap(a, b);
		int k = dep[b] - dep[a];
		for (int i = 0; i < jp[b].size(); i++)
			if ((k >> i) & 1) b = jp[b][i];
		if (a != b) {
			for (int i = jp[a].size() - 1; i >= 0; i--)
				if (jp[a][i] != jp[b][i]) a = jp[a][i], b = jp[b][i];
			a = jp[a][0];
		}
		return ans - 2 * dep[a];
	}
	ll down(ll a, ll k) {
		assert(k >= 0);
		ll ans = 0;
		if (k > dp.size()) {
			ll l1 = dep[leaf[0]];
			ll sub = min(a / l1, k - ll(dp.size()));
			a -= sub * l1;
			k -= sub;
			ans += sub * l1;
		}
		int v = findNode(a, k);
		if (g[v].size() > 0 || k == 0) return ans + dep[v];
		return ans + dep[v] + down(a - (dp[k] - 1) * prev[v] - inds[v], k - 1);
	}
	ll solve(ll a, ll b, ll k) {
		assert(k >= 0);
		if (k > dp.size()) {
			ll l1 = dep[leaf[0]];
			ll sub = min(a / l1, k - (ll)dp.size());
			b -= sub * l1;
			a -= sub * l1;
			k -= sub;
		}
		int n1 = findNode(a, k);
		int n2 = findNode(b, k);
		ll v = k >= dp.size() ? oo : dp[k] - 1;
		a -= v * prev[n1] + inds[n1];
		b -= v * prev[n2] + inds[n2];
		if (n1 == n2 && k > 0 && g[n1].size() == 0) return solve(a, b, k - 1);
		ll ans = findDis(n1, n2);
		if (k > 0 && g[n1].size() == 0) ans += down(a, k - 1);
		if (k > 0 && g[n2].size() == 0) ans += down(b, k - 1);
		return ans;
	}
	ll solve(ll a, ll b) { return a == b ? 0 : solve(min(a, b), max(a, b), k); }
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		g[p].push_back(i);
	}
	ll k;
	cin >> k;
	function<bool()> line = [&]() {
		if (g[0].size() != 1) return false;
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (g[i].size() == 0) cnt++;
		if (cnt == 1) {
			int q;
			cin >> q;
			ll sz = ll(n - 1) * ll(k + 1) + 1;
			while (q--) {
				ll a, b;
				cin >> a >> b;
				if (a > b) swap(a, b);
				if (a > sz || b <= sz)
					cout << b - a << "\n";
				else
					cout << a + b - sz - 1 << "\n";
			}
			return true;
		}
		return false;
	};
	if (k != 0 && g[0].size() == 1) {
		if (!line()) {
			Solver s1(g, k);
			Solver s2(g, k - 1);
			ll sz = s1.getSize();
			int q;
			cin >> q;
			while (q--) {
				ll a, b;
				cin >> a >> b;
				a--, b--;
				if (a < sz && b < sz)
					cout << s1.solve(a, b) << "\n";
				else if (a >= sz && b >= sz)
					cout << s2.solve(a - sz, b - sz) << "\n";
				else {
					if (a >= sz) swap(a, b);
					cout << s1.solve(0, a) + s2.solve(0, b - sz) << "\n";
				}
			}
		}
	} else if (!line()) {
		Solver s(g, k);
		int q;
		cin >> q;
		while (q--) {
			ll a, b;
			cin >> a >> b;
			a--, b--;
			cout << s.solve(a, b) << "\n";
		}
	}
}