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
    int n; cin >> n;
    vector<int> b(n); for(int &i : b) cin >> i;
    vector<int> ans(n, -1);

    for(int t = 0; t < 2; t++) {
        int mx = -1;
        for(int i = 0; i < n; i++) {
            if(b[i] != -1) mx = max(mx, i+b[i]-1);
            if(i <= mx) ans[i] = 0;
        }
        reverse(all(b)); reverse(all(ans));
    }
    for(int& x : ans) if(x == -1) x = 1;
    //check
    for(int i = 0; i < n; i++) {
        if(b[i] != -1) {
            if(!((0 <= i-b[i] && ans[i-b[i]] == 1) || (i+b[i] < n && ans[i+b[i]] == 1))) {
                cout << -1; return;
            }
        }
    }
    for(int x : ans) cout << x;
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