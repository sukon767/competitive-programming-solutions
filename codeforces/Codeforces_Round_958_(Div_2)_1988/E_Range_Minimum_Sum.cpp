#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); for(ll& i : a) cin >> i;

    vector<vector<ll>> adj(n, vector<ll>(4));
    vector<ll> stk1, stk2, t;

    for(ll j = 2; j >= 0; j-=2) {
        for(ll i = 0; i < n; i++) {
            while(sz(stk1) && a[i] < a[stk1.back()]) {
                adj[stk1.back()][j] = j==2?i-1:n-1-i+1;
                t.push_back(stk1.back());
                stk1.pop_back();
            }
            stk1.push_back(i);

            while(sz(stk2) && a[i] < a[stk2.back()]) {
                adj[stk2.back()][j+1] = j==2?i-1:n-1-i+1;
                stk2.pop_back();
            }
            
            while(sz(t)) {
                stk2.push_back(t.back()); t.pop_back();
            }
        }
        while(sz(stk1)) {
            adj[stk1.back()][j] = j==2?n-1:0;
            stk2.push_back(stk1.back());
            stk1.pop_back();
        }

        while(sz(stk2)) {
            adj[stk2.back()][j+1] = j==2?n-1:0;
            stk2.pop_back();
        }
        reverse(all(a)); reverse(all(adj));
    }

    vector<ll> pre(n), suf(n), pcont(n);
    ll base = 0;
    for(ll i = 0; i < n; i++) {
        pre[adj[i][0]] += (adj[i][2]-i+1)*a[i];
        pre[i] -= (adj[i][2]-i+1)*a[i];
        if(i+1 < n) suf[i+1] += (i-adj[i][0]+1)*a[i];
        if(adj[i][2]+1 < n) suf[adj[i][2]+1] -= (i-adj[i][0]+1)*a[i];
        if(adj[i][0]-1 >= 0) pcont[adj[i][0]-1] += (adj[i][0]-adj[i][1]-1)*(adj[i][2]-i+1)*a[i];
        if(adj[i][2]+1 < n) pcont[adj[i][2]+1] += (adj[i][3]-adj[i][2]-1)*(i-adj[i][0]+1)*a[i];
        base += (i-adj[i][0]+1)*(adj[i][2]-i+1)*a[i];
    }

    partial_sum(all(pre), pre.begin());
    partial_sum(all(suf), suf.begin());

    for(ll i = 0; i < n; i++) {
        ll ans = base - pre[i] - suf[i] + pcont[i] - (i-adj[i][0]+1)*(adj[i][2]-i+1)*a[i];
        cout << ans << " ";
    }
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