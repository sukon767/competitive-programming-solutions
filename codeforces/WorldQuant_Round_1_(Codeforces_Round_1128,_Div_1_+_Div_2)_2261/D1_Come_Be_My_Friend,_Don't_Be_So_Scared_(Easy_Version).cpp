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
    int n, m; cin >> n >> m;
    if(n==1) {
        cout << 0; return;
    }
    vector<pair<int, int>> ans;
    int l = (n-1)/2 + ((n-1)&1);
    for(int i = 1; i+l-1 <= n-1; i++) {
        ans.push_back({i, i+l-1});
    }
    cout << sz(ans) << "\n";
    for(auto &p : ans) cout << p.f << " " << p.s << "\n";
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