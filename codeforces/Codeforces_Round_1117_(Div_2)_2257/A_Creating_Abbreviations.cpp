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
	int n, m; cin >> n >> m;
	vector<bool> has(26);
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		has[s[0]-'a']=1;
	}
	vector<string> ss(m); for(auto &s : ss) cin >> s;
	for(int i = 0; i < m; i++) {
		for(auto c : ss[i]) if(!has[c-'A']) {
			cout << "NO"; return;
		}
	}
	cout << "YES";
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