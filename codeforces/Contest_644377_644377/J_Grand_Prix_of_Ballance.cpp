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
    int n, m, q; cin >> n >> m >> q;
    vector<int> buffer;
    int cx = -1;
    int cm = m;
    vector<bool> f(m);
    vector<ll> pts(m);
    for(int i = 0; i < q; i++) {
        int t; cin >> t;
        if(t == 1) {
            int x; cin >> x;
            for(int y : buffer) f[y] = 0;
            buffer.clear();
            cx = x;
            cm = m;
        } else {
            int id, x; cin >> id >> x; id--;
            if(x != cx) continue;
            if(t == 2) {
                if(!f[id]) {
                    pts[id] += cm;
                    cm--;
                    f[id] = 1;
                    buffer.push_back(id);
                }
            } else {
                if(!f[id]) {
                    f[id] = 1;
                    buffer.push_back(id);
                }
            }
        }
    }

    vector<pair<ll, int>> v(m);
    for(int i = 0; i < m; i++) v[i] = {pts[i], -i};
    sort(all(v)); reverse(all(v));
    for(auto &p : v) cout << 1-p.s << " " << p.f << "\n";
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve();
        // if(t)   cout << "\n";
    }
}

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */