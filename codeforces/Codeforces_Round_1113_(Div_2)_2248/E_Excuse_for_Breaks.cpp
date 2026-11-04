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
    int n, m, d; cin >> n >> m >> d;
    vector<int> c = {0};
    map<int, ll> mp;
    ll cur = 0;
    for(int i = 0; i < m; i++) {
        int p, r; cin >> p >> r;
        c.push_back(p);
        cur += r;
        mp[p] = cur;
    }
    mp[n] = cur;
    for(auto &x : c) {
        for(auto &y : c) {
            int z = x+y+1;
            ll dz = z/n*mp[n];
            auto it = mp.upper_bound(z%n);
            if(it != mp.begin()) dz += prev(it)->s;
            if(mp[x] + mp[y] - d > dz) {
                cout << "YES"; return;
            }
        }
    }
    cout << "NO";
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