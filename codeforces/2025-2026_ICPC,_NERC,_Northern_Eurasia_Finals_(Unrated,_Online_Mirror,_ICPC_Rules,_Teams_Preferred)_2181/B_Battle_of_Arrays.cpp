#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		priority_queue<int> a, b;
		int n, m;
		cin >> n >> m;
		while (n--) {
			int x;
			cin >> x;
			a.push(x);
		}
		while (m--) {
			int x;
			cin >> x;
			b.push(x);
		}
		bool x = 0;
		while (a.size() && b.size()) {
			int aa = a.top(), bb = b.top();
			if (x = !x) {
				b.pop();
				if (bb > aa) b.push(bb - aa);
			} else {
				a.pop();
				if (aa > bb) a.push(aa - bb);
			}
		}
		if (a.empty())
			cout << "Bob\n";
		else
			cout << "Alice\n";
	}
}