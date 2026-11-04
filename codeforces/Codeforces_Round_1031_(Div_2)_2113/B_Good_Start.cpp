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
	ll w, h, a, b; cin >> w >> h >> a >> b;
	ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	bool b1 = (x1%a+a)%a == (x2%a+a)%a, b2 = (y1%b+b)%b == (y2%b+b)%b;

	for(int i = 0; i < 2; i++) {
		//overlap
		if(!(x1+a <= x2 || x2+a <= x1)) {
			if(b2) cout << "YES";
			else cout << "NO";
			return;
		}
		swap(a, b); swap(x1, y1); swap(x2, y2); swap(b1, b2);
	}

	if(b1 || b2) cout << "YES";
	else cout << "NO";
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