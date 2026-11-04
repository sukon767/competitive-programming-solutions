#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll m, d, w; cin >> m >> d >> w;
    ll p = w/gcd(d-1, w);
    ll z = min(d, m);
    cout << ((z/p)*(z/p+1)/2)*(z%p) + ((z/p-1)*(z/p)/2)*(p - z%p);
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