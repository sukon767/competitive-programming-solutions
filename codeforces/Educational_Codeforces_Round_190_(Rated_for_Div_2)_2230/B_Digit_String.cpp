#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    string s; cin >> s;
    int n = sz(s);

    vector<int> pre(n), suf(n);

    for(int i =0 ; i < n; i++) {
        pre[i] = (s[i] == '1' || s[i] == '3' || s[i] == '4');
        if(i) pre[i] += pre[i-1];
    }

    for(int i = n-1; i >= 0; i--) {
        suf[i] = (s[i] == '2' || s[i] == '4');
        if(i < n-1) suf[i] += suf[i+1];
    }
    
    int ans = min(suf[0], pre.back());
    for(int i =0 ;i < n-1; i++) {
        ans = min(ans, pre[i]+suf[i+1]);
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