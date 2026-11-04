#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    ll n, m; cin >> n >> m;
    if(m < n) {cout << -1; return;}
    m -= n;
    ll on = 0;
    vector<ll> a(n);
    while(n-1-on > 0 && m >= n-1-on) {
        m -= n-1-on; on++;
        a[on] = on;
    }

    if(on == n-1 && m > 0) {
        cout << -1; return;
    } else {
        //root is on+m;
        cout << on+m+1 << "\n";
        for(int i = 0; i <= on; i++) {
            if(i==on+m) continue;
            cout << on+m+1 << " " << i+1 << "\n";
        }
        for(int i = on+1; i < n; i++) {
            if(i==on+m) continue;
            cout << on+1 << " " << i+1 << "\n";
        }
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