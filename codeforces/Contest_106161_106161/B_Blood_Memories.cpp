#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

template <typename T>
vector<vector<T>> matMul(const vector<vector<T>>& a, const vector<vector<T>>& b) {
    assert(sz(a) && sz(b) && sz(a[0]) && sz(b[0]) && sz(a[0]) == sz(b));
    vector<vector<T>> ans(sz(a), vector<T>(sz(b[0])));
    for(int i = 0; i < sz(a); i++) {
        for(int j = 0; j < sz(b[0]); j++) {
            for(int k = 0; k < sz(b); k++) {
                ans[i][j] = max(ans[i][j], a[i][k]+b[k][j]);
            }
        }
    }
    return ans;
}

template <typename T>
vector<vector<T>> matExp(vector<vector<T>> a, ll N) {
    int n = sz(a);
    assert(n && n == sz(a[0]));
    vector<vector<T>> ans(n, vector<T>(n));
    // for(int i = 0; i < n; i++) ans[i][i] = 1;
    while(N) {
        if(N&1) ans = matMul(ans, a);
        a = matMul(a, a);
        N>>=1;
    }
    return ans;
}

//sukon always reads the entire problem statement.
void solve() {
    int n, m, k, R; cin >> n >> m >> k >> R;
    vector<pair<int, int>> ac(n); for(auto &p : ac) cin >> p.f >> p.s;
    vector<vector<ll>> A((1<<n), vector<ll>(1<<n)); 
    for(int i = 0; i < (1<<n); i++) {
        for(int j = 0; j < (1<<n); j++) {
            // cout << i << " " << j << endl;
            //for using subset i, j is cost subset.
            ll damage = 0;
            ll cost = 0;
            for(int b = 0; b < n; b++) {
                if(i>>b&1) {
                    damage += ac[b].f;
                    cost += ac[b].s + ((j>>b&1) ? k : 0);
                }
            }
            if(cost <= m) A[i][j] = damage;
        }
    }

    // cout << "asdf" << endl;
    A = matExp(A, R);
    vector<vector<ll>> ans(1<<n, vector<ll>(1));
    ans = matMul(A, ans);
    ll x = 0; for(int i = 0; i < 1<<n; i++) x = max(x, ans[i][0]);
    cout << x;
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