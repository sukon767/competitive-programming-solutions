#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, c; cin >> n >> c;
    vector<ll> a(n); for(ll &i : a) cin >> i;


    vector<ll> pre(n); pre[0] = a[0];
    for(int i = 1; i < n; i++) pre[i] = a[i] + pre[i-1];

    vector<ll> pm(n), sm(n);
    pm[0] = c+a[0];
    for(int i = 1; i < n; i++) pm[i] = max(a[i], pm[i-1]);
    sm.back() = a.back();
    for(int i = n-2; i >= 0; i--) sm[i] = max(a[i], sm[i+1]);

    for(int i = 0; i < n; i++) {

        if((i && pm[i-1] >= a[i]) || (i < n-1 && sm[i+1] > a[i])) {
            //full sum
            if(i == n-1 || c+pre[i] >= sm[i+1]) cout << i;
            else cout << i+1;
        } else cout << 0;
        cout << " ";
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