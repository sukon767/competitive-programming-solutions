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

void solve(int cc) {
    int n; cin >> n;
    vector<int> a(n);
    int s = 0;    
    for(int &i : a) {cin >> i; if(!s) {if(i == 1) s = 1; else if(i == n) s = 2;}}
    if(s == 2) reverse(a.begin(), a.end());

    // if(cc == 7646-282) {
    //     for(int x : a) cout << x << " ";
    // }
    // if(cc > 10) return;
    
    int i1, in;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) i1 = i;
        else if(a[i] == n) in = i;
    }

    int t1, t2;

    vector<mi> fac(n+1); fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = fac[i-1]*i;

    set<vector<int>> r;

    if((in - i1)%2) {

        int c = i1+2;
        int cr = 1;
        while(c < n) {
            //.second is type, .first is order in type, a[c] is gen order.
            //so we need r[a[c]-2] to store type + order
            //r.insert({a[c]-1, cr, 1})
            if(a[c]) r.insert({a[c]-1, cr, 1});
            c+=2; cr++;
        }
        if(c == n+1) c = n-2;
        else c = n-1;
        while(a[c] != n) {
            if(a[c]) r.insert({a[c]-1, cr, 1});
            c-=2; cr++;
        }

        t1 = cr-1;

        c = i1-2;
        cr = 1;
        while(c >= 0) {
            // cout << c << endl;
            if(a[c]) r.insert({a[c]-1, cr, 2});
            c-=2; cr++;
        }
        if(c == -2) c = 1;
        else c = 0;
        while(a[c] != n) {
            // cout << c << endl;
            if(a[c]) r.insert({a[c]-1, cr, 2});
            c+=2; cr++;
        }

        t2 = cr-1;
        
    } else {

        int c = i1+2;
        int cr = 1;
        while(a[c] != n) {
            if(a[c]) r.insert({a[c]-1, cr, 1});
            c+=2; cr++;
        }

        t1 = cr-1;

        c = i1-2;
        cr = 1;
        while(c >= 0) {
            if(a[c]) r.insert({a[c]-1, cr, 2});
            c-=2; cr++;
        }
        if(c == -2) c = 1;
        else c = 0;
        while(c < n) {
            if(a[c]) r.insert({a[c]-1, cr, 2});
            c+=2; cr++;
        }

        if(c == n+1) c = n-2;
        else c = n-1;
        while(a[c] != n) {
            if(a[c]) r.insert({a[c]-1, cr, 2});
            c-=2; cr++;
        }

        t2 = cr-1; 

    }

    vector<vector<int>> rt;
    int last = INT_MIN;

    for(auto x : r) {
        if(x[2] == 2) {
            rt.push_back({x[0], x[0]-x[1], 2});
        } else rt.push_back({x[0], x[1], 1});
    }

    // for(auto x : r) cout << x[0] << " " << x[1] << " " << x[2] << endl;
    // for(auto x : rt) cout << x[0] << " " << x[1] << " " << x[2] << endl;
    // cout << t1 << " " << t2 << endl;
    vector<int> ss = {0, t1, t2};

    if(!rt.size()) {cout << fac[n-2]/fac[t1]/fac[t2]; return;}

    mi ans = 1;
    vector<int> prev(3), t;
    for(int i = 0; i < rt.size(); i++) {
        int N, R;
        if(!i) {N = rt[i][0]-1; R = rt[i][1];}
        else {N = rt[i][0]-1-rt[i-1][0]; R = rt[i][1]-rt[i-1][1];}
        if(rt[i][2] == 1) R--;
        // cout << N << " " << R << " NR" << endl;
        if(N < 0 || R < 0 || N-R < 0) {cout << 0; return;}
        ans *= fac[N]/fac[R]/fac[N-R];
        // cout << ans << " ans" << endl;
    }

    int N = n-2-rt.back()[0], R = t1-rt.back()[1];
    // cout << N << " " << R << " NR" << endl;
    if(N < 0 || R < 0 || N-R < 0) {cout << 0; return;}
    ans *= fac[N]/fac[R]/fac[N-R];

    cout << ans;

    // while(it != r.end()) {
    //     t = *it;
    //     // cout << f << endl;
    //     cout << t[0]-f-1 << " " << t[1]-prev[t[2]]-1 << endl;
    //     if(t[0]-f-1 < 0 || t[1]-prev[t[2]]-1 < 0 || t[1]-prev[t[2]] > t[0]-f) {cout << 0; return;}
    //     ans *= fac[t[0]-f-1]/fac[t[1]-prev[t[2]]-1]/fac[(t[0]-f) - (t[1]-prev[t[2]])];
    //     prev[t[2]] = t[1];
    //     f = prev[1] + prev[2];
        
    //     it++;
    // }
    // int fl = ss[t[2]]-t[1]; int buck = n-2-t[0];
    // if(fl < 0 || buck < 0 || buck-fl < 0) {cout << 0; return;}
    // ans *= fac[buck]/fac[fl]/fac[buck-fl];

}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve(t);
        if(t != 0)   cout << "\n";
    }
}