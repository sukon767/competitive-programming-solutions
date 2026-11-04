#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
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
		vector<int> cnt(10);
		for (char c : s) cnt[c - '0']++;
		int z = cnt[0], o = cnt[1],
			a = accumulate(cnt.begin() + 2, cnt.begin() + 6, 0),
			b = n - a - z - o;
		int ans = 0;
		while (1) {
			if (z) {
				z--;
				if (a)
					a--;
				else if (o)
					o--;
				else if (z)
					z--;
				else
					break;
				if (b)
					b--;
				else if (a)
					a--;
				else if (o)
					o--;
				else if (z)
					z--;
				else
					break;
				if (b)
					b--;
				else if (a)
					a--;
				else if (o)
					o--;
				else if (z)
					z--;
				else
					break;
			} else {
				if (o > 1)
					o -= 2;
				else
					break;
				if (a)
					a--;
				else if (o)
					o--;
				else if (z)
					z--;
				else
					break;
				if (b)
					b--;
				else if (a)
					a--;
				else if (o)
					o--;
				else if (z)
					z--;
				else
					break;
			}
			ans++;
		}
		cout << ans << "\n";
	}
}