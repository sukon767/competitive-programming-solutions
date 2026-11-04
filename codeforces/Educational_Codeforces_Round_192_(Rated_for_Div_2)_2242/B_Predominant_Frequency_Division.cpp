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
    vector<int> a(n); for(int& i : a) cin >> i;
    vector<bool> l(n);
    int x = 0;
    //0 too
    for(int i =0 ; i < n; i++) {
        if(a[i] == 1) x++;
        else x--;
        if(x >= 0) l[i] = 1;
    }

    x = 0;
    vector<int> pre(n);
    for(int i =0 ; i < n; i++) {
        if(a[i] < 3) x++;
        else x--;
        pre[i] = x;
    }

    // for(int x : pre) cout << x << " ";

    int mn = INT_MAX;
    bool ok = 0;
    for(int i = 0; i < n-1; i++) {
        if(ok) {
            if(pre[i] - mn >= 0) {cout << "YES"; return;}
        }

        if(l[i]) {
            ok = 1;
            mn = min(mn, pre[i]);
        }
    }

    cout << "NO";

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