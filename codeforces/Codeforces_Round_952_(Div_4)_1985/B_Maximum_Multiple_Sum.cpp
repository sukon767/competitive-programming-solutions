#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 1e9 + 7;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 0;
		int b = -1;
		for (int x = 2; x <= n; x++) {
			int c = 0;
			for (int j = x; j <= n; j += x) c += j;
			if (c > ans) {
				ans = c;
				b = x;
			}
		}
		cout << b << "\n";
	}
}