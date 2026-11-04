// CutSandstone always reads the entire problem statement.
#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
using ll = long long;
const ll oo = 1e18;
template <class T>
T uMin(T& a, T b) {
	return a = min(a, b);
}
template <class T>
T uMax(T& a, T b) {
	return a = max(a, b);
}
int dp[1 << 20];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	fill(dp, dp + (1 << k), -1);
	queue<int> bfs;
	while (n--) {
		string s;
		cin >> s;
		int x = 0;
		for (char c : s) x = (x << 1) + c - '0';
		bfs.push(x);
		dp[x] = 0;
	}
	while (bfs.size()) {
		int x = bfs.front();
		bfs.pop();
		for (int i = 0; i < k; i++)
			if (dp[x ^ (1 << i)] == -1) {
				dp[x ^ (1 << i)] = dp[x] + 1;
				bfs.push(x ^ (1 << i));
			}
	}
	int x = max_element(dp, dp + (1 << k)) - dp;
	for (int i = k - 1; i >= 0; i--)
		if ((x >> i) & 1)
			cout << '1';
		else
			cout << '0';
	cout << "\n";
}