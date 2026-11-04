#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    ll n, r; cin >> n >> r;
    ll hori = (ll)ceil((ld)r * sqrtl(3));

    
    vector<pair<ll, ll>> circ, pts(n);
    for(auto &p : pts) {
        cin >> p.first >> p.second;
        ll x = p.first, y = p.second;
        //find closest odd and even and choose
        ll y1 = p.second/(2*r)*(2*r);
        vector<ll> cont = {y1 + 2*r, y1 - 2*r};
        for(ll s : cont) {
            if(abs(y - s) < abs(y - y1)) y1 = s;
        }
        ll x1 = p.first/(2*hori)*(2*hori);
        cont = {x1 + 2*hori, x1 - 2*hori};
        for(ll s : cont) {
            if(abs(x - s) < abs(x - x1)) x1 = s;
        }

        if((y-y1)*(y-y1) + (x-x1)*(x-x1) <= r*r) {
            circ.push_back({x1, y1}); continue;
        }

        //odd

        y1 = (p.second-r)/(2*r)*(2*r) + r;
        cont = {y1 + 2*r, y1 - 2*r};
        for(ll s : cont) {
            if(abs(y - s) < abs(y - y1)) y1 = s;
        }
        x1 = (p.first-hori)/(2*hori)*(2*hori) + hori;
        cont = {x1 + 2*hori, x1 - 2*hori};
        for(ll s : cont) {
            if(abs(x - s) < abs(x - x1)) x1 = s;
        }

        if((y-y1)*(y-y1) + (x-x1)*(x-x1) <= r*r) {
            circ.push_back({x1, y1}); continue;
        }
    }


    sort(circ.begin(), circ.end());
    circ.erase(unique(circ.begin(), circ.end()), circ.end());
    cout << circ.size() << endl;
    for(auto &p : circ) cout << p.first << " " << p.second << "\n";
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */