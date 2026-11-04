#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    int l = 1, r = n;
    ll cur; 
    cout << "? " << l << " " << r << endl << flush;
    cin >> cur;
    while(l < r) {
        //find mid
        int l2 = l; int r2 = r;
        while(l2 < r2) {
            int m = (l2 + r2)/2;
            cout << "? " << l << " " << m << endl << flush;
            ll s; cin >> s;
            if(s == cur/2) {l2 = m; r2 = m; break;}
            else if(s < cur/2) {l2 = m+1;}
            else r2 = m-1;
        }
        //l2 = r2 = middle.
        if(2*(l2 - l +1) <= r-l+1) r = r2;
        else l = l2+1;
        cur /= 2;
    }
    ll ans;
    cout << "? " << l << " " << l << endl << flush;
    cin >> ans;
    cout << "! " << ans << endl << flush;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}