#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

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

template <typename T> struct BIT {
  private:
    int size;
    vector<T> bit;
    vector<T> arr;

  public:
    BIT(int size) : size(size), bit(size + 1), arr(size) {}

    /** Sets the value at index ind to val. */
    void set(int ind, T val) { add(ind, val - arr[ind]); }

    /** Adds val to the element at index ind. */
    void add(int ind, T val) {
      arr[ind] = (arr[ind] + val);
      ind++;
      for (; ind <= size; ind += ind & -ind) { bit[ind] = (bit[ind]+val); }
    }

    /** @return The sum of all values in [0, ind]. */
    T pref_sum(int ind) {
      ind++;
      T total = 0;
      for (; ind > 0; ind -= ind & -ind) { total = (total+bit[ind]); }
      return total;
    }

    /** The first index where prefix sum >= target */
    T findKth(int target) {
        int idx = 0;
        T current_sum = 0;
        // Start from the largest power of 2 less than or equal to N
        for (int i = 1 << (int)log2(size); i > 0; i >>= 1) {
            int next_idx = idx + i;
            if (next_idx <= size && current_sum + bit[next_idx] < target) {
                idx = next_idx;
                current_sum += bit[next_idx];
            }
        }
        return idx+1;
        //MAY HAVE TO REMOVE THE +1 IF CONVERTING 0-INDEX TO 1-INDEX, NOT SURE. BE AWARE
    }
};

vector<vector<int>> adj;
vector<int> mx, mc;
vector<bool> vis;
int n;

void dfs(int x) {
    vis[x] = true;
    for(int y : adj[x]) {
        if(vis[y]) continue;
        if(x == n-1) mc[y] = y;
        else mc[y] = mc[x];
        dfs(y);
        mx[x] = max(mx[x], max(mx[y], y));
    }
}

void solve() {
    cin >> n;
    adj = vector<vector<int>>(n);
    mx = vector<int>(n, -1);
    mc = vector<int>(n);
    vis = vector<bool>(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    dfs(n-1);
    pair<int, int> bst = {-1, -1};
    for(int y : adj[n-1]) {
        if(bst.first == -1 || max(y, mx[y]) > max(bst.first, mx[bst.first])) {
            bst = {y, bst.first};
        } else if(bst.second == -1 || max(y, mx[y]) > max(bst.second, mx[bst.second])) bst.second = y;
    }

    //starting leaf
    int st = -1;
    for(int i = n-1; i >= 0; i--)
        if(sz(adj[i]) == 1) {st = i; break;}

    BIT<mi> bit(n);

    if(st == n-1) cout << 1;
    else {
        for(int i = n-2; i >= st; i--) {
            if(i < mx[i]) continue;

            mi cur = bit.pref_sum(i-1);
            if((mc[i] == bst.first && max(bst.second, mx[bst.second]) < i) || (mc[i] != bst.first && max(bst.first, mx[bst.first]) < i))
                cur+=1;

            if(i == st) {
                cout << cur;
            } else if(mx[i] != -1) bit.add(mx[i], cur);
        }
    }
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