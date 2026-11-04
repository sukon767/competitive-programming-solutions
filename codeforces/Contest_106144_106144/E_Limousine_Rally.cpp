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
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> sm(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				sm[i][j] = s[j] == 'x';
				if (i) sm[i][j] += sm[i - 1][j];
			}
		}
		vector<vector<bool>> can(n - k + 1, vector<bool>(m));
		for (int i = 0; i <= n - k; i++)
			for (int j = 0; j < m; j++)
				can[i][j] = sm[i + k - 1][j] - (i ? sm[i - 1][j] : 0) == 0;
		vector<vector<bool>> vis(n - k + 1, vector<bool>(m));
		function<void(int, int)> dfs = [&](int x, int y) {
			if (!can[x][y] || vis[x][y]) return;
			vis[x][y] = 1;
			if (x != n - k) dfs(x + 1, y);
			if (y != 0) dfs(x, y - 1);
			if (y != m - 1) dfs(x, y + 1);
		};
		dfs(0, 0);
		int ans = 0;
		for (int i = 0; i <= n - k; i++)
			for (bool b : vis[i])
				if (b) ans = i;
		cout << ans + k << "\n";
	}
}