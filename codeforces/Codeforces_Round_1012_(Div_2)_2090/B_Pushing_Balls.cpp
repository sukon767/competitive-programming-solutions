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
    vector<vector<int>> ty(n, vector<int>(m));
    vector<string> g(n); for(auto & a : g) cin >> a;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == '1') {
                if(!i || ty[i-1][j]&1) ty[i][j] |= 1;
                if(!j || ty[i][j-1]&2) ty[i][j] |= 2;
                if(!ty[i][j]) {
                    cout << "NO"; return;
                }
            }
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