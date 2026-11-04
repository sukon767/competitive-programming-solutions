#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> p;
    vector<int> a;
    for(int i = 0; i < n; i++) if(s[i] == '*') a.push_back(i); else if(s[i] == 'P') p.push_back(i);
    int lo = 0, hi = 2*n;
    while(lo < hi) {
        int m = (lo+hi)>>1;
        int l = 0;
        for(int i = 0; i < sz(p); i++) {
            int r = l;
            while(r < sz(a) && (max(0, p[i]-a[l]) + max(0, a[r] - p[i]) + min(max(0, p[i]-a[l]), max(0, a[r] - p[i]))) <= m) {
                r++;
            }
            l = r;
        }
        if(l < sz(a)) lo = m+1;
        else hi = m;
    }
    cout << lo;
}

//king of the sun o_O
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */