#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (ll)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

const ll mod = 1e9+7;
const ll inv2 = (mod+1)/2;

void xormul(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
	ll m = (ll) a.size();
	c.resize(m);
	if (m == 1) {
		c[0] = a[0] * b[0] % mod;
		return;
	}
	vector<ll> ap, bp, an, bn;
	for (ll i = 0; i < m / 2; i++) {
		ap.push_back((a[i] + a[i + m / 2]) % mod);
		bp.push_back((b[i] + b[i + m / 2]) % mod);
		an.push_back((a[i] - a[i + m / 2] + mod) % mod);
		bn.push_back((b[i] - b[i + m / 2] + mod) % mod);
	}
	vector<ll> d0, d1;
	xormul(ap, bp, d0);
	xormul(an, bn, d1);
	for (ll i = 0; i < m / 2; i++) {
		c[i] = (d0[i] + d1[i]) * inv2 % mod;
		c[i + m / 2] = (d0[i] - d1[i] + mod) * inv2 % mod;
	}
}

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    for(ll i = 2; i <= n; i++) {
        cout << "XOR 1 " << i << endl;
        cin >> a[i-1];
    }

    vector<ll> b(n);
    for(ll i = 0; i < n; i++) b[a[i]]++;

    vector<ll> c;
    xormul(b, b, c);
    c[0] -= n;
    vector<ll> dp(n, -1);
    for(ll i = 0; i < n; i++) {
        if(c[i]) dp[i] = i;
        for(ll b = 1; b < n; b<<=1) dp[i|b] = max(dp[i|b], dp[i]);
    }

    ll x, y;
    for(ll i = 0; i < n; i++) {
        if(dp[i]!=-1 && dp[i^(n-1)]!=-1) {
            x = dp[i], y = dp[i^(n-1)];
            break;
        }
    }

    pair<ll, ll> p1, p2;
    vector<ll> mp(n);
    for(ll i = 0; i < 2; i++) {
        for(ll j = 0; j < n; j++) {
            if(mp[a[j]^x]) {p1 = {mp[a[j]^x]-1, j}; break;}
            mp[a[j]] = j+1;
        }
        fill(all(mp), 0); swap(p1, p2); swap(x, y);
    }

    ll a0 = 0;
    for(ll i = 0; i < 2; i++) {
        cout << "AND " << p1.f+1 << " " << p1.s+1 << endl;
        ll z; cin >> z;
        for(ll b = 1; b < n; b<<=1) {
            if((x&b)==0) a0 |= ((z&b)^(a[p1.f]&b));
        }
        swap(p1, p2); swap(x, y);
    }
    cout << "!";
    for(ll x : a) cout << " " << (x^a0);
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ll t; cin >> t;
    ll t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}

/* benq's 5 commandments
 * ll overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */

 /* new testament
 * nick belov always reads the entire problem statement.
 */