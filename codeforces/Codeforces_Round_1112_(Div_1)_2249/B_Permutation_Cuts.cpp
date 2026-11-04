#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

const ll MOD = 998244353;
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

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    vector<int> a(n-1); for(int& i : a) cin >> i, i--;
    if(*max_element(all(a)) == n-1) {
        cout << 0; return;
    }

    int lm = n-2;
    for(int i = 0; i+1 < n-1; i++) {
        if(a[i] > a[i+1]) {
            lm = i; break;
        }
    }

    int rm = 0;
    for(int i = n-2; i > 0; i--) {
        if(a[i] > a[i-1]) {
            rm = i; break;
        }
    }

    if(a[lm] != a[rm]) {
        cout << 0; return;
    }


    mi ans = 1;
    vector<vector<int>> inds(n);
    for(int i = 0; i < n-1; i++) {
        inds[a[i]].push_back(i);
    }

    int tak = 0;
    for(int i = 0; i < n; i++) {
        if(!sz(inds[i])) continue;
        for(int j = 0; j+1 < sz(inds[i]); j++) {
            if(inds[i][j]+1 != inds[i][j+1]) {
                cout << 0; return;
            }
            ans *= i-tak;
            tak++;
        }
        tak++;
    }

    cout << 2*ans;
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