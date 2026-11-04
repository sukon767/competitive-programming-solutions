#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
using ll = long long;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x, k;
	cin >> n >> x >> k;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	ll ans = 0;
	map<int, int> mp;
	for (int i = n - k; i < n; i++) mp[a[i]]++;
	for (int i = n - 1; i >= 0; i--) {
		if (i >= k) mp[a[i - k]]++;
		if (i % (x + 1) == x) {
			int r = mp.rbegin()->a;
			ans += r;
			if (--mp[r] == 0) mp.erase(r);
		} else {
			int r = mp.begin()->a;
			if (--mp[r] == 0) mp.erase(r);
		}
	}
	cout << ans / 2 << "\n";
}