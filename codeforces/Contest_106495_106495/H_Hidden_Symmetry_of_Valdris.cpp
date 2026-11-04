#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        if(i <= r) {
            p[i] = min(r - i, p[l + (r - i)]);
        }
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    p = vector<int>(begin(p) + 1, end(p) - 1);
    for(int &x : p) x >>=1;
    return p; 
}
vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

//sukon always reads the entire problem statement.
void solve() {
    string a, b; cin >> a >> b;
    int n = sz(a);
    ll ans = 0;
    for(int t = 0; t < 2; t++) {
        vector<int> ma = manacher(a), mb = manacher(b);
        vector<int> p(n);
        for(int i = 0; i < 2*n-1; i++) {
            int m = (i+1)>>1;
            p[m]++;
            int dm = m+min(ma[i], mb[i]);
            if(dm < n) p[dm]--;
        }
        partial_sum(all(p), p.begin());

        for(int i = 0; i < n; i++) {
            if(a[i] != b[n-1-i] || b[i] != a[n-1-i]) break;
            if(!t) ans++;
            if(i <= n-2) ans += p[n-2-i];
        }
        reverse(all(a)); reverse(all(b));
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