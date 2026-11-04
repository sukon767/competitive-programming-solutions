#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 1e9 + 7;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int x, y, z;
		ll k;
		cin >> x >> y >> z >> k;
		ll ans = 0;
		for (int i = 1; i <= x; i++)
			if (k % i == 0) {
				ll d = k / i;
				for (ll j = 1; j * j <= d && j <= max(y, z); j++)
					if (d % j == 0) {
						if (j <= y && d / j <= z)
							ans = max(ans, ll(x - i + 1) * ll(y - j + 1) *
											   ll(z - d / j + 1));
						if (d / j <= y && j <= z)
							ans = max(ans, ll(x - i + 1) * ll(y - d / j + 1) *
											   ll(z - j + 1));
					}
			}
		cout << ans << "\n";
	}
}