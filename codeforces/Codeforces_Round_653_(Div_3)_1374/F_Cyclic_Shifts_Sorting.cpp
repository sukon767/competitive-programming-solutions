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
		vector<int> a(n);
		for (int& i : a) cin >> i;
		vector<int> ret;
		bool w = 1;
		for (int i = 0; i < n - 1; i++) {
			int ind = min_element(a.begin() + i, a.end()) - a.begin();
			if ((ind - i) & 1) {
				if (ind == n - 1) {
					if (i == n - 2) {
						w = 0;
						break;
					}
					ret.push_back(ind - 2);
					ret.push_back(ind - 2);
					rotate(a.begin() + n - 3, a.begin() + n - 2, a.end());
					ind--;
				} else {
					rotate(a.begin() + ind - 1, a.begin() + ind + 1,
						   a.begin() + ind + 2);
					ret.push_back(ind - 1);
					ind++;
				}
			}
			for (int j = ind - 2; j >= i; j -= 2) {
				rotate(a.begin() + j, a.begin() + j + 2, a.begin() + j + 3);
				ret.push_back(j);
			}
		}
		if (!w) {
			if (a[n - 3] == a[n - 1]) {
				ret.push_back(n - 3);
				rotate(a.begin() + n - 3, a.begin() + n - 1, a.end());
				w = 1;
			} else {
				int ind = -1;
				for (int i = n - 3; i > 0; i--)
					if (a[i] == a[i - 1]) {
						ind = i;
						break;
					}
				if (ind != -1) {
					w = 1;
					for (int j = n - 3; j >= ind; j -= 2) {
						rotate(a.begin() + j, a.begin() + j + 2,
							   a.begin() + j + 3);
						ret.push_back(j);
					}
					if ((n - 3 - ind) & 1) {
						ret.push_back(ind - 1);
						ret.push_back(ind - 1);
						rotate(a.begin() + ind - 1, a.begin() + ind,
							   a.begin() + ind + 2);
					} else {
						ret.push_back(ind - 1);
						rotate(a.begin() + ind - 1, a.begin() + ind + 1,
							   a.begin() + ind + 2);
						ind++;
					}
					for (int j = ind; j < n - 2; j += 2) {
						ret.push_back(j);
						ret.push_back(j);
						rotate(a.begin() + j, a.begin() + j + 1,
							   a.begin() + j + 3);
					}
				}
			}
		}
		if (w) {
			cout << ret.size() << "\n";
			for (int i : ret) cout << i + 1 << " ";
			cout << "\n";
		} else
			cout << "-1\n";
	}
}