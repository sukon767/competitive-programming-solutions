#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
using ll = long long;
const int mod = 1e9 + 7;
ll pw(ll a, ll b) {
	ll x = 1;
	while (b) {
		if (b & 1) x = x * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return x;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (ll& i : a) cin >> i;
		int r = n - 1;
		while (r != 0 && a[r] == 0) r--;
		for (int i = r - 1; i >= 0; i--) {
			if (a[i + 1] >= 0) {
				a[i + 1] = 1;
				break;
			}
			a[i] += a[i + 1];
			a[i + 1] = 0;
		}
		if (count(a.begin(), a.end(), 0LL) == n) {
			cout << "Yes\n";
		} else
			cout << "No\n";
	}
}