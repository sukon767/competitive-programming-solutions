#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

#define rep(i,a,b) for (int i = (a); i < (b); ++i)

using C = complex<double>;
using vd = vector<double>;

void fft(vector<C>& a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);

    for (static int k = 2; k < n; k *= 2) {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i, k, 2 * k)
            rt[i] = R[i] = (i & 1) ? R[i / 2] * x : R[i / 2];
    }

    vector<int> rev(n);
    rep(i, 0, n)
        rev[i] = (rev[i / 2] | (i & 1) << L) / 2;

    rep(i, 0, n)
        if (i < rev[i]) swap(a[i], a[rev[i]]);

    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            rep(j, 0, k) {
                auto x = (double*)&rt[j + k];
                auto y = (double*)&a[i + j + k];
                C z(x[0] * y[0] - x[1] * y[1],
                    x[0] * y[1] + x[1] * y[0]);
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
}

vd conv(const vd& a, const vd& b) {
    if (a.empty() || b.empty()) return {};

    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res));
    int n = 1 << L;

    vector<C> in(n), out(n);

    copy(all(a), begin(in));
    rep(i, 0, sz(b))
        in[i].imag(b[i]);

    fft(in);

    for (C& x : in) x *= x;

    rep(i, 0, n)
        out[i] = in[-i & (n - 1)] - conj(in[i]);

    fft(out);

    rep(i, 0, sz(res))
        res[i] = imag(out[i]) / (4 * n);

    return res;
}

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--; adj[u].push_back(v); adj[v].push_back(u);
    }

    vector<bool> vis(n);
    vector<pair<int, int>> par(n, {0, -1}); //dist from root, par;
    auto dfs = [&](auto &&self, int x) -> void {
        vis[x] = 1;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            par[y] = {par[x].f+1, x};
            self(self, y);
        }
    };
    dfs(dfs, 0);
    pair<int, int> d1m = par[0];
    int d1 = 0;
    for(int i = 1; i < n; i++) {
        if(par[i] > d1m) {
            d1 = i; d1m = par[i];
        }
    }
    // cout << d1 << endl;

    fill(all(par), pair<int, int>{0, -1});
    fill(all(vis), 0);
    dfs(dfs, d1);
    pair<int, int> d2m = par[0];
    int d2 = 0;
    for(int i = 1; i < n; i++) {
        if(par[i] > d2m) {
            d2 = i; d2m = par[i];
        }
    }
    // cout << d2 << endl;

    // for(auto &p : par) cout << p.f << " " << p.s << endl;
    fill(all(vis), 0);
    vector<int> path;
    while(d2 != -1) {
        path.push_back(d2);
        vis[d2] = 1;
        d2 = par[d2].s;
        // cout << d2 << endl;
    }
    assert(sz(path) == d2m.f+1);
    assert(path.back() == d1);

    // for(int x : path) cout << x << " ";
    // cout << endl;

    vector<double> x1(n+1), x2(n+1);
    vector<int> h(n);
    vector<int> cur;
    auto dfs2 = [&](auto &&self, int x) -> void {
        vis[x] = 1; cur.push_back(x);
        int mx = -1;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            self(self, y);
            mx = max(mx, h[y]);
        }

        h[x] = mx+1;
    };

    auto dfs3 = [&](auto &&self, int x) -> void {
        vis[x] = 1;
        int cnt = 0;
        for(int y : adj[x]) {
            if(vis[y]) continue;
            if(h[y]+1 == h[x]) {
                cnt++; self(self, y);
            }
        }
        if(cnt >= 2) x1[h[x]] = 1;
    };

    int d = sz(path);
    for(int i = 0; i < d; i++) {
        cur.clear();
        if(i == d/2) swap(x1, x2);
        dfs2(dfs2, path[i]);
        int c = min(i, d-1-i);
        assert(h[path[i]] <= c);
        if(h[path[i]] == c) {
            x1[c] = 1;
            for(int v : cur) vis[v] = 0;
            dfs3(dfs3, path[i]);
        }
    }

    vector<double> y = conv(x1, x2);
    vector<int> ans;
    for(int i = d-2; i >= 0; i--) {
        if(y[i] > 0.5) ans.push_back(d-1-i);
    }
    ans.push_back(d-1);
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    cout << sz(ans) << " ";
    for(int x : ans) cout << x << " ";
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