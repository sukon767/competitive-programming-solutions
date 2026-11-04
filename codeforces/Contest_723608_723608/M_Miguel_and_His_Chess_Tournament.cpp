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
    vector<pair<int, int>> b(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i].f;
        sum += b[i].f;
        b[i].s = i;
    }
    if(sum != n*(n-1)/2) {
        cout << "NO"; return;
    }
    sort(all(b));
    reverse(all(b));
    vector<vector<int>> g(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        if(b[i].f > n-1-i) {
            cout << "NO"; return;
        }
        vector<pair<int, int>> req;
        for(int j = i+1; j < n; j++) req.push_back({b[j].f, j});
        sort(all(req));
        for(int j = i+1; j < n; j++) {
            b[j].f--;
            g[j][i] = 1;
        }
        for(int k = 0; k < b[i].f; k++) {
            int j = req[k].s;
            b[j].f++;
            g[j][i] = 0;
            g[i][j] = 1;
        }
    }

    vector<vector<int>> ans(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans[b[i].s][b[j].s] = g[i][j];
        }
    }

    cout << "YES\n";
    for(auto &v : ans) {
        for(auto &i : v) cout << i;
        cout << "\n";
    }
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
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