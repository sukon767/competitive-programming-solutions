#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    vector<int> b = a;
    sort(b.begin(), b.end());
    map<int, int> cmp;
    for(int i = 0; i < n; i++) cmp[b[i]] = i;
    for(int i = 0; i < n; i++) a[i] = cmp[a[i]];

    int inv = 0;
    for(int i = 1; i < n; i++) if(a[i-1]+1 != a[i]) inv++;

    if(inv < k) cout << "YES";
    else cout << "NO";

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