#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll n, m, a, b; cin >> n >> m >> a >> b;

    ll init = lcm(n/gcd(n, a), m/gcd(m, b));
    if(init == n*m) {
        cout << "YES"; return; 
    }
    if(init*2 < n*m) {cout << "NO"; return;}

    //now init*2 = n*m. how to check if the shift is not covered?

    //neither has give    
    ll np = n/gcd(n, a), mp = m/gcd(m, b);
    ll g = gcd(np, mp);
    // cout << np << " " << mp << endl;
    if(g == 1) cout << "NO";
    else cout << "YES";
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