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
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> open, close;
		for (int i = 0; i < n; i++)
			if (s[i] == '(')
				open.push_back(i);
			else
				close.push_back(i);
		int ans = n;
		for (int i = 0; i <= n / 2; i++)
			for (int j = 0; j <= n / 2; j++) {
				int p1 = 0, p2 = j;
				string c;
				for (int x = 0; x < i; x++) c += "(";
				while (c.size() < n) {
					if (p2 == n / 2 ||
						(p1 != n / 2 - i && open[p1] < close[p2])) {
						c += "(";
						p1++;
					} else {
						c += ")";
						p2++;
					}
				}
				int s = 0;
				bool w = 1;
				for (char x : c) {
					if (x == '(')
						s++;
					else
						s--;
					if (s < 0) w = 0;
				}
				if (w) ans = min(ans, i + j);
			}
		cout << ans << "\n";
	}
}