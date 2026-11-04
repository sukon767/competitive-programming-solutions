#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<vector<int>> b(n+1);
    for(int i = 0; i < n; i++) {int y; cin >> y; b[y].push_back(i);}
    ll m; cin >> m;
    vector<ll> freq(n);
    set<vector<ll>> seg;

    if(b[n].size()) {
        if(b[n][0]) seg.insert({0, b[n][0]-1, n});
        for(int i = 0; i+1 < b[n].size(); i++) seg.insert({b[n][i]+1, b[n][i+1]-1, n});
        if(b[n].back() < n-1) seg.insert({b[n].back()+1, n-1, n});
    } else seg.insert({0, n-1, n});
    
    for(int i = n-1; i >= 0; i--) {
        // cout << i << endl;
        for(int x : b[i]) {
            auto it = seg.lower_bound({x+1, 0, 0});
            assert(it != seg.begin());
            it = --it;
            vector<ll> cur = *it;
            seg.erase(it);

            freq[cur[1]-cur[0]] += cur[2]-i;
            if(cur[0] < x) seg.insert({cur[0], x-1, i});
            if(x < cur[1]) seg.insert({x+1, cur[1], i});   
        }
    }


    ll ans = m;
    for(int i = n-1; i >= 0; i--) {
        if(freq[i]*(i+1) >= m) {
            freq[i] -= m/(i+1);
            ans -= m/(i+1);
            m -= m/(i+1)*(i+1);
            if(m) ans --;
            break;
        } else {ans -= freq[i]; m -= freq[i]*(i+1);}
    }

    cout << ans;
}
 
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