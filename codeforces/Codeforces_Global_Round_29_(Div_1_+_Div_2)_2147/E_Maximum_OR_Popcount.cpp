#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, q; cin >> n >> q;
    vector<ll> a(n), b(q); for(ll& i : a) cin >> i;
    for(ll& i : b) cin >> i;
    ll base = 0;
    for(ll x : a) base|=x;

    vector<ll> ans(__builtin_popcountll(base)+1);
    vector<int> cur;

    for(int j = 0; j < 40; j++) {
        if(!(base>>j&1)) {
            ll op = 0;
            vector<ll> v = a;
            for(int i = j; i >= 0; i--) {
                ll curb = 0;
                for(ll x : v) curb |= x;
                if(curb>>i&1) continue;
                
                op += (1LL<<i);
                //turn off all bits at least i
                for(ll &x : v) {
                    x &= (1LL<<i)-1;
                }
                auto it = max_element(v.begin(), v.end());
                op -= *it;
                *it = 0;
            }

            ans.push_back(op);
        }
    }

    for(ll x : b) {
        cout << distance(ans.begin(), upper_bound(ans.begin(), ans.end(), x))-1 << "\n";
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