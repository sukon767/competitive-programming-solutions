#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

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
    
    // Returns the smallest index i such that query(i) >= val.
    // Returns n if no such index exists.
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
    int n; cin >> n;
    BIT<int> bit(n);
    for(int i = 0; i < n; i++) bit.add(i, 1);
    vector<ll> xs(n, -1);
    string str;
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        char c; ll x;
        cin >> c >> x;
        if(c=='p') --x;
        xs[i] = x;
        str += c;
    }
    for(int i = n-1; i >= 0; i--) {
        if(str[i] == 'p') {
            p[i] = xs[i];
            bit.add(xs[i], -1);
        } else {
            ll x = xs[i]; int j = i-1;
            while(j >= 0 && str[j]=='p') {
                x -= bit.query(xs[j]+1, n-1);
                bit.add(xs[j], -1);
                j--;
            }
            if(j >= 0) x -= xs[j];
            for(int k = j+1; k < i; k++) bit.add(xs[k], 2);
            ll d = bit.query(n-1) - (x+(i-j-1));
            int lb = bit.lower_bound(d);
            bit.add(lb, -1); p[i] = lb;
            for(int k = j+1; k < i; k++) bit.add(xs[k], -1);
        }
    }
    for(int x : p) cout << x+1 << " ";
}

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

 /* new testament
 * nick belov always reads the entire problem statement.
 */