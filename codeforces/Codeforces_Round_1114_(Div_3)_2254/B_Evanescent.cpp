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
    vector<pair<char, int>> rn;
    int n; cin >> n;
    string s; cin >> s;
    for(int i = 0; i < n; i++) {
        if(!i || s[i] != s[i-1]) rn.push_back({s[i], 1});
        else rn.back().s++;
    }
    int ans = sz(rn);
    for(int i = 1; i+1 < sz(rn); i++) if(rn[i].s == 1) {
        ans = min(ans, sz(rn) - 1 - (rn[i-1].f == rn[i+1].f));
    }
    cout << ans;
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