#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> split;
    vector<pair<int, int>> pts(n);
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y; pts[i] = {x+1e6, y+1e6};
    }

    while(sz(split)==0 || sz(split)==n) {
        split.clear();
        for(int i = 0; i < n; i++) {
            if((pts[i].first+pts[i].second)%2) split.push_back(i);
        }
        if(sz(split)==0 || sz(split)==n) {
            split.clear();
            for(int i = 0; i < n; i++) {
                if(pts[i].first%2)split.push_back(i);
            }
        }
        for(auto&p : pts) {p.first/=2; p.second/=2;}
    }
    cout << sz(split) << "\n";
    for(int x : split) cout << x+1 << " ";
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