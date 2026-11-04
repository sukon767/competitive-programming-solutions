#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll n; cin >> n;
    vector<ll> b(n);
    for(ll &i : b) {cin >> i;}
    
    vector<ll> a(n);   a[0] = 1;
    ll on = 2;
    for(ll i = 1; i < n; i++) {
        if(b[i] - b[i-1] == i+1)  {a[i] = on; on++;}
        else     a[i] = a[i - (b[i]-b[i-1])];  
    }
    for(ll i = 0; i < n; i++) {
        if(i)   cout << " ";
        cout << a[i];
    }
}

int main() {
    ll t; cin >> t;
    for(ll i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}