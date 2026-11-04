#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll x, y; cin >> x >> y;

    ll c = 0;
    if(y < x) swap(y, x);
    ll d = abs(y-x);

    if(d == 0) {
        cout << -1;
    } else {
        int msb;
        for(int b = 40; b >= 0; b--) {
            if((d >> b) & 1) {msb = b; break;}
        }

        for(int b = msb; b <= 40; b++) {
            c += (1LL << b);
        } 

        cout << c-x;
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