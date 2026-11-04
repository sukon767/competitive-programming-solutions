#include<bits/stdc++.h>
 
using namespace std;

template<class T>
using v = vector<T>;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

template <class T, class Op> struct dst {
  v<v<T>> dat;
  v<T> a;
  v<int> mask;
  Op op;
 
  dst(v<T> a, Op op) : a(a), op(op) {
    size_t logn = 32 - __builtin_clz(a.size());
    dat.assign(logn, v<T>(a.size()));
    mask.resize(a.size());
    construct(0, a.size() - 1, 0);
  }
  dst &operator=(dst &&val) {
    dat = move(val.dat);
    a = move(val.a);
    mask = std::move(val.mask);
    return *this;
  }
 
  void construct(int l, int r, int depth) {
    if (l == r)
      return;
 
    int mid = (l + r) / 2;
    dat[depth][mid] = a[mid];
    for (int i = mid - 1; i >= l; i--)
      dat[depth][i] = op(a[i], dat[depth][i + 1]);
    dat[depth][mid + 1] = a[mid + 1];
    for (int i = mid + 2; i <= r; i++)
      dat[depth][i] = op(dat[depth][i - 1], a[i]);
    for (int i = mid + 1; i <= r; i++) {
      mask[i] ^= 1 << depth;
    }
    construct(l, mid, depth + 1);
    construct(mid + 1, r, depth + 1);
  }
 
  T operator()(int l, int r) const {
    if (l == r)
      return a[l];
    int layer = __builtin_ctz(mask[l] ^ mask[r]);
    return op(dat[layer][l], dat[layer][r]);
  }
 
  T const &operator[](int i) const { return a[i]; }
 
  T comb(T l, T r) { return op(l, r); }
};

//sukon always reads the entire problem statement.
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> pre(n), down(n);
    vector<int> mn(n, n-1);
    for(int i = 0; i < n; i++) {
        pre[i] = (s[i] == '(' ? 1 : -1);
        if(s[i] == ')') down[i]++;
    }
    partial_sum(all(pre), pre.begin()); partial_sum(all(down), down.begin());

    vector<int> stk;
    for(int i = 0; i < n; i++) {
        while(!stk.empty() && pre[i] < (stk.back() ? pre[stk.back()-1] : 0)) {
            mn[stk.back()] = i-1;
            stk.pop_back();
        }
        stk.push_back(i);
    }

    //most to the right we can go.
    vector<int> lim(n);
    int r = 0;
    for(int l = 0; l < n; l++) {
        while(r+1 < n && (down[r+1] - (l ? down[l-1] : 0) <= k)) r++;
        lim[l] = r;
    }

    // for(int x : mn) cout << x << " ";
    // cout << endl;

    //build dst
    auto op = [](int a, int b) {return max(a, b);};
    dst sparse(pre, op);

    //general case.
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int j = min(lim[i], mn[i]);
        int t = sparse(i, j) - (i?pre[i-1]:0);
        //we need the max in this interval - dst ig.
        ans = max(ans, t);
    }

    //at the beginning.
    int z = min(lim[0], mn[0]);
    //[0, z] + k.
    //because its min(n/2, pre[z] + down[z] + (k-down[z]))
    ans = max(ans, min(n/2, sparse(0, z) + k));
    assert(ans <= n/2);
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