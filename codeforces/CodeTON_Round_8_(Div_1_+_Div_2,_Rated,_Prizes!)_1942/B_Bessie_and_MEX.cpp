#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int&i : a) cin >> i;
    vector<bool> f(n);
    int on = 0;
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            p[i] = on;
        } else {
            p[i] = on-a[i];
        }
        f[p[i]] = 1;
        while(on < n && f[on]) on++;
    }

    for(int x : p) cout << x << " ";
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