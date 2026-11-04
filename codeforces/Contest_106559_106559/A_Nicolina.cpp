#include<bits/stdc++.h>
#include<ranges>

using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

ld getx(pair<ll, ll> a, pair<ll, ll> b) {
    return ld(a.s*a.f - b.s*b.f)/(a.s-b.s);
}

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    for(ll& i : a) cin >> i;
    std::ranges::sort(a);
    vector<ll> b(n);
    deque<pair<ll, ll>> cht;
    for(int i = 0; i < n; i++) {
        pair<ll, ll> ln = {i, a[i]};
        if(!sz(cht) || cht.back().s < ln.s) {
            while(sz(cht) > 1) {
                ld p = getx(cht.back(), ln);
                ld q = getx(cht[sz(cht)-2], cht.back());
                if(p <= q) cht.pop_back();
                else break;
            }
            cht.push_back(ln);
        }
        while(sz(cht)>1) {
            ld p = getx(cht[0], cht[1]);
            if(p <= i+1) cht.pop_front();
            else break;
        }

        b[i] = cht[0].s*(i+1-cht[0].f);
    }
    ll ans = 0;
    for(int i = n-1; i > 0; i--) {
        ans = max(ans, a[i]*(n-i) + b[i-1]);
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