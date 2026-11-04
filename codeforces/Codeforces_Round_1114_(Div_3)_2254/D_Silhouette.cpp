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
    vector<ll> b(n); for(ll& i : b) cin >> i;
    vector<ll> a(n);
    map<ll, vector<int>> pos;
    for(int i = 0; i < n; i++) pos[b[i]].push_back(i);
    vector<vector<int>> sm;
    for(auto &[_, v] : pos) sm.push_back(v);
    
    if(b[sm[0][0]] != 0) {
        cout << -1; return;
    }
    for(int j : sm[0]) a[j] = 1;
    if(sz(sm) == 1) {
        for(ll x : a) cout << x << " ";
        return;
    }
    for(int i = 1; i < sz(sm); i++) {
        ll dx = b[sm[i][0]] - b[sm[i-1][0]];
        if(dx % sz(sm[i-1])) {cout << -1; return;}
        dx /= sz(sm[i-1]);
        if(dx <= (i>=2 ? a[sm[i-2][0]] : 0)) {cout << -1; return;}
        for(int j : sm[i-1]) a[j] = dx;
        if(i == sz(sm)-1) {
            for(int j : sm[i]) a[j] = dx+1;
        }
    }

    for(ll x : a) cout << x << " ";
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