#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
// Extended Euclidean Algorithm
array<ll, 3> extend_euclid(ll a, ll b) {
	// we know that (1 * a) + (0 * b) = a and (0 * a) + (1 * b) = b
	array<ll, 3> x = {1, 0, a};
	array<ll, 3> y = {0, 1, b};

	while (y[2] > 0) {
		// keep subtracting the multiple of one equation from the other
		ll k = x[2] / y[2];
		for (int i = 0; i < 3; i++) { x[i] -= k * y[i]; }
		swap(x, y);
	}
	return x;  // x[0] * a + x[1] * b = x[2], x[2] = gcd(a, b)
}

// The Modular Inverse
ll inv(ll x, ll y) {
	ll m = extend_euclid(x, y)[0] % y;
	return (m < 0 ? m + y : m);
}

// General code for multiple congruences in a system
ll crt(const vector<ll> &remainders, const vector<ll> &moduli) {
	ll MOD = accumulate(moduli.begin(), moduli.end(), 1LL, multiplies<ll>());
	ll x = 0;
	for (int i = 0; i < (int)moduli.size(); i++) {
		ll a = remainders[i] * inv(MOD / moduli[i], moduli[i]) % moduli[i];
		x = (x + a * (MOD / moduli[i])) % MOD;
	}
	return x;
}

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> c(2*max(n, m), {-1, -1});
    for(int i = 0; i < n; i++) {int u; cin >> u; c[--u].first = i;}
    for(int i = 0; i < m; i++) {int u; cin >> u; c[--u].second = i;}

    // auto pp = crt({3, 1}, {4, 2});
    // cout << pp.first << " " << pp.second << endl;

    vector<ll> res = {-1};
    ll g = gcd(n, m), l = n/g*m;
    // for(int i = 0; i < 2*max(n, m); i++) cout << i << " " << c[i].first << " " << c[i].second << endl;

    for(int i = 0; i < 2*max(n, m); i++) {
        if(c[i].first != -1 && c[i].second != -1) {
            if(c[i].first %g != c[i].second%g) continue;
            ll r = crt({c[i].first/g, c[i].second/g}, {n/g, m/g});
            res.push_back((r*g + c[i].first%g)%l);
            // cout << i << endl;
        }
    }
    res.push_back(l);
    // cout << "adfk" << endl;

    sort(res.begin(), res.end());
    // for(int r : res) cout << r << " ";
    // cout << endl;

    ll ans = (k-1)/(l - (res.size()-2))*l; k -= (k-1)/(l - (res.size()-2))*(l - (res.size()-2));

    for(int i = 0; i <= res.size(); i++) {
        if(k > res[i+1] - res[i]-1) k -= res[i+1] - res[i]-1;
        else {ans += res[i] + k + 1; break;}
    }

    cout << ans;
}
 
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