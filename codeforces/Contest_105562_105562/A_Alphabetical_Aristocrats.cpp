#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string nn;
	getline(cin, nn);
	int n = stoi(nn);
	vector<string> a(n);
	for (int i = 0; i < n; i++) getline(cin, a[i]);
	vector<pair<string, string>> b;
	for (int i = 0; i < n; i++) {
		string t;
		for (int j = 0; j < (int)a[i].size(); j++) {
			if ('A' <= a[i][j] and 'Z' >= a[i][j]) {
				t = a[i].substr(j, (int)a[i].size() - j);
				b.emplace_back(t, a[i]);
				break;
			}
		}
	}
	sort(b.begin(), b.end());
	for (auto [x, y] : b) {
		cout << y << '\n';
	}
}