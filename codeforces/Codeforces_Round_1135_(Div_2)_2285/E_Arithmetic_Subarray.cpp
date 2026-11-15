#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    static uint64_t hash_comb(uint64_t a, uint64_t b) {
        return splitmix64(a*31 + b);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(const pair<ll, ll>& x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(hash_comb(splitmix64(x.f + FIXED_RANDOM), splitmix64(x.s + FIXED_RANDOM)));
    }
};

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

//sukon always reads the entire problem statement.
void solve() {
    int n, k; cin >> n >> k;
    vector<array<ll, 3>> prs; prs.reserve(2*(k+1)*n);
    vector<ll> a(n); for(ll &i : a) cin >> i;
    for(int i = n-1; i >= 0; i--) {
        for(int j = i+1; j <= min(n-1, i+k+1); j++) {
            if((a[j]-a[i])%(j-i)) continue;
            ll d = (a[j]-a[i])/(j-i);
            ll ac = a[i] - i*d;
            prs.push_back({ac, d, i});
            prs.push_back({ac, d, j});
        }
    }

    sort(all(prs)); prs.erase(unique(all(prs)), prs.end());

    // do it
    int ans = k+2;
    int i = 0;
    while(i < sz(prs)) {
        int j = i;
        while(j < sz(prs) && prs[j][0] == prs[i][0] && prs[j][1] == prs[i][1]) {
            while((prs[j][2]-prs[i][2]+1) - (j-i+1) > k) i++;
            ans = max(ans, k + (j-i+1));
            j++;
        }
        i = j;
    }
    cout << min(ans, n);
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