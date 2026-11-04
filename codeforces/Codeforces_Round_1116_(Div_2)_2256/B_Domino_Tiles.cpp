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
	string s; cin >> s;

	int ans = 1;

	for(int j = 0; j < 2; j++) {

		int cur = -1;
		int way = 2;
		for(int i = j; i < n; i+=2) {
			if(s[i] != '?') {
				if(cur == -1) {
					cur = s[i]-'0';
					way = 1;
				} else if(s[i]-'0' != cur) {
					way = 0;
				}
			}
	
			if(cur != -1) cur = 1-cur;
		}

		ans *= way;
	}
	cout << ans;
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