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
    int n, k, q; cin >> n >> k >> q;
    vector<vector<int>> event;
    for(int i = 0; i < q; i++) {
        int p, l, r; cin >> p >> l >> r;
        p--;
        //returns
        event.push_back({r, -1, -l, i});
        //departures
        event.push_back({l, 1, -r, i});
    }

    int on = 0;
    sort(all(event));
    vector<bool> key(q);
    for(auto &v : event) {
        if(v[1] == -1 && on == n) {
            key[v[3]] = 1;
        }
        on += v[1];
    }

    int curKey = 0;
    for(auto &v : event) {
        if(key[v[3]]) {
            curKey += v[1];
        }
        if(curKey > k) {
            cout << "impossible"; return;
        }
    }

    for(int x : key) cout << x;
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
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