#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	vector<int> g(n + 1);
	vector<int> b(n);
	vector<int> st;
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() and c[st.back()] < c[i]) {
			st.pop_back();
		}
		if (!st.empty()) {
			g[i] = st.back();
		} else {
			g[i] = -1;
		}
		st.emplace_back(i);
	}
	for (int it = 0; it < q; it++) {
		string type;
		cin >> type;
		if (type == "+") {
			int l, x;
			cin >> l >> x, l--;
			vector<int> trav;
			if (b[l] == c[l]) l = g[l];
			while (l != -1 and b[l] <= c[l]) {
				int d = min(c[l] - b[l], x);
				b[l] += d;
				x -= d;
				if (x == 0) break;
				trav.emplace_back(l);
				l = g[l];
			}
			for (auto& y : trav) {
				g[y] = l;
			}
		} else {
			int l;
			cin >> l, l--;
			cout << b[l] << '\n';
		}
	}
}