#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int& i : a) {cin >> i; i--;}
    sort(a.begin(), a.end());
    vector<int> f(n);
    vector<pair<bool, bool>> adj(n);
    for(int i = 0; i < n; i++) {
        f[a[i]]++;
        if(i && a[i] != a[i-1] && a[i]-a[i-1]<=k) {
            adj[a[i-1]].second=adj[a[i]].first=1;
        }
    }

    for(int i = 0; i < n; i++) {
        // if(i==2) cout << f[i] << " " << adj[i].first << " " << adj[i].second << endl;
        if(f[i] && !adj[i].second) {
            if(adj[i].first || f[i]%2==0) {cout << "YES"; return;}
        }
    }
    cout << "NO";
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