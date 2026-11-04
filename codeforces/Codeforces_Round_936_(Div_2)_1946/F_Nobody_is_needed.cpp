#include<bits/stdc++.h>
 
using namespace std;

using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

template <typename T> struct BIT {
    int size;
    vector<T> bit;

    BIT(int size) : size(size), bit(size + 1, 0) {}

    /** Adds val to the element at index ind. */
    void add(int ind, T val) {
        ind++;
        for (; ind <= size; ind += ind & -ind) { 
            bit[ind] += val; 
        }
    }

    /** @return The sum of all values in [0, ind]. */
    T pref_sum(int ind) {
        ind++;
        T total = 0;
        for (; ind > 0; ind -= ind & -ind) { 
            total += bit[ind]; 
        }
        return total;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n+1), pos(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) pos[a[i]] = i;
    vector<pair<pair<int, int>, int>> que(q);
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; que[i] = {{l, r}, i};
    }
    sort(que.begin(), que.end());

    vector<ll> dp(n+1, 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 2*a[i]; j <= n; j+=a[i]) {
            if(pos[j] > i) dp[pos[j]] += dp[i];
        }
    }

    int cur = 1;
    vector<ll> ans(q);
    BIT<ll> bit(n+1);
    for(int i = 1; i <= n; i++) bit.add(i, dp[i]);

    for(auto& p : que) {
        auto& [l, r] = p.first;
        while(cur < l) {
            //remove cur
            vector<ll> dpp(n/a[cur]+1); dpp[1] = 1;
            for(int i = a[cur]; i <= n; i+=a[cur]) {
                for(int j = i; j <= n; j+=i) {
                    if(pos[j] > pos[i]) dpp[j/a[cur]] += dpp[i/a[cur]];
                }
                bit.add(pos[i], -dpp[i/a[cur]]);
            }
            cur++;
        }

        ans[p.second] = bit.pref_sum(r) - bit.pref_sum(l-1);
    }

    for(ll x : ans) cout << x << " ";
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