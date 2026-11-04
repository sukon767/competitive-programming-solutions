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
		int n, k;
		cin >> n >> k;
		map<int, int> mp;
		while (n--) {
			int x;
			cin >> x;
			if (x % k != 0) mp[k - x % k]++;
		}
		if (mp.size() == 0) {
			cout << "0\n";
			continue;
		}
		int last = mp.begin()->a;
		for (auto& a : mp)
			if (a.b >= mp[last]) last = a.a;
		cout << ll(mp[last] - 1) * ll(k) + last + 1 << "\n";
	}
}