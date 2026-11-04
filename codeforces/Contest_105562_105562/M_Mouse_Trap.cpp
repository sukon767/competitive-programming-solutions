#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> x(n), y(n);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	long double ans = 0;
	ll xs = accumulate(x.begin(), x.end(), 0LL);
	ll ys = accumulate(y.begin(), y.end(), 0LL);
	ll xsm = 0, ysm = 0;
	for (int i = 0; i < n; i++) {
		xsm += x[i] * i;
		ysm += y[i] * i;
	}
	long double tot = 0;
	for (int i = 0; i < n; i++)
		tot += x[i] * y[(i + 1) % n] - x[(i + 1) % n] * y[i];
	ll ap = 0, bp = 0;
	for (int i = 0; i < n; i++) {
		ll a = ap * n, b = bp * n;
		a += ysm;
		b += xsm;
		a -= i * ys;
		b -= i * xs;
		ans += a * (x[i] / tot) - b * (y[i] / tot);
		ans += xs * (y[i] / tot) - (x[i] / tot) * ys;
		ap += y[i];
		bp += x[i];
	}
	cout << fixed << setprecision(6) << -ans << "\n";
}