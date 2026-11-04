#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
	int n; cin >> n;
	int u = 1, v = 2;
	int d = 1;

	while(1) {
		cout << "? " << u << " " << v << " " << d << endl;
		bool x; cin >> x;
		if(x) d++;
		else break;
	}

	for(int i = 3; i <= n; i++) {
		int ou = u, ov = v;

		while(1) {
			cout << "? " << ou << " " << i << " " << d << endl;
			bool x; cin >> x;
			if(x) {
				d++; u = ou; v = i;
			} else break;
		}

		while(1) {
			cout << "? " << i << " " << ov << " " << d << endl;
			bool x; cin >> x;
			if(x) {
				d++; u = i; v = ov;
			} else break;
		}
	}

	cout << "! " << u << " " << v << " " << d-1 << endl;
}

//king of the sun o_O
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	//int t = 1;
	while(t--) {
		solve();
		if(t)   cout << "\n";
	}
}

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */