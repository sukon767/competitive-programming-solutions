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
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i = n - 1; i >= 0; i--)
			for (int j = i; j < n; j++) {
				int vI = s[i] == '(' ? 1 : -1;
				int vJ = s[j] == '(' ? 1 : -1;
				if ((n - (j - i)) & 1) {
					dp[i][j] =
						min(min(min(0, vI), vI + (i == j ? 0 : dp[i + 1][j])),
							min(min(0, vJ), vJ + (i == j ? 0 : dp[i][j - 1])));
				} else {
					dp[i][j] = max(min(0, i == j ? 0 : dp[i + 1][j]),
								   min(0, i == j ? 0 : dp[i][j - 1]));
				}
			}
		if (s[0] == '(' && s[n - 1] == '(')
			cout << (min(dp[0][n - 2], dp[1][n - 1]) <= -1 ? "Monocarp\n"
														   : "Polycarp\n");
		else if (s[0] == '(')
			cout << (dp[1][n - 1] <= -1 ? "Monocarp\n" : "Polycarp\n");
		else if (s[n - 1] == '(')
			cout << (dp[0][n - 2] <= -1 ? "Monocarp\n" : "Polycarp\n");
		else
			cout << "Polycarp\n";
	}
}