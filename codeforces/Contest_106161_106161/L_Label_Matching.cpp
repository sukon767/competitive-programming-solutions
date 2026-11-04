#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    vector<unordered_map<int, int, custom_hash>> cnta(n), cntb(n);
    vector<pair<int, int>> nza(n), nzb(n);
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a) {
            cnta[i][a]++;
            nza[i].f++;
        } else nza[i].s++;
    }

    auto merge = [&](int x, int y) {
        int z = min(cnta[x][y], cntb[x][y]);
        nza[x].f -= z; nzb[x].f -= z;
        cnta[x][y] -= z; cntb[x][y] -= z;
    };

    for(int i = 0; i < n; i++) {
        int b; cin >> b;
        if(b) {
            cntb[i][b]++;
            nzb[i].f++;
            merge(i, b);
        } else nzb[i].s++;
    }

    vector<vector<int>> adj(n);
    for(int i = 0; i+1 < n; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    vector<bool> ans(n);
    auto dfs = [&](auto&&self, int x, int p) -> void {
        for(int y : adj[x]) {
            if(y == p) continue;
            self(self, y, x);

            //merge a
            if(sz(cnta[x]) < sz(cnta[y])) {
                swap(cnta[x], cnta[y]);
                swap(nza[x], nza[y]);
                swap(cntb[x], cntb[y]);
                swap(nzb[x], nzb[y]);
            }
            nza[x].f += nza[y].f;
            nza[x].s += nza[y].s;
            for(auto &p : cnta[y]) {
                cnta[x][p.f] += p.s;
                merge(x, p.f);
            }

            //merge b
            if(sz(cntb[x]) < sz(cntb[y])) {
                swap(cnta[x], cnta[y]);
                swap(nza[x], nza[y]);
                swap(cntb[x], cntb[y]);
                swap(nzb[x], nzb[y]);
            }
            nzb[x].f += nzb[y].f;
            nzb[x].s += nzb[y].s;
            for(auto &p : cntb[y]) {
                cntb[x][p.f] += p.s;
                merge(x, p.f);
            }

        }
        // if(x==0) {
        //     cout << nza[x].f << " " << nza[x].s << " " << nzb[x].f << " " << nzb[x].s << endl;
        // }

        ans[x] = (nza[x].f <= nzb[x].s && nzb[x].f <= nza[x].s);
    };
    dfs(dfs, 0, -1);

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