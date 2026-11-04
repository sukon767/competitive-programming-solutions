#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> r(n), c(m);
    map<pair<int, int>, bool> mp;
    for(int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        r[--x].push_back(--y); c[y].push_back(x);
        mp[{x, y}] = 1;
    }
    for(auto&v : r) sort(v.begin(), v.end());
    for(auto&v : c) sort(v.begin(), v.end());

    pair<int, int> pos = {0, 0};
    pair<int, int> bdr = {0, n-1}, bdc = {0, m-1}; int d = 0;
    int l = k;
    while(bdr.first <= bdr.second && bdc.first <= bdc.second) {
        // if(d%2==0)cout << pos.first << ", " << pos.second << endl;
        // else cout << pos.second << ", " << pos.first << endl;
        // if(d%2==0) cout << bdc.first << " " << bdc.second << endl;
        // else cout << bdr.first << " " << bdr.second << endl;
            
        if(d<=1) {
            auto it = upper_bound(r[pos.first].begin(), r[pos.first].end(), pos.second);
            if(it==r[pos.first].end() || *it > bdc.second) {
                pos.second = bdc.second;
                if(d%2==0) bdr.first++;
                else bdr.second--;
                goto bruh;
            }
            
            //blok
            if(ll(bdc.second - *it + 1)*(bdr.second-bdr.first+1) > l) {cout << "No"; return;}
            for(int i = bdr.first; i <= bdr.second; i++)
                for(int j = *it; j <= bdc.second; j++) {
                    bool ok = (d%2 ? mp[{j, i}] : mp[{i, j}]);
                    if(!ok) {cout << "No"; return;}
                    else l--;
                }

            pos.second = *it-1;
            if(d%2==0) bdr.first++;
            else bdr.second--; 
            bdc.second = *it-1;
        } else {
            auto it = lower_bound(r[pos.first].begin(), r[pos.first].end(), pos.second);
            if(it==r[pos.first].begin() || *prev(it) < bdc.first) {
                pos.second = bdc.first;
                if(d%2==1) bdr.first++;
                else bdr.second--; 
                goto bruh;
            }

            // cout << "asdf" << " " << *it << endl;
            
            //blok
            if(ll(*prev(it) - bdc.first + 1)*(bdr.second-bdr.first+1) > l) {cout << "No"; return;}
            // cout << "asdf " << bdr.first << " " << bdr.second << " " << *prev(it) << " " << bdc.first << endl;
            for(int i = bdr.first; i <= bdr.second; i++)
                for(int j = bdc.first; j <= *prev(it); j++) {
                    bool ok = (d%2 ? mp[{j, i}] : mp[{i, j}]);
                    if(!ok) {cout << "No"; return;}
                    else l--;
                }
            
            pos.second = *prev(it)+1;
            if(d%2==1) bdr.first++;
            else bdr.second--;
            bdc.first = *prev(it)+1;
        }
        
        bruh:
        d++; d%=4;
        swap(r, c);
        swap(pos.first, pos.second);
        swap(bdr, bdc);
    }

    cout << "Yes";
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