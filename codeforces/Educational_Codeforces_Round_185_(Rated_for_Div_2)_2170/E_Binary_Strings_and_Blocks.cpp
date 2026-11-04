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

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> con;
    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        con.push_back({l, r});
    }

    sort(con.begin(), con.end(), [&](const auto& a, const auto& b) {
        if(a.first == b.first) return a.second > b.second; 
        return a.first < b.first;
    });

    vector<pair<int, int>> temp;
    for (auto& cur : con) {
        while (!temp.empty() && cur.second <= temp.back().second) {
            temp.pop_back();
        }
        temp.push_back(cur);
    }
    con = temp;

    vector<mi> p2(n+1), ip2(n+1); p2[0] = 1; ip2[0] = 1; ip2[1] = mi(1)/2;
    for(int i = 1; i <= n; i++) {
        p2[i] = p2[i-1]*2;
        if(i > 1) ip2[i] = ip2[i-1]*ip2[1];
    }

    vector<vector<mi>> dp(n+1, vector<mi>(2)), pre(n+1, vector<mi>(2)), prew(n+1, vector<mi>(2));
    dp[0][0] = 1; pre[0][0] = 1; prew[0][0] = p2[n];
    int on = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 2; j++) {
            pre[i][j] = pre[i-1][j];
            prew[i][j] = prew[i-1][j];
        }

        while(on < sz(con) && con[on].second < i) on++;
        if(on < sz(con) && con[on].second == i) {
            //update dp and pre.
            auto& [l, r] = con[on];
            for(int j = 0; j < 2; j++) {
                dp[i][j] += prew[l-1][j^1]*ip2[n-l+1]*2 + (pre[r][j^1]-pre[l-1][j^1]);
            }
            for(int j = 0; j < 2; j++) {
                pre[i][j] += dp[i][j];
                prew[i][j] += dp[i][j]*p2[n-i];
            }
        }

        // cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
        // cout << prew[i][0] << " " << prew[i][1] << endl;
    }

    cout << prew[n][0]-prew[n][1];
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