#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

ll MOD = 998244353;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    ll ups = 0;
    vector<int> pre(n+1);
    vector<ll> p2(n+1); p2[0] = 1; for(int i = 1; i <= n; i++) p2[i] = p2[i-1]*2%MOD;
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i-1];
        if(s[i-1] == '(') {ups++; pre[i]++;}
        else pre[i]--;
    }

    vector<int> zos;
    ll ans = 1;
    for(int i = 1; i <= n; i++) if(pre[i] <= 1) zos.push_back(i);
    for(int i = zos.size()-1; i > 0; i--) {
        ll t = 1;
        for(int j = zos[i]; j > zos[i-1]; j--) {
            if(pre[j] - pre[j-1] == -1)
                t = (t+p2[j-1-zos[i-1]])%MOD;
        }
        ans = ans*t%MOD;
    }
    ans = (ans-1+MOD)%MOD;
    //this is ending down
    
    //now ending up is simply
    for(int i = n; i >= 1; i--)
        if(pre[i] - pre[i-1] == 1) ans = (ans+p2[i-1])%MOD;

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