#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// do 2 and 3.
// 1  _  3  _  5  _  7  _  9 __ 11 __ 13 __ 15
// 1  2  _  4  5  _  7  8  _ 10 11 __ 13 14 __
// 1  2  3  4  _  6  7  8  9 __ 11 12 13 14 __
// 1                 
//x and y are restricted if there exists a p such that p doesnt divide x or y. so basically just like consider p | rad(xy), and if
//rad(n) | rad(xy) then they are free. 
//but what if we have a chain. like x -> w -> y.
//

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

vector<int> lp;
vector<int> pr;

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

unordered_map<ll, pair<int, int>, custom_hash> cnt;
//cnt, mob.

// map<ll, pair<int, int>> cnt;

void cont(vector<int>& a, int v) {
    int n = sz(a);
    for(int i = 0; i < (1<<n); i++) {
        ll x = 1; int c = 0;
        for(int b = 0; b < n; b++)
            if(i>>b&1) {
                x *= a[b];
                c++;
            }
        cnt[x].f += v;
        cnt[x].s = (c&1 ? 1 : -1);
    }
}

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    for(int i = 1; i+1 <= n; i++) {
        vector<int> a, b;
        for(int j = i; j <= i+1; j++) {
            int x = j;
            while(x > 1) {
                if(!sz(a) || a.back() != lp[x]) a.push_back(lp[x]);
                x /= lp[x];
            }
            swap(a, b);
        }
        vector<int> c(sz(a) + sz(b));
        merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
        c.erase(unique(all(c)), c.end());
        cont(a, -1); cont(b, -1); cont(c, 1);
    }
    vector<mi> fac(n+1, 1), ifac(n+1, 1), p2(n+1, 1), p3(n+1, 1);
    for(int i = 2; i <= n; i++) ifac[i] = (-MOD/i)*ifac[MOD%i];
    for(int i = 1; i <= n; i++) {
        ifac[i] *= ifac[i-1];
        fac[i] = i*fac[i-1];
        p2[i] = 2*p2[i-1];
        p3[i] = 3*p3[i-1];
    }
    // cout << "asdf" << endl;
    mi ans = fac[n]*ifac[n-n/2];
    //for cont[i] = x; we need to do -mob[i]*(n!/(n-n//i)!)*(2^x).
    for(auto &p : cnt) {
        if(p.f <= 2) continue;
        auto [x, mob] = p.s;
        int c3 = (p.f&1 ? 0 : (n-1)/(p.f/2) - (n-1)/p.f);
        // cout << p.f << " " << x << " " << c3 << endl;
        ans += mob*(fac[n]*ifac[n-n/p.f])*p2[x-2*c3]*p3[c3];
        // cout << p.f << " " << x << " " << c3 << endl;

        // cout << p.f << " " << x << " " << mob << endl;
    }
    //3 2 4 ?
    //6*5*4 + 6*5 + 6 = 156
    //-6*4 - 4 - 2 + 2
    //-6*3 - 3 - 2
    //when do you ahve a run of 3? when x-1, x, x+1, so the diff is 2.
    //so its basically when you have 2q, q | x, 2q !| x. so its literally (n//q - n//(2q)).
    //
    cout << ans;
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;

    const int N = 200000;
    lp = vector<int>(N+1);

    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }

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