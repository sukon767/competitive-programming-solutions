#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

const ll MOD = 998244353;

ll pw(ll x, ll k = MOD-2, ll p = MOD) {
    ll r = 1;
    while (k) {
        if (k & 1) r = r * x % p;
        x = x * x % p;
        k >>= 1;
    }
    return r;
}
const ll G = 3, GIV = pw(G);
const int Nntt = 1 << 19;
//MUST COMPUTE THIS
ll iv[Nntt + 1];
void ntt(vector<ll> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = pw(invert ? GIV : G, (MOD - 1) / len);
 
        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i + j];
                ll v = (a[i + j + len / 2] * w) % MOD;
 
                a[i + j] = (u + v < MOD ? u + v : u + v - MOD);
                a[i + j + len / 2] = (u - v >= 0 ? u - v : u - v + MOD);
 
                w = w * wlen % MOD;
            }
        }
    }
    if (invert) {
        ll n_inv = iv[n];
        for (ll &x : a)
            x = x * n_inv % MOD;
    }
}
vector<ll> multiply(vector<ll> a, vector<ll> b) {
    int n = 1;
    while (n < sz(a) + sz(b))
        n <<= 1;
    a.resize(n, 0);
    b.resize(n, 0);
    ntt(a, false);
    ntt(b, false);
    vector<ll> c(n);
    for (int i = 0; i < n; i++)
        c[i] = (a[i] * b[i]) % MOD;
    ntt(c, true);
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    for(ll& x : c) x = (x+MOD)%MOD;
    return c;
}
//MUST COMPUTE THE INVERSE ARRAY (don'r forget to MOD)

//sukon always reads the entire problem statement.
void solve() {
    int n, k, f; cin >> n >> k >> f;
    iv[1] = 1;
    for(int i = 2; i <= Nntt; i++) iv[i] = (MOD-MOD/i)*iv[MOD%i]%MOD;
    vector<ll> dp(k+1, 1);
    while(n--) {
        vector<ll> nxt = multiply(dp, dp);
        if(n) {
            ll tot = 0; for(ll x : nxt) (tot += x) %= MOD;
            if(sz(nxt) > k+1) nxt.resize(k+1);
            for(int i = 0; i < sz(nxt); i++) {
                (tot += MOD-nxt[i]) %= MOD;
                (nxt[i] *= k-i+1) %= MOD;
                (nxt[i] += tot) %= MOD;
            }
        }
        dp = nxt;
    }
    
    cout << (f+1 <= sz(dp) ? dp[f] : 0);
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