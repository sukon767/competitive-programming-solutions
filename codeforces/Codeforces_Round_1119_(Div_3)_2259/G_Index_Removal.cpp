#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); for(ll & i : a) cin >> i;
    vector<ll> l(n);
    //leeway array
    for(int i = 1; i < n; i++) {
        l[i] = k - (a[i] - a[i-1]);
        // cout << i << " " << l[i] << endl;
    }


    vector<ll> p1(n);
    vector<__int128> p2(n);
    partial_sum(all(l), p1.begin());
    partial_sum(all(p1), p2.begin());

    vector<__int128> ans(n);
    for(int i = 1; i+1 < n; i++) {
        ll z = a[i+1] - a[i-1] - k;
        // cout << i << " " << z << endl;
        if(z <= 0) continue;
        int lo = i+1, hi = n-1;
        while(lo < hi) {
            int m = (lo+hi+1)>>1;
            if(p1[m] - p1[i+1] >= z) hi = m-1;
            else lo = m;
        }
        // cout << (p2[lo] - p2[i]) << endl;
        // cout << (p1[lo] - p1[i]) << endl;
        // z + (z-l[i+2]) + (z - l[i+2] - l[i+3])...

        // cout << lo << " " << i << endl;
        // cout << (lo-(i+1) + 1) << endl;
        // cout << (ll)p2[lo] << endl;
        // cout << (ll)p2[i+1] << endl;
        // cout << lo-i-1 << endl;
        // cout << p1[i+1] << endl;

        // cout << ll((((p2[lo] - p2[i]) - (i+2) * (p1[lo] - p1[i])))) << endl;
        ans[i] = (__int128)z * (lo-(i+1) + 1) - ((p2[lo] - p2[i+1]) - (__int128)(lo-i-1)*(p1[i+1]));
    }

    for(ll x : ans) cout << x << " ";
}

//king of the sun o_O
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