#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    ll n; cin >> n;
    cout << "xor " << 1 << " " << n << endl;
    ll tot; cin >> tot;
    vector<ll> ans;
    for(int b = 60; b >= 0; b--) {
        if(1LL<<b > n) continue;
        cout << "xor " << (1LL<<b) << " " << min((1LL<<(b+1))-1, n) << endl;
        ll x; cin >> x;
        if(x) {
            ll l = (1LL<<b), r = min((1LL<<(b+1))-1, n);
            while(l < r) {
                ll m = (l+r+1)>>1;
                cout << "xor " << m << " " << r << endl;
                ll y; cin >> y;
                if(y) l = m;
                else r = m-1;
            }
            ans.push_back(l); tot^=l;
            break;
        }
    }

    ll l = 1, r = ans[0]-1;
    while(l < r) {
        ll m = (l+r+1)>>1;
        cout << "xor " << m << " " << r << endl;
        ll y; cin >> y;
        if(y) l = m;
        else r = m-1;
    }
    ans.push_back(l); tot^=l; ans.push_back(tot);
    cout << "ans ";
    for(ll x : ans) cout << x << " ";
    cout << endl;
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