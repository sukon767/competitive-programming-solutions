#include<bits/stdc++.h>
 
using namespace std;

using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

int f[1<<18];

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) cin >> i;
    //build the cartesian didy or something
    vector<int> par(n, -1);
    vector<int> stk;
    for(int i = 0; i < n; i++) {
        int last = -1;
        while(!stk.empty() && a[i] >= a[stk.back()]) {
            last = stk.back();
            stk.pop_back();
        }
        if(!stk.empty()) par[i] = stk.back();
        if(last != -1) par[last] = i;
        stk.push_back(i);
    }
    vector<array<int, 2>> adj(n, {-1, -1});
    for(int i = 0; i < n; i++) if(par[i] != -1) adj[par[i]][i > par[i]] = i;
    int mx = stk[0];
    
    //so annoying...
    int ans = 0;
    for(int t = 17; t >= 0; t--) {
        //try
        ans |= (1<<t);
        vector<int> p(n);
        for(int i = 0; i < n; i++) p[i] = (i ? p[i-1] : 0)^(a[i]&ans);
        auto dfs = [&](auto&&self, int x, int l, int r) -> bool {
            //basically make left and right, try if mask is good, stl merge.
            //[l, x-1]
            //[x+1, r]
            bool ok = 0;
            if((x-1)-l <= r-(x+1)) {
                if(adj[x][0] != -1) {
                    ok |= self(self, adj[x][0], l, x-1);
                    for(int i = l; i <= x-1; i++) f[p[i]]--;
                }
                if(adj[x][1] != -1) {
                    ok |= self(self, adj[x][1], x+1, r);
                }
                f[p[x]]++;
                if((a[x]&ans) == ans) {
                    ll cnt = 0;
                    for(int i = l-1; i <= x-1; i++) {
                        cnt += f[(i<0 ? 0 : p[i])^ans];
                    }
                    assert(cnt>0);
                    if(cnt-1) ok = 1;
                }
                for(int i = l; i <= x-1; i++) f[p[i]]++;
            } else {
                if(adj[x][1] != -1) {
                    ok |= self(self, adj[x][1], x+1, r);
                    for(int i = x+1; i <= r; i++) f[p[i]]--;
                }
                if(adj[x][0] != -1) {
                    ok |= self(self, adj[x][0], l, x-1);
                }
                if((a[x]&ans) == ans) {
                    f[(l?p[l-1]:0)]++;
                    ll cnt = 0;
                    for(int i = x; i <= r; i++) {
                        cnt += f[p[i]^ans];
                    }
                    assert(cnt>0);
                    if(cnt-1) ok = 1;
                    f[(l?p[l-1]:0)]--;
                }
                for(int i = x; i <= r; i++) f[p[i]]++;
            }
            return ok;
        };
        bool wrk = dfs(dfs, mx, 0, n-1);
        for(int i = 0; i < n; i++) f[p[i]&ans] = 0;
        if(!wrk) ans ^= (1<<t);
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