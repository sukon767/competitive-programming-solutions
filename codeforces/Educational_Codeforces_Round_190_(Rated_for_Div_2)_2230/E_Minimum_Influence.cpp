#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> p(n), c(n);
    for(int& i : p) cin >> i;
    for(int& i : c) cin >> i;
    int m; cin >> m;
    vector<int> tp(m), tc(m), d(m);
    for(int& i : tp) cin >> i;
    for(int& i : tc) cin >> i;
    for(int& i : d) cin >> i;
    
    int cont = INT_MAX;
    for(int i = 0; i < n; i++) {
        cont = min(cont, p[i] + c[i]);
    }
    vector<int> ans(m, cont);

    int mx = 2e6;
    vector<vector<int>> na(mx+1);
    vector<pair<int, int>> query;

    for(int j = 0; j < 2; j++) {

        int cur = INT_MAX;

        for(int i = 0; i < m; i++) {
            query.push_back({tp[i]+d[i], i});
            // cout << tp[i]+d[i] << " " << i << endl;
        }
        sort(query.begin(), query.end());
        
        for(int i = 0; i < n; i++) na[p[i]].push_back(i);
    
        for(int i = mx; i >= 0; i--) {
            // if(i%10000 == 0) cout << i << endl;

            //add in news = i.
            for(int x : na[i]) {
                cur = min(cur, c[x]);
            }
    
            while(sz(query) && query.back().first == i) {
                //answer queries.
                auto& v = query.back();
                if(cur != INT_MAX) {
                    int z;
                    if(cur < tc[v.second]) z = 0;
                    else if(cur < tc[v.second] + d[v.second]) z = cur;
                    else z = tc[v.second] + d[v.second];
                    
                    // cout << j << " " << v.second << " " << i << " " << z << endl;
                    // cout << tc[v.second] << " " << cur << endl;
                    // if(v.second == 3) {
                    //     cout << j << " " << i << " " << z << endl;
                    // }

                    ans[v.second] = min(ans[v.second], i + z);
                }
                query.pop_back();
            }
    
        }

        swap(tc, tp);
        swap(c, p);
        for(auto& v : na) v.clear();
        query.clear();
    }

    for(int j = 0; j < 2; j++) {

        int cur = INT_MAX;

        for(int i = 0; i < m; i++) {
            if(tp[i] > 0) query.push_back({tp[i] -1, i});
            // cout << tp[i]-1 << " " << i << endl;
        }
        sort(query.begin(), query.end()); reverse(query.begin(), query.end());
        
        for(int i = 0; i < n; i++) na[p[i]].push_back(i);
    
        for(int i = 0; i <= mx; i++) {
            // if(i%10000 == 0) cout << i << endl;

            //add in news = i.
            for(int x : na[i]) {
                cur = min(cur, c[x]);
            }
    
            while(sz(query) && query.back().first == i) {
                //answer queries.
                auto& v = query.back();
                if(cur != INT_MAX) {
                    int z;
                    if(cur < tc[v.second]) z = 0;
                    else if(cur < tc[v.second] + d[v.second]) z = cur;
                    else z = tc[v.second] + d[v.second];
                    
                    // cout << j << " " << v.second << " " << i << " " << z << endl;
                    // cout << tc[v.second] << " " << cur << endl;

                    // if(v.second == 3) {
                    //     cout << 0+z << endl;
                    // }

                    ans[v.second] = min(ans[v.second], 0 + z);
                }
                query.pop_back();
            }
    
        }

        swap(tc, tp);
        swap(c, p);
        for(auto& v : na) v.clear();
        query.clear();
    }

    for(int x : ans) cout << x << "\n";
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