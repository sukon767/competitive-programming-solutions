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
	// 	string s;
	// 	cin >> s;
	// 	if (s[0] == ')' and s.back() == ')') {
	// 		cout << "Polycarp" << '\n';
	// 	} else {
	// 		int ignore = (s[0] == '(' ? 0 : n - 1);
	// 		deque<char> q;
	// 		for (int i = 0; i < n; i++) {
	// 			if (ignore == i) continue;
	// 			q.push_back(s[i]);
	// 		}
	// 		int bal = 1;
	// 		int turn = 1;
	// 		bool g = 0;
	// 		auto Upd = [&](char c) -> void {
	// 			if (c == ')') {
	// 				bal--;
	// 			} else {
	// 				bal++;
	// 			}
	// 		};
	// 		while (!q.empty()) {
	// 			char f = q.front();
	// 			char b = q.back();
	// 			// 0 for front, 1 for back
	// 			if (turn == 1) {
	// 				int P = 0;
	// 				if (q.front() == '(') P = 1;
	// 				if (!P) {
	// 					q.pop_front();
	// 				} else {
	// 					q.pop_back();
	// 				}
	// 			} else {
	// 				int M = 0;
	// 				if (q.front() == '(') M = 1;
	// 				if (!M) {
	// 					q.pop_front();
	// 					Upd(f);
	// 				} else {
	// 					q.pop_back();
	// 					Upd(b);
	// 				}
	// 			}
	// 			if (bal == 0) {
	// 				g = 1;
	// 				break;
	// 			}
	// 			turn ^= 1;
	// 		}
	// 		cout << (!g ? "Polycarp" : "Monocarp") << '\n';
	// 	}
	// }
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<ll, ll>> pt(n);
		for (auto& a : pt) cin >> a.a >> a.b;
		auto cross = [&](pair<ll, ll> a, pair<ll, ll> b) {
			return a.a * b.b - a.b * b.a > 0;
		};
		int ans = 0;
		set<int> bad;

		for (int i = 1; i < n - 1; i++) {
			pair<ll, ll> a = {pt[i - 1].a - pt[i].a, pt[i - 1].b - pt[i].b};
			pair<ll, ll> b = {pt[i + 1].a - pt[i].a, pt[i + 1].b - pt[i].b};
			if (!cross(a, b)) bad.insert(i);
		}
		int l = 0;
		int r = 1;

		// for (int x : bad) cout << x << endl;

		while (r < n - 1) {
			// cout << r << " " << l << endl;

			r++;
			if (bad.find(r - 1) != bad.end()) {
				l = r - 1;
				// cout << "r" << endl;
				continue;
			}

			while (1) {
				pair<int, int> a = {pt[r - 1].a - pt[r].a,
									pt[r - 1].b - pt[r].b};
				pair<int, int> b = {pt[l].a - pt[r].a, pt[l].b - pt[r].b};
				bool x1 = cross(a, b);

				b = {-b.a, -b.b};
				a = {pt[l + 1].a - pt[l].a, pt[l + 1].b - pt[l].b};

				bool x2 = cross(b, a);
				// cout << r << " " << l << " " << cross(a, b) << endl;
				// cout << a.a << " " << a.b << " " << b.a << ' ' << b.b <<
				// endl;

				if (x1 && x2) break;
				l++;
			}

			ans = max(ans, r - l + 1);
		}

		cout << ((ans < 3) ? 0 : ans) << "\n";
	}
}