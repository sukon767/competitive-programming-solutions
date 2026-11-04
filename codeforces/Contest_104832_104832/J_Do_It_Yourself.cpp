// CutSandstone always reads the entire problem statement.
#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
using ll = long long;
const ll oo = 1e18;
template <class T> T uMin(T &a, T b) { return a = min(a, b); }
template <class T> T uMax(T &a, T b) { return a = max(a, b); }
template <typename T> struct BIT {
    int n;
    vector<T> tree;

    BIT(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, T val) {
        for (i++; i <= n; i += i & -i) {
            tree[i] += val;
        }
    }

    T query(int i) {
        T sum = 0;
        for (i++; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

    T query(int l, int r) {
        if (l > r)
            return 0;
        return query(r) - query(l - 1);
    }

    int lower_bound(T val) {
        if (val <= 0)
            return 0;
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
const int N = 5e5;
int up[N];
ll f[N];
vector<int> g[N];
priority_queue<ll> dfs(int s) {
    priority_queue<ll> ret;
    ret.push(f[s]);
    for (int i : g[s]) {
        auto c = dfs(i);
        if (c.size() > ret.size())
            swap(ret, c);
        while (c.size()) {
            ret.push(c.top());
            c.pop();
        }
    }
    for (int i = 1;; i++) {
        ll c = f[s] * (2 * i + 1);
        ret.push(c);
        ll p = ret.top();
        ret.pop();
        if (p == c)
            break;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
        cin >> up[i], up[i]--;
    for (int i = 0; i < n; i++)
        cin >> f[i];
    for (int i = n - 1; i > 0; i--)
        g[up[i]].push_back(i);
    auto ans = dfs(0);
    ll r = 0;
    for (int i = 0; i < n; i++) {
        r += ans.top();
        ans.pop();
    }
    cout << r << "\n";
}