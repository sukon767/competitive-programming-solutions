#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		ll lm, rm, lb, rb;
		cin >> lm >> rm;
		cin >> lb >> rb;

		int l = 0, r = min(rm - lm, (rb - lb + 1) / 2);

		while (l < r) {
			int k = l + (r - l + 1) / 2;

			ll opp = (lb + 2 * k - 1) * (lb + 2 * k) / 2 - (lb - 1) * lb / 2,
			   us = lm * k + rm * (rm + 1) / 2 - (rm - k) * (rm - k + 1) / 2;
			if (opp <= us)
				l = k;
			else
				r = k - 1;
		}

		cout << l << "\n";

		// int n;
		// cin >> n;
		// string s;
		// cin >> s;
		// vector<vector<int>> dp(n, vector<int>(n));
		// for (int i = 0; i < n; i++)
		// 	dp[i][i] = s[i] == '(' ? (n & 1 ? 0 : 1) : -1;
		// for (int i = n - 2; i >= 0; i--)
		// 	for (int j = i + 1; j < n; j++) {
		// 		int x = min(0, dp[i][i]) + dp[i + 1][j];
		// 		int y = min(0, dp[j][j]) + dp[i][j - 1];
		// 		if ((n - (j - i)) & 1)
		// 			dp[i][j] =
		// 				min(min(min(0, dp[i][i]), dp[i][i] + dp[i + 1][j]),
		// 					min(min(0, dp[j][j]), dp[j][j] + dp[i][j - 1]));
		// 		else
		// 			dp[i][j] =
		// 				max(min(min(0, dp[i][i]), dp[i][i] + dp[i + 1][j]),
		// 					min(min(0, dp[j][j]), dp[j][j] + dp[i][j - 1]));
		// 	}
		// if (s[0] == '(' && s[n - 1] == '(')
		// 	cout << (dp[0][n - 1] <= 0 ? "Monocarp\n" : "Polycarp\n");
		// else if (s[0] == '(')
		// 	cout << (dp[1][n - 1] <= -1 ? "Monocarp\n" : "Polycarp\n");
		// else if (s[n - 1] == '(')
		// 	cout << (dp[0][n - 2] <= -1 ? "Monocarp\n" : "Polycarp\n");
		// else
		// 	cout << "Polycarp\n";
	}
}