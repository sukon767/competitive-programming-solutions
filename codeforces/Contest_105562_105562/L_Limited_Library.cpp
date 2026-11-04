#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<int> a(n), b(m);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int lo = -1, hi = n;
	while (lo < hi) {
		int mi = (lo + hi + 1) >> 1;
		int p1 = 0, p2 = 0;
		for (int i = 0; i < n; i++) {
			int mx = i < mi ? y : x;
			while (p2 < m && b[p2] <= a[i]) p2++;
			while (p1 < p2 && mx--) p1++;
		}
		if (p1 == m)
			lo = mi;
		else
			hi = mi - 1;
	}
	if (lo == -1)
		cout << "impossible\n";
	else
		cout << lo << "\n";
}