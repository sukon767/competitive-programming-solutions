#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    ll l, r; cin >> l >> r;
    if(l==r) {cout << 0; return;}
    ll ans;
    for(int b = 50; b >= 0; b--) {
        if((l>>b&1) != (r>>b&1)) {
            int md = b;
            r++;
            for(int j = 0; j < b; j++) {
                if((l>>j&1) || (r>>j&1)) {md = j; break;}
            }
            r--;
            ans = 1LL<<md;
            ll lim = r>>b<<b;
            if(r-lim+1 == lim-l) ans<<=1;
            break;
        }
    }
    cout << ans-1;
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

 /* new testament
 * nick belov always reads the entire problem statement.
 */