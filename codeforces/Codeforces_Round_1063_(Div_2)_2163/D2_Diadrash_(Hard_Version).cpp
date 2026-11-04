#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, q;
    cin >> n >> q;
    // n = 1e4, q = 1e4;

    vector<int> mind(n+1, -1);
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        mind[l] = max(mind[l], r);
    }

    vector<pair<int, int>> ivls;
    for(int i = 1; i <= n; i++) {
        if(mind[i] == -1) continue;
        if(!ivls.size() || mind[i] > ivls.back().second) ivls.push_back({i, mind[i]});
    }

    // for(int i = 1; i <= n; i++) {
    //     ivls.push_back({i, i});
    // }

    if(ivls.size() == 1) {
        int x;
        cout << "? " << ivls[0].first << " " << ivls[0].second << endl;
        cin >> x;
        cout << "! " << x << endl;
        return;
    }

    int l = 0, r = (int)ivls.size()-1;
    
    int cnt = 0;

    int cur = 0;
    while(l < r) {
        int m = (l+r)>>1;
        int x, y;
        
        cout << "? " << ivls[l].first << " " << ivls[m].second << endl;
        cnt++;
        if(cnt > 30) {return;}
        cin >> x;
        // if(ivls[l].first == 1) x = ivls[m].second; 

        cout << "? " << ivls[m+1].first << " " << ivls[r].second << endl;
        cnt++;
        if(cnt > 30) {return;}
        cin >> y;
        // if(ivls[l].first == 1) y = ivls[m].second;

        if(x == y) {
            cout << "! " << x << endl;
            return;
        }
        if(x > y) {cur = x; r = m;}
        else {cur = y; l = m+1;}
    }
    cout << "! " << cur << endl;

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    // int t = 1;
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