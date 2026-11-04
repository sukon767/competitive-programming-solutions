#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll s, m; cin >> s >> m;
    ll lm = 0, ls = 0;
    for(ll bit = 0; bit <= 62; bit++) if(m & (1LL << bit)) {lm = bit; break;}
    for(ll bit = 0; bit <= 62; bit++) if(s & (1LL << bit)) {ls = bit; break;}
    if(ls < lm) {cout << -1LL; return;}
    
    ll l = 1LL, r = s;     
    while(l < r) {
        ll t = s;
        ll mid = (l+r-1LL)>>1LL;
        for(ll bit = 62; bit >= 0; bit--) {
            if(!(m & (1LL << bit))) continue;
            ll cont = min(mid, t/(1LL << bit));
            t -= cont*(1LL << bit);
            // cout << t << " " << bit << endl;
        }

        // cout << t << " " << mid << endl;
        if(!t) r = mid;
        else l = mid+1LL;
    }
    cout << l;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    ll t; cin >> t;
    //ll t = 1LL;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}