#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
ll MOD = 998244353;
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
 
 
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); for(int &i : a) cin >> i;
    vector<int> k(m); for(int &i : k) cin >> i;
 
    vector<pair<int, int>> ind;
    for(int i = 0; i < n; i++) ind.push_back({a[i], i});
    sort(ind.begin(), ind.end());
 
    vector<pair<int, int>> bd(n);
    set<int> cur;
 
    for(int i = 0; i < n; i++) {
        int x = ind[i].second;
        auto it = cur.lower_bound(x);
 
        if(it == cur.end()) bd[x].second = n-1;
        else bd[x].second = (*it)-1;
 
        
        if(it == cur.begin()) bd[x].first = 0;
        else {
            --it;
            bd[x].first = (*it) + 1;
        }
 
        cur.insert(x);
    }

    vector<mi> cnt(n);
    for(int i = 0; i < n; i++) {
        cnt[i] = mi(i-bd[i].first+1)*(bd[i].second-i+1);
    }
 
    vector<int> ans(m);
    mi x = 0;
    mi c = 0;
    vector<mi> den(n);
    for(int i = 0; i < n; i++) den[i] = mi(1)/a[i];

    for(int i = 0; i < n; i++) {
        c += den[i]*cnt[i]; x += den[i]*cnt[i];
        c += den[i]*(mi(i+1)*(n-i) - cnt[i]);
    }

    int l = 0;
    for(int i = 0; i < m; i++) {
        while(l < n && k[i] >= ind[l].first) {
            mi eff = cnt[ind[l].second];
            c -= den[ind[l].second]*eff; x -= den[ind[l].second]*eff;
            c += (2 - ind[l].first)*eff; x += 1*eff;
            l++;
        }

        cout << x*k[i] + c << "\n";
    }
    
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
