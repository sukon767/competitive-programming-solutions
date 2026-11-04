#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) {cin >> i; i--;}
    vector<vector<bool>> hv(n, vector<bool>(n));

    set<int> cur;
    vector<int> f(n);
    for(int i = 0; i < n; i++) {
        cur.clear();
        fill(f.begin(), f.end(), 0);

        for(int j = i; j < n; j++) {
            f[a[j]]++;
            if(f[a[j]]==1) cur.insert(a[j]);
            if(sz(cur) == (j-i+1) && sz(cur) == (*prev(cur.end()) - *cur.begin() + 1)) hv[*cur.begin()][*prev(cur.end())]=1;
        }
    }

    int ans = 0;
    for(int i = 2; i <= n; i+=2) {
        for(int j = 0; j+i-1 < n; j++) {
            if(hv[j][j+i/2-1] && hv[j+i/2][j+i-1]) ans = i/2;
        }
    }

    cout << ans;
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