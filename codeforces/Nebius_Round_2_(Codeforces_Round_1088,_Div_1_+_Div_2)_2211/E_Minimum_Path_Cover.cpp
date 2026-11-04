#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> ans(n);
    vector<ll> goods(n);
    for(ll i = n-1; i >= 0; i--) {
        cin >> a[i];
        ll k; cin >> k;

        vector<ll> child(k);
        for(ll &i : child) {cin >> i; i--;}
        
        for(ll x : child) {
            ans[i] += ans[x];
            if(!goods[i]) goods[i] = gcd(a[i], goods[x]);
            else goods[i] = lcm(goods[i], gcd(a[i], goods[x]));
        }

        if(goods[i] == 0 || goods[i] == 1) {
            goods[i] = a[i];
            ans[i]++;
        }

        cout << ans[i] << endl;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    //ll t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}