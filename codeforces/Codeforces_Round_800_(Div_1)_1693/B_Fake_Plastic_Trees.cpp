#include <math.h>
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
using ld = long double;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define F(i, l, r) for(int i = l; i < (r); ++i)
#define vpii vector<pii>
#define vpll vector<pll>
#define vll vector<ll>
#define vld vector<ld>
#define FD(i, r, l) for(int i = r; i > (l); --i)
#define G(x) int x; cin >> x;
#define GL(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define GC(c) char c; cin >> c;
#define fs first
#define sc second
#define inf 0x3f3f3f3f
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define size(x) (int)x.size()
#ifdef DEV_MODE
#include "debug.h"
#else
#define dbg(...)
#define dbg2d(...)
#endif


#define int long long


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    G(t)
    while(t--) {
        G(n)
        vi p(n);
        vector<vi> g(n);
        F(i, 1, n) {
            cin >> p[i], p[i]--;
            g[p[i]].pb(i);
        }
        vi l(n), r(n);
        F(i, 0, n) {
            cin >> l[i] >> r[i];
        }
        int ans = 0;
        auto DFS = [&](auto DFS, int v) -> int {
            int accumulated = 0;
            for (auto u : g[v]) {
                accumulated += DFS(DFS, u);
            }
            if (accumulated < l[v]) {
                accumulated += r[v] - accumulated;
                ans += 1;
            }
            if (accumulated > r[v]) {
                accumulated = r[v];
            }
            return accumulated;
        };
        DFS(DFS, 0);
        cout << ans << '\n';
    }
}








