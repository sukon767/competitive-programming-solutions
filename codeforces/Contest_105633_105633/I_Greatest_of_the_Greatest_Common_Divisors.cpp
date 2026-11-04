#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//rmq
int n;
vector<int> seg;

void upd(int k, int u, int i = 1, int l = 0, int r = n-1) {
    if(l==r) {seg[i] = u; return;}
    int m = (l+r)>>1;
    if(k <= m) upd(k, u, i<<1, l, m);
    else upd(k, u, i<<1|1, m+1, r);
    seg[i] = max(seg[i<<1], seg[i<<1|1]);
}

int quer(int p, int q, int i = 1, int l = 0, int r = n-1) {
    if(p <= l && r <= q) return seg[i];
    int ans = 0;
    int m = (l+r)>>1;
    if(p <= m) ans = max(ans, quer(p, q, i<<1, l, m));
    if(m+1 <= q) ans = max(ans, quer(p, q, i<<1|1, m+1, r));
    return ans;
}

void solve() {
    cin >> n;
    vector<int> a(n); for(int& i : a) cin >> i;
    seg.resize(4*n);
    const int N = 1e5;
    vector<vector<int>> fac(N+1);
    vector<int> mul(N+1, n);
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j+=i) fac[j].push_back(i);
    }

    int q; cin >> q;
    vector<pair<pair<int, int>, int>> ivl(q);
    for(int i = 0; i < q; i++) {
        cin >> ivl[i].f.s >> ivl[i].f.f;
        ivl[i].f.f--; ivl[i].f.s--;
        ivl[i].s = i;
    }
    sort(all(ivl));
    for(auto &[p, _] : ivl) swap(p.f, p.s);

    vector<vector<pair<int, int>>> ups(n);

    for(int i = n-1; i >= 0; i--) {
        vector<pair<int, int>> stk;
        for(int d : fac[a[i]]) {
            if(mul[d] < n) {
                while(sz(stk) && stk.back().s >= mul[d]) stk.pop_back();
                stk.push_back({d, mul[d]});
            }
            mul[d] = min(mul[d], i);
        }
        for(auto& [d, ind] : stk) {
            ups[ind].push_back({i, d});
        }
    }

    int on = 0;
    vector<int> ans(q);
    for(int i = 0; i < n; i++) {
        for(auto &[k, u] : ups[i]) upd(k, u);
        while(on < q && ivl[on].f.s == i) {
            ans[ivl[on].s] = quer(ivl[on].f.f, ivl[on].f.s);
            on++;
        }
    }

    for(int x : ans) cout << x << "\n";
}

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

 /* new testament
 * nick belov always reads the entire problem statement.
 */