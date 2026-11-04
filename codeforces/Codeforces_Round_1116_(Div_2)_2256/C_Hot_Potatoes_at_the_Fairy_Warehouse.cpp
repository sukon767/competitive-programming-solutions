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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	n <<=1;
	int a = 0, b = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1' && s[(i+1)%n] == '0') {
			if(i&1) {
				b -= 1; a += 1;
			} else {
				a -= 1; b += 1;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(i&1) b+=s[i]-'0';
		else a += s[i]-'0';
	}
	cout << b << " " << a;
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