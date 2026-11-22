#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

template <typename T>
pair<vector<int>, vector<int>> manacher(const vector<T>& v) {
    int n = v.size();
    vector<int> d1(n), d2(n);

    // 1. Odd-length palindromes
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : std::min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && v[i - k] == v[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    // 2. Even-length palindromes
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : std::min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && v[i - k - 1] == v[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }

    return {d1, d2};
}

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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int N = 250;
const ll M = (1LL << 61) - 1;

//sukon always reads the entire problem statement.
void solve() {
    mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
    const ll B = uniform_int_distribution<ll>(0, M - 1)(rng);
    vector<ll> pow(N, 1);
    for(int i = 1; i < N; i++) pow[i] = ((__int128_t)pow[i-1]*B)%M;

    int n, m; cin >> n >> m;
    vector<vector<pair<ll, int>>> pre(n, vector<pair<ll, int>>(m));
    for(auto &v : pre) for(int i = 0; i < m; i++) {
        char c; cin >> c;
        v[i] = {pow[c-'a'], (1<<(c-'a'))};
        if(i) {
            (v[i].f += v[i-1].f) %= M;
            v[i].s ^= v[i-1].s;
        }
    }
    
    ll ans = 0;
    for(int l = 0; l < m; l++) {
        for(int r = l; r < m; r++) {
            vector<vector<ll>> hshs = {{}};
            for(int i = 0; i < n; i++) {
                int par = pre[i][r].s ^ (l?pre[i][l-1].s:0);
                if(__builtin_popcount(par) > 1) {
                    hshs.push_back({});
                    continue;
                }
                ll t = pre[i][r].f - (l?pre[i][l-1].f:0);
                ((t %= M) += M) %= M;
                hshs.back().push_back(t);
            }

            for(auto &v : hshs) {
                auto p = manacher(v);
                ans += accumulate(all(p.f), 0) + accumulate(all(p.s), 0);
            }
        }
    }
    cout << ans;
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