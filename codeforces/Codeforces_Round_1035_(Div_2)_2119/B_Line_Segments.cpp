#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<ll> pt(4); for(ll& i : pt) cin >> i;
    vector<ll> a(n); for(ll& i : a) cin >> i;

    ll s = accumulate(a.begin(), a.end(), (ll)0);
    ll d = (pt[0]-pt[2])*(pt[0]-pt[2])+(pt[1]-pt[3])*(pt[1]-pt[3]);
    ll sd = sqrt(d);

    if(s*s < d) cout << "NO";
    else if((*max_element(a.begin(), a.end()))*2 > s+sd) cout << "NO";
    else cout << "YES";
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