#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

class HashedString {
  private:
	// change M and B if you want
	static const ll M = (1LL << 61) - 1;
	static const ll B;

	// pow[i] contains B^i % M
	static vector<ll> pow;

	// p_hash[i] is the hash of the first i characters of the given string
	vector<ll> p_hash;

	__int128 mul(ll a, ll b) { return (__int128)a * b; }
	ll mod_mul(ll a, ll b) { return mul(a, b) % M; }

  public:
	HashedString(const string &s) : p_hash(s.size() + 1) {
		while (pow.size() < s.size()) { pow.push_back(mod_mul(pow.back(), B)); }
		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
		}
	}

	ll get_hash(int start, int end) {
		ll raw_val = p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
		return (raw_val + M) % M;
	}
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<ll> HashedString::pow = {1};
const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);


void solve() {
    ll n, l, k; cin >> n >> l >> k;
    string s; cin >> s;

    if(k == 1) {
        if(l <= n) {
            cout << "YES\n" << s;
        } else cout << "NO";
        return;
    }

    HashedString hs(s);
    vector<pair<int, int>> cont;

    
    for(int i = 0; i < n; i++) {
        if(i && !(i/l)) continue;
        ll r = min(n-1, n-l*(k-(i/l+1))-1);
        if(r-i+1 >= l) cont.push_back({i, r});
    }
    if(!cont.size()) {cout << "NO"; return;}

 
    // for(auto &p : cont) cout << p.first << " " << p.second << endl;
    
    int cur = 0;
    for(int i = 1; i < cont.size(); i++) {
        //compare
        pair<int, int> a = cont[cur], b = cont[i];

        int sub = min(a.second-a.first+1, b.second-b.first+1);
        int l = 0, r = sub;

        while(l < r) {
            int m = (l+r+1)>>1;
            if(hs.get_hash(a.first, a.first+m-1) == hs.get_hash(b.first, b.first+m-1)) l = m;
            else r = m-1;
        }

        if(l == sub) {
            if(b.second-b.first+1 > a.second-a.first+1) cur = i;
        } else {
            if(s[a.first+l] < s[b.first+l]) cur = i;
        }
        // cout << l << " " << a.first << " " << b.first << " " << i << " " << cur << endl;
    }

    cout << "YES\n";
    cout << s.substr(cont[cur].first, cont[cur].second-cont[cur].first+1);
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