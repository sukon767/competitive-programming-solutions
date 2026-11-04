#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<string> msk;
    int k = n;
    while(k) {
        string s; cin >> s;
        msk.push_back(s);
        k>>=1;
    }

    int l2 = sz(msk);
    vector<vector<int>> cnt(n+1);
    for(int i = 0; i < sz(msk); i++) {
        int c = 0;
        for(int j = 0; j < n; j++) c += (msk[i][j] - '0');
        cnt[c].push_back(i);
    }
    
    vector<vector<int>> need(n+1);
    for(int i = 0; i < l2; i++) {
        int c = 0;
        for(int j = 1; j <= n; j++) c += j>>i&1;
        need[c].push_back(i);
    }

    
    // for(int i = 0; i < l2; i++) {
        //     cout << i << " " << sz(cnt[i]) << " " << sz(need[i]) << endl;
        // }
        
        
    vector<int> pe(l2);
    for(int i = 0; i <= n; i++) {
        if(sz(need[i]) != sz(cnt[i])) {cout << 0; return;}
        for(int j = 0; j < sz(need[i]); j++) {
            pe[need[i][j]] = cnt[i][j];
        }
    }
    
    // cout << "asdf" << endl;



    vector<bool> hv(n+1);
    for(int i = 0; i < n; i++) {
        int x = 0;
        for(int j = 0; j < l2; j++) {
            if(msk[pe[j]][i] == '1') x |= (1LL << j);
        }
        if(x > n) {cout << 0; return;}
        hv[x] = 1;
    }
    
    for(int i = 1; i <= n; i++) {
        if(hv[i]==0) {cout << 0; return;}
    }

    ll ans = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 1; j <= sz(cnt[i]); j++) ans *= j;
    }

    cout << ans;
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