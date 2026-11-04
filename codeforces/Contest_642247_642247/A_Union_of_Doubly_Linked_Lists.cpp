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
    vector<pair<int, int>> lr(n);
    for(auto &p : lr) {cin >> p.f >> p.s; p.f--, p.s--;}
    vector<bool> dn(n, 0);
    int on = 0;
    while(lr[on].f != -1) on++;
    dn[on] = 1;
    int pt = 0;
    while(pt < n) {
        // cout << on << endl;
        if(lr[on].s != -1) {
            // cout << "to " << lr[on].s << endl;
            on = lr[on].s;
        } else {
            while(pt < n && (dn[pt] || lr[pt].f != -1)) pt++;
            if(pt < n) {
                lr[on].s = pt;
                lr[pt].f = on;
                on = pt;
            }
        }
        dn[on] = 1;
    }
    for(auto &p : lr) cout << (p.f+1) << " " << (p.s+1) << endl;
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