#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

template <typename T>
struct BIT {
    int n;
    vector<T> tree;
    
    BIT(int n) : n(n), tree(n + 1, 0) {}
    
    void add(int i, T val) {
        for (i++; i <= n; i += i & -i) {
            tree[i] = (tree[i] + val);
            // tree[i] = (tree[i] + val) % mod;
        }
    }
    
    T query(int i) {
        T sum = 0;
        for (i++; i > 0; i -= i & -i) {
            sum = (sum + tree[i]);
            // sum = (sum + tree[i]) % mod;
        }
        return sum;
    }
    
    T query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
        // return (query(r) - query(l - 1) + mod) % mod;
    }
    
    void set(int i, T val) {
        add(i, val - query(i, i));
    }

    // Returns the smallest index i such that query(i) >= val.
    // Returns n if no such index exists.
    int lower_bound(T val) {
        if (val <= 0) return 0;
        int pos = 0;
        int pw = 1 << (31 - __builtin_clz(n));
        for (; pw > 0; pw >>= 1) {
            if (pos + pw <= n && tree[pos + pw] < val) {
                pos += pw;
                val -= tree[pos];
            }
        }
        return pos;
    }
};

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
	HashedString(const string &s) : p_hash(sz(s) + 1) {
		while (sz(pow) <= sz(s)) { pow.push_back(mod_mul(pow.back(), B)); }
		p_hash[0] = 0;
		for (int i = 0; i < sz(s); i++) {
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

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    string A, B; cin >> A >> B;
    ll ans = 0;

    //others, j...n > 1...i
    for(int b = 0; b < 2; b++) {
        HashedString hA(A), hB(B);
        BIT<int> bit(n);

        
        if(b==0) {
            for(int i = 0; i < n; i++) {
                if(hA.get_hash(0, i) == hA.get_hash(n-1-i, n-1) && hB.get_hash(0, i) == hB.get_hash(n-1-i, n-1)) {
                    ans++;
                }
            }
        }

        vector<vector<int>> mxhsh(n+1);
        for(int j = 0; j < n; j++) {
            int lo = 0, hi = n-j;
            while(lo < hi) {
                int m = (lo+hi+1)>>1;
                if(hA.get_hash(j, j+m-1) == hA.get_hash(0, m-1)) lo = m;
                else hi = m-1;
            }
            if(lo) {
                bit.add(j, 1);
                mxhsh[lo].push_back(j);
            }
        }
        
        for(int i = 0; i+1 < n; i++) {
            if(hB.get_hash(0, i) == hB.get_hash(n-1-i, n-1)) {
                int lo = 0, hi = n-1-i;
                while(lo < hi) {
                    int m = (lo+hi)>>1;
                    if(hA.get_hash(m+(i+1), n-1) == hB.get_hash(m, n-1-(i+1))) hi = m;
                    else lo = m+1;
                }
                ans += bit.query(lo, n-1-(i+1));
                // cout << i << " " << lo << " " << n-1-(i+1) << " " << ans << endl;
            }
            for(int j : mxhsh[i+1]) bit.add(j, -1);
        }

        reverse(all(A)), reverse(all(B));
        swap(A, B);
    }

    cout << ans;
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