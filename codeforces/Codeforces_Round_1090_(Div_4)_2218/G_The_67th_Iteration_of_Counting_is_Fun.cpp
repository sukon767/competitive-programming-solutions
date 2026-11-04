#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
ll MOD = 676767677;
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
    mi ans = 1;

    vector<vector<int>> t(m);
    for(int i = 0; i < n; i++) t[a[i]].push_back(i);

    vector<int> pre(m);
    pre[0] = t[0].size();
    for(int i = 1; i < m; i++) pre[i] = pre[i-1] + t[i].size();

    for(int i = 1; i < m; i++) {
        for(int x : t[i]) {
            //greater than cur, but leq cur+t[i-1].size()
            if((x && a[x-1] < i) || (x < n-1 && a[x+1] < i)) {
                //t[i] - t[max left right -1
                int y = INT_MAX;
                if(x && a[x-1] < i) y = min(y, a[x-1]);
                if(x < n-1 && a[x+1] < i) y = min(y, a[x+1]);
                int mul = pre[i-1];
                if(y != i-1 && i >= 2) mul -= pre[i-2];
                ans *= mul;

                // cout << i << " " << y << " " << mul << endl;
            } else {
                // cout << "ASS" << endl;
                cout << 0; return;
            }
        }
    }

    cout << ans;
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