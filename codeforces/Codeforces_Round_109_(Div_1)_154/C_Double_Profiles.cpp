#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

constexpr long long MAX_VAL = 1e18;

/** @return a random integer between 0 and MAX_VAL */
long long rng() {
	static std::mt19937_64 gen(
	    std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<long long>(0, MAX_VAL)(gen);
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

//sukon always reads the entire problem statement.
void solve() {
    int n, m; cin >> n >> m;
    vector<ll> hsh(n); for(auto &i : hsh) i = rng();
    vector<ll> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[--u]^=hsh[--v];
        adj[v]^=hsh[u];
    }
    gp_hash_table<ll, ll, custom_hash> mp;
    for(int i = 0; i < n; i++) {
        mp[adj[i]]++;
        mp[adj[i]^hsh[i]]++;
    }

    ll ans = 0;
    for(auto [_, v] : mp) ans += v*(v-1)/2;
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