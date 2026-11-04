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
	vector<string> g(n);
	int cnt = 0;
	for(string &s : g) {
		cin >> s;
		for(char c : s) cnt += c=='#';
	}
	pair<int, int> tar; cin >> tar.f >> tar.s; tar.f--, tar.s--;
	vector<pair<int, int>> coord;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if((g[i][j] == '#') == (cnt < n*n-cnt)) {
				coord.push_back({i, j});
			}
		}
	}
	
	cnt = min(cnt, n*n-cnt);
	
	pair<int, int> K = {tar.f*cnt%n, tar.s*cnt%n};
	for(int i = 0; i < cnt; i++) {
		K.f = (K.f-coord[i].f+n)%n;
		K.s = (K.s-coord[i].s+n)%n;
	}
	//K + coord[i].
	if(K.f == 0 && K.s == 0) {
		cout << "1 1 1 1 "; return;
 	}

	// for(auto &p : coord) cout << p.f << " " << p.s << endl;

	//(sum(xi) - x1 + y)/w == c mod n
	//y == cw - ((sum(xi)) + xj mod n
	for(int j = 0; j < cnt; j++) {
		pair<int, int> nw = {(coord[j].f + K.f)%n, (coord[j].s + K.s)%n};
		if(g[coord[j].f][coord[j].s] != g[nw.f][nw.s]) {
			cout << coord[j].f+1 << " " << coord[j].s+1 << " " << nw.f+1 << " " << nw.s+1;
			return;
		}
	}
}

void solve2() {
	int n; cin >> n;
	vector<string> g(n);
	int cnt = 0;
	for(string &s : g) {
		cin >> s;
		for(char c : s) cnt += c=='#';
	}

	pair<int, int> sm = {0, 0};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if((g[i][j] == '#') == (cnt < n*n-cnt)) {
				sm = {(sm.f+i)%n, (sm.s+j)%n};
			}
		}
	}
	
	cnt = min(cnt, n*n-cnt)%n;
	//inverse of cnt mod n.
	int z = -1;
	for(int i = 0; i < n; i++) {
		if(cnt*i%n == 1) {z = i; break;}
	}

	cout << sm.f*z%n+1 << " " << sm.s*z%n+1;
}

//king of the sun o_O
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string ty; cin >> ty;
	bool ok = ty == "first";
	int t; cin >> t;
	//int t = 1;
	while(t--) {
		if(ok) solve();
		else solve2();
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