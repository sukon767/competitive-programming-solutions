#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;

    vector<int> d;
    for(int i = 1; i < n; i++) {
        if(a[i] != a[i-1])
            d.push_back(abs(a[i]-a[i-1]));
    }

    if(d.size() == 0) {cout << a.back(); return;}

    ll g = d[0];
    for(int x : d) g = gcd(g, x);

    ll s = a[0]%(2*g);
    if(!s) s+=2*g;
    for(int i = 1; i < n; i++) s += abs(a[i] - a[i-1]);

    cout << s;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}