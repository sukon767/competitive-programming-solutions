#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;

    vector<int> g(n);
    for(int i = 0; i < n; i++) {
        if(!i) g[i] = gcd(a[i], a[i+1]);
        else if(i == n-1) g[i] = gcd(a[i], a[i-1]);
        else g[i] = lcm(gcd(a[i], a[i+1]), gcd(a[i], a[i-1]));
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != g[i]) ans++;
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