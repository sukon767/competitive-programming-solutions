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
ll cross(const pair<ll, ll>& p, const pair<ll, ll>& a, const pair<ll, ll>& b) {
	pair<ll, ll> x = {a.a - p.a, a.b - p.b};
	pair<ll, ll> y = {b.a - p.a, b.b - p.b};
	return x.a * y.b - x.b * y.a;
}
vector<int> hullInd(const vector<pair<ll, ll>>& v) {
	int ind = int(min_element(v.begin(), v.end()) - v.begin());
	vector<int> cand, hull{ind};
	for (int i = 0; i < v.size(); i++)
		if (v[i] != v[ind]) cand.push_back(i);
	sort(cand.begin(), cand.end(), [&](int a, int b) {
		pair<ll, ll> x = {v[a].a - v[ind].a, v[a].b - v[ind].b};
		pair<ll, ll> y = {v[b].a - v[ind].a, v[b].b - v[ind].b};
		ll t = x.a * y.b - x.b * y.a;
		return t != 0 ? t > 0 : x.a * x.a + x.b * x.b < y.a * y.a + y.b * y.b;
	});
	for (int c : cand) {
		while (hull.size() > 1 &&
			   cross(v[hull.end()[-2]], v[hull.back()], v[c]) <= 0)
			hull.pop_back();
		hull.push_back(c);
	}
	return hull;
}
ll dot(const pair<ll, ll>& a, const pair<ll, ll>& b, const pair<ll, ll>& c) {
	return (a.a - b.a) * (c.a - b.a) + (a.b - b.b) * (c.b - b.b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<ll, ll>> p(n);
	for (auto& i : p) cin >> i.a >> i.b;
	vector<bool> cur(n, 1);
	while (1) {
		vector<int> inds;
		vector<pair<ll, ll>> pts;
		for (int i = 0; i < n; i++)
			if (cur[i]) {
				inds.push_back(i);
				pts.push_back(p[i]);
			}
		if (inds.size() < 4) {
			cout << "impossible\n";
			break;
		}
		vector<int> hull = hullInd(pts);
		int bad = -1;
		for (int i = 0; i < hull.size(); i++) {
			ll d = dot(pts[i ? hull[i - 1] : hull.back()], pts[hull[i]],
					   pts[hull[(i + 1) % hull.size()]]);
			if (d > 0) {
				bad = inds[hull[i]];
				break;
			}
		}
		if (bad == -1) {
			cout << hull.size() << "\n";
			for (int i : hull) cout << inds[i] + 1 << " ";
			cout << "\n";
			break;
		}
		cur[bad] = 0;
	}
}