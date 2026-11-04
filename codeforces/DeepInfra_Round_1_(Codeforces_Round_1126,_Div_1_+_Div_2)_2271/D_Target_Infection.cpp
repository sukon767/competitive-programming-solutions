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
    ll n, m, k; cin >> n >> m >> k;
    vector<pair<ll, ll>> ivl(n);
    vector<pair<ll, ll>> upd;
    ll dx = 0;
    ll amt = 0;
    for(auto &[l, r] : ivl) {
        cin >> l >> r;
        // cout << l << " " << r << endl;
        upd.push_back({r+1, 1});
        upd.push_back({l, -1});
        upd.push_back({r-(m-1), -1});
        upd.push_back({l-1-(m-1), 1});
    }
    sort(all(upd));

    // for(auto &p : upd) cout << p.f << " " << p.s << endl;

    //just do it style
    ll i = sz(upd)-1;
    while(i >= 0) {
        ll cur = upd[i].f;
        // cout << cur << " " << amt << " " << dx << endl;
        while(i>=0 && upd[i].f == cur) {
            dx += upd[i].s; i--;
        }
        // cout << cur << " " << amt << " " << dx << " " << i << " " << endl;
        // if(i>=0) cout << upd[i].f << endl;
        //if between, then u do the shi
        //amt + dx*(moving) = k and moving <= cur-upd[i-1].f
        
        if(i>=0) {
            if(dx) {
                ll moving = (k-amt)/dx;
                if(0 <= moving && moving <= cur-upd[i].f) {
                    cout << (cur-moving);
                    return;
                }
            }
            amt += dx*(cur-upd[i].f);
        }
    }
    cout << -1;
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