#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    int n, k; cin >> n >> k;
    vector<ll> x(n); for(auto& i : x) cin >> i;
    vector<ll> pre(n); partial_sum(all(x), pre.begin());
    //dp[i][j] = over l < i of dp[l][j-1] + C(l+1, i).

    vector<ll> prev(n, LLONG_MAX);
    for(int t = 1; t <= k; t++) {
        vector<ll> cur(n, LLONG_MAX);
        auto dnc = [&](auto&&self, int l, int r, int lo, int hi) {
            if(l > r) return;
            int m = (l+r)>>1;
            // if(t==1 && m==1)cout << t << " " << l << " " << r << " " << lo << " " << hi << endl;
            pair<ll, int> best = {LLONG_MAX, -1};
            for(int i = lo; i <= min(hi, m-1); i++) {
                ll pi = (i>=0?prev[i]:0);
                if(pi == LLONG_MAX) continue;
                ll test = pi;
                ll mid = (m + i+1)/2;
                if(i+1 <= mid-1) test += x[mid]*(mid-1-i) - (pre[mid-1] - (i>=0?pre[i]:0));
                if(mid+1 <= m) test += (pre[m] - pre[mid]) - x[mid]*(m - mid);
                best = min(best, pair<ll, int>{test, i});
            }
            cur[m] = best.f;
            self(self, l, m-1, lo, best.s); self(self, m+1, r, best.s, hi);
        };
        dnc(dnc, t-1, n-1, t-2, n-2);
        // for(ll x : cur) cout << x << " ";
        // cout << endl;
        prev = cur;
    }

    cout << prev.back();
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