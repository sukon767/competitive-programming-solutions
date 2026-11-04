#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// int t;
	// cin >> t;
	// while (t--) {
	// 	int n;
	// 	cin >> n;
	// 	vector<int> a(n);
	// 	vector<vector<int>> b(n + 1);
	// 	multiset<pair<int, int>> ms;
	// 	for (int i = 0; i < n; i++) {
	// 		cin >> a[i];
	// 		b[a[i]].push_back(i);
	// 		ms.insert({i, a[i]});
	// 	}
	// 	for (int i = 1; i <= n; i++) {
	// 		reverse(b.begin(), b.end());
	// 	}
	// 	int mn = 0;
	// 	auto Upd = [&]() -> void {
	// 		while (mn <= n and b[mn].empty()) mn++;
	// 	};
	// 	Upd();
	// 	int sol = 0;
	// 	while (!ms.empty()) {
	// 		if ((int)ms.size() >= 2) {
	// 			auto pt1 = ms.begin();
	// 			auto pt2 = next(ms.begin());
	// 			if (pt1->second == pt2->second) {
	// 				int x = pt1->first;
	// 				b[x].pop_back();
	// 				b[x].pop_back();
	// 				ms.erase(ms.begin());
	// 				ms.erase(ms.begin());
	// 				sol++;
	// 			} else {
	// 				int x = mn;
	// 				int idx = b[x].back();
	// 				ms.erase({idx, x});
	// 				b[x].pop_back();
	// 				sol++;
	// 			}
	// 			Upd();
	// 		} else {
	// 			ms.erase(ms.begin());
	// 			sol++;
	// 		}
	// 	}
	// 	cout << sol << '\n';
	// }

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector<vector<int>> cnt(26);
		for (int i = 0; i < s.size(); i++) cnt[s[i] - 'a'].push_back(i);
		ll ans = 1;
		for (auto& a : cnt) {
			vector<pair<int, int>> r;
			for (int i : a)
				if (r.size() == 0 || r.back().b < i - 1)
					r.push_back({i, i});
				else
					r.back().b = i;
			ll pref = 0;
			for (auto& a : r) {
				ll len = a.b - a.a + 1;
				ans += len * pref + len;
				pref += len;
			}
		}
		cout << ans << "\n";
	}
}