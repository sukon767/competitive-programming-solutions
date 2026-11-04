#include<bits/stdc++.h>
#include <utility>

using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

template <typename T>
struct BIT {
    int n;
    vector<T> tree;
    
    BIT(int n) : n(n), tree(n + 1, 0) {}
    
    void add(int i, T val) {
        for (i++; i <= n; i += i & -i) {
            tree[i] = (tree[i] + val);
            // tree[i] = (tree[i] + val) % mod;
        }
    }
    
    T query(int i) {
        T sum = 0;
        for (i++; i > 0; i -= i & -i) {
            sum = (sum + tree[i]);
            // sum = (sum + tree[i]) % mod;
        }
        return sum;
    }
    
    T query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
        // return (query(r) - query(l - 1) + mod) % mod;
    }
    
    int lower_bound(T val) {
        if (val <= 0) return 0;
        int pos = 0;
        int pw = 1 << (31 - __builtin_clz(n));
        for (; pw > 0; pw >>= 1) {
            if (pos + pw <= n && tree[pos + pw] < val) {
                pos += pw;
                val -= tree[pos];
            }
        }
        return pos;
    }
};

void solve() {
    ll n, b, r, w; cin >> n >> b >> r >> w;
    vector<ll> d(b); for(ll& i : d) cin >> i;
    for(int i = 1; i < b; i++) d[i] += d[i-1];
    vector<ll> t(n); for(ll& i : t) {cin >> i; i--;}
    
    ll lo = 0, hi = 1e18;
    
    while(lo < hi) {
        pair<BIT<ll>, BIT<ll>> bit(b, b);
        int mx = -1;
        ll m = (lo+hi)>>1;
        
        int st = 0;
        ll cx = 0;
        ll nb = 0;

        bool ok = 1;
        for(int i = 0; i < n; i++) {
            //update current
            cx += 2*w;
            auto p = pair<ll, ll>{bit.f.query(t[i], t[i]), bit.s.query(t[i], t[i])};
            if(p.f == 0) {
                //not there - add shit
                cx += 2*w*bit.f.query(t[i]+1, b-1);
            }
            
            //under it
            cx += 2*w*bit.s.query(0, t[i]-1);

            if(p.f == 0) {
                if(t[i]>mx) {
                    cx += d[t[i]] - (mx>=0?d[mx]:0);
                    mx = t[i];
                }
                bit.s.add(t[i], 1);
            }
            bit.f.add(t[i], 1);

            if(cx > m) {
                //undo
                for(int j = st; j <= i; j++) {
                    auto pp = pair<ll, ll>{bit.f.query(t[j], t[j]), bit.s.query(t[j], t[j])};
                    bit.f.add(t[j], -pp.first); bit.s.add(t[j], -pp.second);
                }
                nb++;
                bit.f.add(t[i], 1);
                bit.s.add(t[i], 1);
                cx = nb*r + 2*w + d[t[i]];
                st = i;
                mx = t[i];
                if(cx > m) {ok = 0; break;}
            }
        }

        if(ok) hi = m;
        else lo = m+1;
    }
    cout << lo;
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