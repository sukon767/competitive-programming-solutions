#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll a, b, c, m; cin >> a >> b >> c >> m;

    ll g = a*b/(gcd(a, b));
    ll l = c*g/gcd(g, c);

    cout << (m/a*6 - m/(a*b/gcd(a, b))*3 - m/(a*c/gcd(a, c))*3 + m/l*2) << " " << (m/b*6 - m/(a*b/gcd(a, b))*3 - m/(b*c/gcd(b, c))*3 + m/l*2) << " " << (m/c*6 - m/(a*c/gcd(a, c))*3 - m/(b*c/gcd(b, c))*3 + m/l*2);
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