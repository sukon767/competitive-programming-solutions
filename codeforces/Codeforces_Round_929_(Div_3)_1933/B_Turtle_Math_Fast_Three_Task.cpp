#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    ll ans = 0;
    for(int x : a) ans += x;
    if(ans%3 != 1) cout << bool(ans%3);
    else {
        for(int x : a) {
            if(x%3 == 1) {
                cout << 1;
                return;
            }
        }
        cout << 2;
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