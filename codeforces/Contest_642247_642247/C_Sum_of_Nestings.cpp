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
    if(k > n*(n-1)/2) {cout << "Impossible"; return;}
    ll lo = 1, hi = 2e9;
    while(lo < hi) {
        ll m = (lo+hi)>>1;
        if(m*(m-1)/2 >= k) hi = m;
        else lo = m+1;
    }
    ll df = (lo*(lo-1)/2)-k;
    string s;
    for(int i = lo-1; i > df; i--) {
        s += '(';
    }
    for(int i = df-1; i >= 0; i--) {
        s += '(';
    }
    for(int i = df-1; i >= 0; i--) {
        s += ')';
    }
    s += "()";
    for(int i = lo-1; i > df; i--) {
        s += ')';
    }
    while(sz(s) < 2*n) s += "()";
    cout << s;
}

//king of the sun o_O
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */