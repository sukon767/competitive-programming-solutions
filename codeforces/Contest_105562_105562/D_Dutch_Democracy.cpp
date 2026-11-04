#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> p(n);
	for (int& i : p) cin >> i;
	sort(p.rbegin(), p.rend());
	int need = accumulate(p.begin(), p.end(), 0LL) / 2 + 1;
	vector<ll> dp(need);
	dp[0] = 1;
	ll ans = 0;
	for (int i : p) {
		for (int j = 0; j < need; j++)
			if (j + i >= need) ans += dp[j];
		for (int j = need - i - 1; j >= 0; j--) dp[j + i] += dp[j];
	}
	cout << ans << "\n";
}