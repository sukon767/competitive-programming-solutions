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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<ll, mi, custom_hash> iv;

//sukon always reads the entire problem statement.
void solve() {
    int n, m; cin >> n >> m;

    vector<array<int, 4>> event(n);
    vector<int> val;
    for(auto &v : event) {
        int r, d, t, w; cin >> r >> d >> t >> w;
        v = {d, w, r, t};
        val.push_back(r); val.push_back(d); val.push_back(t);
        iv[w] = mi(1)/w;
    }
    sort(all(event));
    sort(all(val)); val.erase(unique(all(val)), val.end());
    int N = sz(val);
    
    vector<mi> dp(n);
    vector<bool> vis(n);
    vector<pair<int, int>> par(N, {-1, 0});
    priority_queue<array<int, 4>, vector<array<int, 4>>> pq;
    int l = n-1;
    for(int i = N-1; i >= 0; i--) {
        // cout << val[i] << " " << l << endl;
        while(l >= 0 && event[l][0] == val[i]) {
            pq.push({event[l][1], event[l][2], event[l][3], l});
            l--;
        }
        while(sz(pq) && pq.top()[1] > val[i]) pq.pop();
        if(sz(pq)) {
            int w = pq.top()[0], t = pq.top()[2], c = pq.top()[3];
            int j = distance(val.begin(), lower_bound(all(val), t));
            // cout << i << " " << val[i] << " " << val[j] << " " << w << " " << t << endl;
            par[i] = {j, w};
            int cur = i;
            int k = 1;
            mi cp = 1;
            if(!vis[c]) {
                vis[c] = 1;
                while(par[cur].f != -1 && cp.v != 0) {
                    // cout << val[i] << " " << val[cur] << " " << cur << endl;
                    auto [nxt, weight] = par[cur];
                    mi prob = mi(min(k, weight))*iv[weight];
                    dp[c] += weight*cp*prob;
                    cp *= 1-prob; k++; cur = nxt;
                }
            }
        }
    }

    vector<mi> ans(m);
    vector<pair<int, int>> paper(m);
    for(int i = 0; i < m; i++) {
        cin >> paper[i].f; paper[i].s = i;
    } 
    sort(all(paper));
    l = n-1;
    while(sz(pq)) pq.pop();

    for(int i = m-1; i >= 0; i--) {
        while(l >= 0 && event[l][0] >= paper[i].f) {
            pq.push({event[l][1], event[l][2], event[l][3], l});
            l--;
        }
        while(sz(pq) && pq.top()[1] > paper[i].f) pq.pop();
        if(sz(pq)) {
            ans[paper[i].s] = dp[pq.top()[3]];
        }
    }

    for(auto &x : ans) cout << x << "\n";
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