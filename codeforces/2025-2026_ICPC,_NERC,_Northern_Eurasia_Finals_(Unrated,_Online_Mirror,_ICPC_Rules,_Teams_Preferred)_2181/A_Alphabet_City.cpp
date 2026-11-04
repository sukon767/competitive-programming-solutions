#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	vector<ll> cnt(26);
	for (auto& a : v) {
		cin >> a;
		for (char c : a) cnt[c - 'A']++;
	}
	for (auto& a : v) {
		vector<int> cnt2(26);
		for (char c : a) {
			cnt[c - 'A']--;
			cnt2[c - 'A']++;
		}
		ll ans = LLONG_MAX;
		for (int i = 0; i < 26; i++)
			if (cnt[i] * m - cnt2[i] < 0) {
				ans = -1;
				break;
			} else if (cnt[i] != 0)
				ans = min(ans, (cnt[i] * m - cnt2[i]) / cnt[i]);
		cout << ans << " ";
		for (char c : a) cnt[c - 'A']++;
	}
	cout << "\n";
}