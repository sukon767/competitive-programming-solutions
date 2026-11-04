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
    ll n, k; cin >> n >> k;
    if(n==2) {
        if(k!=2) {cout << -1; return;}
        cout << 1 << " " << 2 << "\n";
        return;
    }
    if(k%2) {cout << -1; return;}
    k>>=1;
    if(k < n-1) {cout << -1; return;}
    ll on = 1; ll ck = n-1;
    while(n-1-2*on > 0 && ck + n-1-2*on <= k) {
        ck += n-1-2*on; on++;
    }
    ll r = k-ck;
    if(n-1-2*on <= 0 && r > 0) {
        cout << -1; return;
    }
    vector<pair<ll, ll>> ans;
    for(int i = 0; i <= on-1; i++) {
        ans.push_back({max(1, 2*i), 2*i+2});
        if(2*i+3 <= n) ans.push_back({max(1, 2*i+1), 2*i+3});
    }
    for(int i = 2*on+2; i <= n-r; i++) {
        ans.push_back({max(1LL, 2*(on-1) + (i%2)), i});
    }
    //n-r-1, n-r.
    for(int i = n-r+1; i <= n; i++) {
        ans.push_back({n-r-1 + (i-(n-r+1))%2, i});
    }

    assert(sz(ans) == n-1);
    for(auto& p : ans) cout << p.f << " " << p.s << "\n";
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