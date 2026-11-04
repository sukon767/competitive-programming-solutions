#include <vector>
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
ostream_iterator<T> oit(const string &s = " "){ return ostream_iterator<T>(cout,s.c_str()); }
inline auto rep(int l, int r) { return views::iota(min(l, r), r); }
inline auto rep(int n) { return rep(0, n); }
inline auto rep1(int l, int r) { return rep(l, r + 1); }
inline auto rep1(int n) { return rep(1, n + 1); }
inline auto per(int l, int r) { return rep(l, r) | views::reverse; }
inline auto per(int n) { return per(0, n); }
inline auto per1(int l, int r) { return per(l, r + 1); }
inline auto per1(int n) { return per(1, n + 1); }
inline auto len = ranges::ssize;

#define A(a) begin(a),end(a)
#define pb push_back
#define pp partition_point
#define K first
#define V second
#define krep(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (size(x))

template<typename T>
void mkunq(vector<T> &v){
    ranges::sort(v),v.resize(unique(A(v))-v.begin());
}
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.first >> data.second;
    return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.first << "," << data.second << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
struct chash {
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
template<typename T, typename U> using pb_map = gp_hash_table<T, U, chash>;
template<typename T> using pb_set = gp_hash_table<T, null_type, chash>;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vll =  vector<ll>;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
template<class T> bool ckmin(T& a, const T& b) { return b < a ? (a = b, 1) : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? (a = b, 1) : 0; }
inline long long Bit(long long mask, long long bit) { return (mask >> bit) & 1; }


constexpr ll NN = 2e5, M = 1000000007, L = 20;

ll f1[NN], f2[NN];
ll inv(ll a, ll b=M) { return 1 < a ? b - inv(b % a, a) * b / a : 1; } // inv a mod b
ll choose(ll n, ll k) { return f1[n] * f2[k] % M * f2[n - k] % M; } // n choose k
constexpr ll oo = 1e15;
void run()
{
    ll n,m,k; cin >> n >> m >> k;

    vll a(n); for(ll &x : a) cin >> x,--x;

    vector<vector<array<ll,2>>> adj(n);
    for(ll u,v; int _ : rep(m)){
        ll w = 1;
        cin >> u >> v,--u,--v;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    vll dp(n,oo);
    priority_queue<pll,vector<pll>,greater<>> pq; pq.push({0,0});
    dp[0]=0;
    while(not pq.empty()){
        auto [d,i] {pq.top()}; pq.pop();
        if(d > dp[i]) continue;
        for(auto [j,w] : adj[i]) if(d+w < dp[j]) dp[j]=d+w,pq.emplace(d+w,j);
    }

    vll ans(k,-1);
    for(int i : rep(n)) ckmax(ans[a[i]],dp[i]);
    cout << ans << '\n';
}

int main()
{
    //KING OF THE WORLD...... U.W.T.B
    //nick belov always reads the entire problem statement.
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    run();
}