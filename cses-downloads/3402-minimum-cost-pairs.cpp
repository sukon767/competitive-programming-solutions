#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
const ll oo = 1e18;
void mineq(vector<ll>& a, const vector<ll>& b) {
    while(sz(a) < sz(b)) a.resize(sz(b), oo);
    for(int i = 0; i < sz(b); i++) a[i] = min(a[i], b[i]);
}
vector<ll> minconv(const vector<ll>& A, const vector<ll>& B) {
    vector<ll> a = A, b = B;
    adjacent_difference(a.begin(), a.end(), a.begin());
    adjacent_difference(b.begin(), b.end(), b.begin());
    vector<ll> c(sz(a)+sz(b)-1);
    merge(a.begin()+1, a.end(), b.begin()+1, b.end(), c.begin()+1);
    partial_sum(c.begin(), c.end(), c.begin());
    return c;
}
void solve() {
    int n; cin >> n;
    vector<ll> x(n); for(ll& i : x) cin >> i;
    sort(all(x));
    vector<pair<array<array<vector<ll>, 2>, 2>, pair<int, int>>> sb;
    for(int i = 0; i < n; i++) {
        pair<array<array<vector<ll>, 2>, 2>, pair<int, int>> temp; temp.s = {i, i};
        for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) temp.f[j][k].resize(1);
        sb.push_back(temp);
    }
    while(sz(sb) > 1) {
        vector<pair<array<array<vector<ll>, 2>, 2>, pair<int, int>>> t;
        for(int i = 0; i < sz(sb); i+=2) {
            if(i+1==sz(sb)) {t.push_back(sb[i]); continue;}
            const auto& p1 = sb[i].f, p2 = sb[i+1].f;
            pair<int, int> fin = {sb[i].s.f, sb[i+1].s.s};
            ll d = x[sb[i+1].s.f] - x[sb[i].s.s];
            array<array<vector<ll>, 2>, 2> p3;
            //0-0, 0!0, 1-0, 0-1
            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    vector<ll> OO = minconv(p1[j][0], p2[0][k]);
                    if(!((sb[i].s.f==sb[i].s.s && j==0) || (sb[i+1].s.f==sb[i+1].s.s && k==0))) {
                        OO.push_back(OO.back()+d);
                        for(int l = sz(OO)-1; l > 0; l--) OO[l] = min(OO[l], OO[l-1]+d);
                    }
                    mineq(p3[j][k], OO);
                    mineq(p3[j][k], minconv(p1[j][1], p2[1][k]));
                }
            }
            t.push_back({p3, fin});
        }
        sb = t;
    }
    vector<ll> ans;
    for(int j = 0; j < 2; j++) {
        for(int k = 0; k < 2; k++) {
            mineq(ans, sb[0].f[j][k]);
        }
    }
    for(int i = 1; i <= n/2; i++) cout << ans[i] << " ";
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
 /* new testament
 * nick belov always reads the entire problem statement.
 */
