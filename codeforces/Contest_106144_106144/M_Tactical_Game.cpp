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
		// cout << s << endl;
		bool x1 = false, x2 = false;
		int ans = 0;
		for (int i = 0; i < n - 2; i++) {
			if (s[i] == '1') {
				// cout << "asdf" << endl;
				ans++;
			}
			if (s[i] == '1' && s[i + 1] == '1') {
				x1 = true;
				if (s[i + 2] == '1') x2 = true;
			}
		}
		if (s[n - 2] == '1' && s[n - 1] == '1') x1 = true;
		for (int i = n - 2; i < n; i++)
			if (s[i] == '1') ans++;

		cout << ans - x1 - x2;
		cout << "\n";
	}

	// int t;
	// cin >> t;
	// while (t--) {
	// 	string s;
	// 	cin >> s;
	// 	vector<vector<int>> cnt(26);
	// 	for(int i = 0; i<s.size(); i++) cnt[s[i]-'a'].push_back(i);
	// 	ll ans = 0;
	// 	for(auto& a: cnt){
	// 		vector<pair<int,int>> r;
	// 		for(int i: a) if(r.size() == 0 || r.back().b < i-1)
	// 			r.push_back({i,i});
	// 		else r.back().b = i;

	// 	}
	// }
}