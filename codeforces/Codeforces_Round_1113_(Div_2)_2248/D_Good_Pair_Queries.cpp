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
    int n, q; cin >> n >> q;
    string s, t; cin >> s >> t;
    vector<int> pre(n);
    vector<int> n0(n), n1(n);
    for(int i = 0; i < n; i++) {
        pre[i] += s[i]-t[i];
        n0[i] += (s[i] == t[i] && s[i] == '0');
        n0[i] += (s[i] == t[i] && s[i] == '1');
    }
    partial_sum(all(pre), pre.begin());
    partial_sum(all(n0), n0.begin());
    partial_sum(all(n1), n1.begin());

    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--; r--;
        int c = pre[r] - (l?pre[l-1]:0);
        if(n0[r]-(l?n0[l-1]:0) >= abs(c) || n1[r]-(l?n1[l-1]:0)) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
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