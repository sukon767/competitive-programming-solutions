#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

const ll MOD = 998244353;
struct mi {
ll v;
explicit operator ll() const { return v; }
mi() { v = 0; }
mi(ll _v) : v(_v % MOD) { v += (v < 0) * MOD; }
bool operator<(const mi& other) const {
return v < other.v;
}
friend std::ostream& operator<<(std::ostream& os, const mi& m) {
  os << m.v;
  return os;
}
};
mi &operator+=(mi &a, mi b) {
if ((a.v += b.v) >= MOD) a.v -= MOD;
return a;
}
mi &operator-=(mi &a, mi b) {
if ((a.v -= b.v) < 0) a.v += MOD;
return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi(a.v * ll(b.v)); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, ll p) {
assert(p >= 0);
return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
assert(a.v != 0);
return pow(a, MOD-2);
}
mi operator/(mi a, mi b) { return a * inv(b); }
mi& operator/=(mi& a, mi b) { return a = a/b; }
bool operator==(mi a, mi b) {return a.v == b.v;}
bool operator!=(mi a, mi b) {return a.v != b.v;}

vector<int> sort_cyclic_shifts(string &s) {
    s.push_back('$');
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    s.pop_back();
    return vector<int>(p.begin()+1, p.end());
}

vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

template <typename T, typename U>
pair<T, U> operator+(const pair<T, U>& a, const pair<T, U>& b) {
    return {a.first + b.first, a.second + b.second};
}

template <typename T, typename U>
pair<T, U> operator-(const pair<T, U>& a, const pair<T, U>& b) {
    return {a.first - b.first, a.second - b.second};
}

template <typename T>
struct BIT {
    int n;
    vector<T> tree;
    
    BIT(int n) : n(n), tree(n + 1, {0, 0}) {}
    
    void add(int i, T val) {
        for (i++; i <= n; i += i & -i) {
            tree[i] = (tree[i] + val);
            // tree[i] = (tree[i] + val) % mod;
        }
    }
    
    T query(int i) {
        T sum = {0, 0};
        for (i++; i > 0; i -= i & -i) {
            sum = (sum + tree[i]);
            // sum = (sum + tree[i]) % mod;
        }
        return sum;
    }
    
    T query(int l, int r) {
        if (l > r) return {0, 0};
        return query(r) - query(l - 1);
        // return (query(r) - query(l - 1) + mod) % mod;
    }
    
    void set(int i, T val) {
        add(i, val - query(i, i));
    }

    // Returns the smallest index i such that query(i) >= val.
    // Returns n if no such index exists.
    int lower_bound(T val) {
        if (val.f <= 0) return 0;
        int pos = 0;
        int pw = 1 << (31 - __builtin_clz(n));
        for (; pw > 0; pw >>= 1) {
            if (pos + pw <= n && tree[pos + pw].f < val.f) {
                pos += pw;
                val -= tree[pos];
            }
        }
        return pos;
    }
};

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> sa = sort_cyclic_shifts(s);
    vector<int> isa(n);
    for(int i = 0; i < n; i++) isa[sa[i]] = i;
    vector<int> lcp = lcp_construction(s, sa);
    vector<pair<int, int>> ps(n, {n-1, n-1});
    BIT<pair<int, ll>> ft1(n), ft2(n);
    mi ans = 0;

    for(int b = 1; b < n; b<<=1) {
        for(int j = 0; j+b < n; j+=(b<<1)) {
            vector<int> cur(sa.begin()+j, sa.begin()+min(n, j+(b<<1)));
            sort(all(cur));
            mi t = 0, t2 = 0;
            int ml = min(lcp[j+b-1], ps[j].s), mr = min(lcp[j+b-1], ps[j+b].s);
            for(int tc = 0; tc < 2; tc++) {
                vector<int> op1, op2;
                for(int l = 0; l < min(n-j, (b<<1)); l++) {
                    int k = cur[l];
                    if(isa[k] < j+b) {
                        ll thr = min(ps[isa[k]].s, lcp[j+b-1]);
                        auto pt = ft2.query(thr);
                        t += k*(pt.s + thr*(sz(op2) - pt.f));
                        ft1.add(ps[isa[k]].s, {1, ps[isa[k]].s});
                        op1.push_back(ps[isa[k]].s);
                    } else {
                        ll thr = min(ps[isa[k]].f, lcp[j+b-1]);
                        auto pt = ft1.query(thr);
                        t += k*(pt.s + thr*(sz(op1) - pt.f));
                        ft2.add(ps[isa[k]].f, {1, ps[isa[k]].f});
                        op2.push_back(ps[isa[k]].f);
                    }
                }
                
                //reset.
                sort(all(op1)); sort(all(op2));
                op1.erase(unique(all(op1)), op1.end()); op2.erase(unique(all(op2)), op2.end());
                for(int x : op1) ft1.set(x, {0, 0});
                for(int x : op2) ft2.set(x, {0, 0});
                
                swap(t, t2); reverse(all(cur));
            }

            for(int k : cur) {
                if(isa[k] < j+b) ps[isa[k]].s = min(ps[isa[k]].s, mr);
                else ps[isa[k]].f = min(ps[isa[k]].f, ml);
            }
            
            ans += t-t2;
        }
    }
    cout << ans;
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