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
	map<string, int> vals;
	vals["xxx"] = 2;
	vals["x.x"] = 0;
	vals["xx."] = 1;
	vals[".xx"] = 1;
	vals[".x."] = 0;

	while (t--) {
		int n;
		cin >> n;

		int ans = 0;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			if (s[0] == '=')
				s = s.substr(3, 3);
			else
				s = s.substr(0, 3);
			ans ^= vals[s];
		}

		if (ans)
			cout << "Monocarp";
		else
			cout << "Polycarp";
		cout << "\n";
	}
}