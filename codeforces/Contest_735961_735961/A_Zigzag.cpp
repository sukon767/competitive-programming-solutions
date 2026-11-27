#include<bits/stdc++.h>

using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

const int N = 2e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(res, t[--r]);
  }
  return res;
}

//sukon always reads the entire problem statement.
void solve() {
    int q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        t[--a[i] + n] = i;
    }
    build();
    int B = min(n, int(2*sqrt(n)));
    vector<int> pre(n);
    for(int i = 0; i < n; i++) {
        pre[i] = a[i];
        if(i) pre[i] = max(pre[i-1], pre[i]);
    }
    vector<pair<int, int>> lst(n); //pos, ops
    vector<int> one(n, -1);
    auto dp = [&](int i) {
        int nxt = query(0, pre[i] + 1);
        one[i] = nxt/B == i/B ? nxt : -1;
        if(nxt == i || nxt/B > i/B) {lst[i] = {i, 0}; return;}
        lst[i] = {lst[nxt].f, 1 + (t[pre[i]+n] != i) + lst[nxt].s};
    };
    
    for(int i = n-1; i >= 0; i--) dp(i);
    
    auto j1 = [&](int i) {
        if(one[i] != -1) return one[i];
        return query(0, pre[i] + 1);
    };

    while(q--) {
        int tc; cin >> tc;
        if(tc == 1) {
            int qi; cin >> qi, qi--;
            modify(a[qi+1], qi); modify(a[qi], qi+1); //R
            swap(a[qi], a[qi+1]);
            //pre
            for(int i = qi; i <= qi+1; i++) {
                pre[i] = a[i];
                if(i) pre[i] = max(pre[i-1], pre[i]);
            }

            auto upd = [&](int p) {
                for(int i = p; i/B == p/B && i >= 0; i--) dp(i);
            };
            upd(qi+1);
            if(qi/B < (qi+1)/B) upd(qi);
        } else {
            int u, v; cin >> u >> v; u--, v--;
            if(u == v) cout << "0\n";
            else if(v < u || a[v] < a[u]) cout << "1\n";
            else {
                auto jump = [&](int x, int y) {
                    if(x == y) return 0;
                    if(x > y) return 1;
                    int cum = 0;
                    //across
                    while(1) {
                        if(x != lst[x].f) {
                            if(lst[x].f <= y) {cum += lst[x].s; x = lst[x].f;}
                            else break;
                        } else {
                            int nxt = j1(x);
                            if(x != nxt && nxt <= y) {cum += 1 + (t[pre[x] + n] != x); x = nxt;}
                            else break;
                        }
                    }

                    //within
                    while(1) {
                        int nxt = j1(x);
                        if(x != nxt && nxt <= y) {cum += 1 + (t[pre[x] + n] != x); x = nxt;}
                        else break;
                    }

                    
                    if(x == y) return cum;
                    
                    int nxt = j1(x);
                    if(x == nxt) return -1;
                    
                    if(a[x] > a[y]) return 1 + cum;
                    if(x != t[pre[x]+n]) {
                        x = t[pre[x]+n]; cum++;
                    }
                    if(a[x] > a[y]) return 1 + cum;
                    return 2 + cum;
                };
                int nxu = query(0, a[u] + 1);
                // cout << t[pre[u]+n] << " " << nxu << endl;
                int ans = INT_MAX, tl = jump(t[pre[u]+n], v), tr = jump(nxu, v);
                if(tl != -1) ans = min(ans, tl + (u != t[pre[u]+n]));
                if(tr != -1) ans = min(ans, tr + (nxu != u));
                cout << (ans == INT_MAX ? -1 : ans) << "\n";
            }
        }
    }
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