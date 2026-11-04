#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<ll> a(n); for(ll& i : a) cin >> i;
    ll mx = *max_element(a.begin(), a.end());
    for(ll& i : a) i = mx - i;
    ll d = accumulate(a.begin(), a.end(), 0LL);
    if((n%4==0 && d%4!=0) || (n%2==0 && d%2!=0)) {cout << -1; return;}
    ll x = 1e9;
    while((x*n+d)%4 != 0) x++;
    for(ll& i : a) i += x;

    for(int j = 0; j < 2; j++) {
        vector<ll> op(n);
        for(int i = 0; i < n; i++) op.back() += a[i]*(i%2 ? -1 : 1);
        op.back()>>=1;
        for(int i = 0; i+1 < n; i++) op[i] = a[i] - op[(i-1+n)%n];
        a = op;
    }
    ll mn = *min_element(a.begin(), a.end());
    for(int i = n-1; i < 2*n-1; i++) cout << a[i%n]-mn << " ";
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