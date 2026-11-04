#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll n, h; cin >> n >> h;
    vector<ll> a(n);
    for(ll &i : a) cin >> i;
    set<ll> cur;
    cur.insert(-1); cur.insert(n);

    map<ll, vector<ll>> hs;
    for(ll i = 0; i < n; i++) hs[a[i]].push_back(i);

    vector<ll> vals = {h};
    vector<ll> pre(n);
    vector<vector<ll>> pre2(n, vector<ll>(n));


    auto it = --hs.end();
    while(true) {
        //update pairs to prefixes
        auto it2 = cur.begin();
        auto last = --cur.end();
        while(it2 != last) {
            auto it3 = it2; it3++;
            // if(it3 == cur.end()) break;

            pair<ll, ll> p = {*it2 + 1, *it3 - 1};
            if(p.first > p.second) {it2++; continue;}

            ll d = (vals.back() - (*it).first)*(p.second - p.first+1);


            pre[p.first] += d;
            if(p.second < n-1) pre[p.second+1] -= d;

            //2D
            pre2[p.first][p.first] += d;                
            if(p.second < n-1) {
                pre2[p.second+1][p.first] -= d;
                pre2[p.first][p.second+1] -= d;
                pre2[p.second+1][p.second+1] += d;
            }
            it2++;
        }

        for(ll x : (*it).second) cur.insert(x);

        vals.push_back((*it).first);
        if(it == hs.begin()) break;
        it--;
    }

    ll ans = 0;

    for(ll i = 1; i < n; i++) pre[i] += pre[i-1];

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++) {
            if(i) pre2[i][j] += pre2[i-1][j];
            if(j) pre2[i][j] += pre2[i][j-1];
            if(i && j) pre2[i][j] -= pre2[i-1][j-1];
        }

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++) {
            ans = max(ans, pre[i] + pre[j] - pre2[i][j]);
        }

    cout << ans;
     
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    //ll t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}