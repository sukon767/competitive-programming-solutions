#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

const ll MOD = 1e9+7;
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

vector<int> fac;
int N = 5e5;

void solve() {
    int n, x; cin >> n >> x;
    map<int, pair<int, vector<int>>> mp; //xs pfac, rest.
    vector<int> a(n); for(int& i :a) cin >> i;

    while(x>1) {
        mp[fac[x]].first++;
        x/=fac[x]; 
    }

    for(int i : a) {
        int x = i, prev = 1;
        while(x>1) {
            if(fac[x]==prev) mp[fac[x]].second.back()++;
            else mp[fac[x]].second.push_back(1);
            prev=fac[x]; x/=fac[x]; 
        }
    }

    mi ans = 1;
    for(auto& [p, pa] : mp) {
        auto&[xi, v] = pa;
        // cout << p << " " << xi << " " << *max_element(v.begin(), v.end()) << " " << count(v.begin(), v.end(), *max_element(v.begin(), v.end())) << endl;
        ans *= 1+(accumulate(v.begin(), v.end(), 0LL));
        
        // ll t1 = min(60LL, accumulate(v.begin(), v.end(), 0LL)), t2 = *max_element(v.begin(), v.end());
        // vector<vector<mi>> dp(1 + t1, vector<mi>(1 + t2)); //sum, max.
        // dp[0][0] = 1;
        // for(int i = 0; i < sz(v); i++) {
        //     for(int )
        // }
    }

    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fac = vector<int>(N+1);
    for(int i = 2; i <= N; i++) {
        if(!fac[i]) {
            for(int j = i; j <= N; j+=i) if(!fac[j]) fac[j] = i;
        }
    }

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

 /* new testament
 * nick belov always reads the entire problem statement.
 */