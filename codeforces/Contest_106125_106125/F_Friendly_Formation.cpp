// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
using ll = long long;
const int mod = 1e9 + 7;
ll pw(ll x, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1) res = res * x % mod;
		x = x * x % mod;
		k >>= 1;
	}
	return res;
}
vector<vector<ll>> matMul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
	vector<vector<ll>> res(a.size(), vector<ll>(b[0].size()));
	assert(a[0].size() == b.size());
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			for (int k = 0; k < b[0].size(); k++)
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
	return res;
}
struct Line {
	bool type;
	double x;
	double m, c;
};

bool operator<(Line l1, Line l2) {
	if (l1.type || l2.type) return l1.x < l2.x;
	return l1.m > l2.m;
}
struct LineContainer {
	set<Line> cht;

	bool has_prev(set<Line>::iterator it) { return it != cht.begin(); }
	bool has_next(set<Line>::iterator it) {
		return it != cht.end() && next(it) != cht.end();
	}

	double intersect(set<Line>::iterator l1, set<Line>::iterator l2) {
		return (double)(l1->c - l2->c) / (l2->m - l1->m);
	}

	void calc_x(set<Line>::iterator it) {
		if (has_prev(it)) {
			Line l = *it;
			l.x = intersect(prev(it), it);
			cht.insert(cht.erase(it), l);
		}
	}

	bool bad(set<Line>::iterator it) {
		if (has_next(it) && next(it)->c <= it->c) return true;
		return (has_prev(it) && has_next(it) &&
				intersect(prev(it), next(it)) <= intersect(prev(it), it));
	}

   public:
	void addLine(double m, double b) {
		set<Line>::iterator it;
		it = cht.lower_bound({0, 0, m, b});
		if (it != cht.end() && it->m == m) {
			if (it->c <= b) return;
			cht.erase(it);
		}

		it = cht.insert({0, 0, m, b}).first;
		if (bad(it))
			cht.erase(it);
		else {
			while (has_prev(it) && bad(prev(it))) cht.erase(prev(it));
			while (has_next(it) && bad(next(it))) cht.erase(next(it));

			if (has_next(it)) calc_x(next(it));
			calc_x(it);
		}
	}

	double queryMin(double h) {
		if (cht.size() == 0) return LLONG_MAX;
		Line l = *prev(cht.upper_bound({1, (double)h, 0, 0}));
		return l.m * h + l.c;
	}
};
ll bitPrefSum(vector<ll>& bit, int ind) {
	ll ans = 0;
	for (int i = ind + 1; i > 0; i -= i & -i) ans += bit[i];
	return ans;
}
void bitAdd(vector<ll>& bit, int ind, ll val) {
	for (int i = ind + 1; i < bit.size(); i += i & -i) bit[i] += val;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	if ((n / 2) * (n / 2 - 1) > m || (n & 1)) {
		cout << "impossible\n";
		return 0;
	}
	vector<vector<bool>> mat(n, vector<bool>(n));
	while (m--) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		mat[a][b] = mat[b][a] = 1;
	}
	vector<vector<int>> g(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && !mat[i][j]) g[i].push_back(j);
	vector<int> cc(n, -1);
	int cp = 0;
	vector<bool> r(n);
	function<bool(int)> dfs = [&](int s) {
		cc[s] = cp;
		for (int i : g[s]) {
			if (cc[i] == -1) {
				cc[i] = cp;
				r[i] = !r[s];
				if (!dfs(i)) return false;
			} else if (r[i] == r[s])
				return false;
		}
		return true;
	};
	for (int i = 0; i < n; i++)
		if (cc[i] == -1) {
			if (!dfs(i)) {
				cout << "impossible\n";
				return 0;
			}
			cp++;
		}
	vector<int> sz1(cp), sz2(cp);
	for (int i = 0; i < n; i++)
		if (r[i])
			sz1[cc[i]]++;
		else
			sz2[cc[i]]++;
	vector<vector<pair<bool, bool>>> dp(
		cp + 1, vector<pair<bool, bool>>(n / 2 + 1, {0, 0}));
	dp[0][0] = {1, 0};
	for (int i = 0; i < cp; i++) {
		for (int j = n / 2 - sz1[i]; j >= 0; j--)
			if (dp[i][j].a) dp[i + 1][j + sz1[i]] = {1, 0};
		for (int j = n / 2 - sz2[i]; j >= 0; j--)
			if (dp[i][j].a) dp[i + 1][j + sz2[i]] = {1, 1};
	}
	if (!dp.back().back().a) {
		cout << "impossible\n";
		return 0;
	}
	vector<bool> ans(cp);
	int p = n / 2;
	for (int i = cp; i > 0; i--) {
		assert(dp[i][p].a);
		ans[i - 1] = dp[i][p].b;
		p -= ans[i - 1] ? sz2[i - 1] : sz1[i - 1];
	}
	for (int i = 0; i < n; i++) cout << (ans[cc[i]] == r[i] ? "r\n" : "b\n");
}