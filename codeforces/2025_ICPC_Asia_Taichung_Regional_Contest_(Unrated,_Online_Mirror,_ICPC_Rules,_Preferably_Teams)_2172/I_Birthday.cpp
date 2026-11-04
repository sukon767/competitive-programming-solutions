#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 998244353;
using ld = long double;
#define M_PI 3.14159265358979323846

vector<ld> line(pair<ll, ll> a, pair<ll, ll> b) {
	vector<ld> ans(3);
	if (a.first == b.first) {
		return {1, 0, -ld(a.first)};
	}
	ld m = ld(a.second - b.second) / ld(a.first - b.first);
	ld c = a.second - m * a.first;
	return {m, -1, c};
}

ld smallArea(ld r, pair<ll, ll> a, pair<ll, ll> b) {
	vector<ld> l = line(a, b);
	ld d = abs(l[2]) / sqrt(l[0] * l[0] + l[1] * l[1]);
	ld t = acos(d / r);
	ld most = acos(d / r) * r * r;
	ld down = r * sin(t);
	ld ans = most - down * d;

	pair<ld, ld> v1 = {a.first - b.first, a.second - b.second},
				 v2 = {-b.first, -b.second};
	ld cross = v1.first * v2.second - v1.second * v2.first;
	if (cross < 0) return ans;
	return M_PI * r * r - ans;
}
// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(nullptr);
// 	int n;
// 	cin >> n;
// 	vector<int> a(n);
// 	for (int& i : a) cin >> i;
// 	vector<int> h(n - 1);
// 	for (int& i : h) cin >> i;
// 	h.push_back(n);
// 	vector<int> g(n);
// 	vector<int> ans(n);
// 	for (int i = n - 1; i >= 0; i--) {
// 		for (int j = 0; j < h[i]; j++) g[j] = i;
// 		for (int j = 0; j < a[i]; j++) ans[g[j]--]++;
// 	}
// 	for (int i : ans) cout << i << " ";
// 	cout << "\n";
// }
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	ld r;
	cin >> n >> r;
	vector<pair<ll, ll>> p(n);
	for (auto& a : p) cin >> a.a >> a.b;
	vector<int> h = hullInd(p);
	ld ans = 0;
	for (int i = 0; i < h.size(); i++)
		ans = max(ans, smallArea(r, p[h[i]], p[h[(i + 1) % h.size()]]));
	cout << fixed << setprecision(7) << min(ans, r * r * M_PI / ld(2)) << "\n";
}