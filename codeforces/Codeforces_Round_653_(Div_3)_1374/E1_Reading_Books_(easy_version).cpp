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
	int n, k;
	cin >> n >> k;
	vector<int> both, alice, bob;
	while (n--) {
		int t;
		cin >> t;
		int a, b;
		cin >> a >> b;
		if (a && b)
			both.push_back(t);
		else if (a)
			alice.push_back(t);
		else if (b)
			bob.push_back(t);
	}
	sort(both.begin(), both.end());
	sort(alice.begin(), alice.end());
	sort(bob.begin(), bob.end());
	int p1 = 0, p2 = 0, p3 = 0;
	int ca = 0, cb = 0;
	int ans = 0;
	while (ca < k || cb < k) {
		int cboth = p1 == both.size() ? INT_MAX : both[p1];
		int calice = p2 == alice.size() ? INT_MAX >> 1 : alice[p2];
		int cbob = p3 == bob.size() ? INT_MAX >> 1 : bob[p3];
		if (ca == k) {
			if (cboth < cbob) {
				p1++;
				ans += cboth;
			} else {
				if (p3 == bob.size()) {
					ans = -1;
					break;
				}
				p3++;
				ans += cbob;
			}
			cb++;
		} else if (cb == k) {
			if (cboth < calice) {
				p1++;
				ans += cboth;
			} else {
				if (p2 == alice.size()) {
					ans = -1;
					break;
				}
				p2++;
				ans += calice;
			}
			ca++;
		} else {
			if (cboth < calice + cbob) {
				ans += cboth;
				p1++;
				ca++;
				cb++;
			} else if (p2 == alice.size() || p3 == bob.size()) {
				ans = -1;
				break;
			} else {
				ans += calice + cbob;
				ca++;
				cb++;
				p2++;
				p3++;
			}
		}
	}
	cout << ans << "\n";
}