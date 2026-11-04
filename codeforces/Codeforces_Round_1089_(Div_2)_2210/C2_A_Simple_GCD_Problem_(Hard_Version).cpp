#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
vector<ll> ps;

void solve() {

    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll &i : a) cin >> i;
    for(ll &i : b) cin >> i;

    vector<ll> g(n);
    for(ll i = 0; i < n; i++) {
        if(!i) g[i] = gcd(a[i], a[i+1]);
        else if(i == n-1) g[i] = gcd(a[i], a[i-1]);
        else g[i] = lcm(gcd(a[i], a[i+1]), gcd(a[i], a[i-1]));
    }

    vector<ll> ban(n);
    for(ll i = 0; i < n; i++) {
        if(!i) ban[i] = g[i+1]/gcd(a[i], a[i+1]);
        else if(i == n-1) ban[i] = g[i-1]/gcd(a[i], a[i-1]);
        else ban[i] = lcm(g[i+1]/gcd(a[i], a[i+1]), g[i-1]/gcd(a[i], a[i-1]));
    }

    vector<vector<ll>> plist(n);

    for(ll i = 0; i < n; i++) {
        b[i] /= g[i];
        for(ll j = 0; j < 20; j++) {
            if(ps[j] > b[i]) break;
            if(ban[i] % ps[j]) plist[i].push_back(ps[j]);
            if(plist[i].size() == 3) break;
        }
    }

    vector<ll> adjoin(n);
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        if(g[i] != a[i]) {
            if(1 <= b[i]) ans++;
        } else {
            //adjoin
            if(plist[i].size() >= 3) {ans++; continue;}
            if(plist[i].size() == 2) {
                //casey
                if(i && plist[i][0] == adjoin[i-1]) adjoin[i] = plist[i][1];
                else if(i && plist[i][1] == adjoin[i-1]) adjoin[i] = plist[i][0];
                ans++;
            } else if(plist[i].size() == 1) {
                if(!i || plist[i][0] != adjoin[i-1]) {
                    adjoin[i] = plist[i][0];
                    ans++;
                }
            }
        }
    }

    cout << ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> sieve(1000);
    for(ll i = 2; i < 1000; i++) {
        if(!sieve[i]) ps.push_back(i);
        if(ps.size() == 20) break;
        for(ll j = i; j < 1000; j+=i) sieve[j] = true;
    }

    ll t; cin >> t;
    //ll t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}