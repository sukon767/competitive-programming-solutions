#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> v(3);
	for (int& i : v) cin >> i;
	sort(v.begin(), v.end());
	if (v[2] - v[0] >= 10) {
		cout << "check again\n";
	} else {
		cout << "final " << v[1] << "\n";
	}
}