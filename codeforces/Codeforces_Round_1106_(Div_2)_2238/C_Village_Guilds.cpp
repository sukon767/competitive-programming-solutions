#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n; cin >> n;
    vector<ll> p(n, -1);
    for(int i = 1; i < n; i++) {
        cin >> p[i]; p[i]--;
    }

    vector<ll> h(n);
    vector<vector<ll>> cont(n);
    vector<ll> g(n);
    for(int i = n-1; i >= 0; i--) {
        sort(all(cont[i]));
        h[i]++;
        g[i]++;
        if(sz(cont[i])) h[i] += cont[i].back();
        if(sz(cont[i]) >= 2) g[i] += cont[i][sz(cont[i])-2];

        if(p[i] != -1) {
            cont[p[i]].push_back(h[i]);
        }
        // cout << i+1 << " " << g[i] << endl;
    }

    cout << accumulate(all(g), (ll)0);
}

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

 /* new testament
 * nick belov always reads the entire problem statement.
 */