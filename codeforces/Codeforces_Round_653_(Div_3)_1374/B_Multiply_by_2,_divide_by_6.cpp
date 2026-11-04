#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		int ans = 0;
		while (n != 1) {
			if (n % 3 != 0) {
				ans = -1;
				break;
			}
			if (n % 6 == 0)
				n /= 6;
			else
				n *= 2;
			ans++;
		}
		cout << ans << "\n";
	}
}