#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<vector<int>> p(n, vector<int>(3));
    set<int> cur;
    for(int i = 0; i < n; i++) {
        cin >> p[i][0] >> p[i][1]; p[i][2] = i;
    }
    sort(p.begin(), p.end(), [&](auto &a, auto &b) {if(a[0] == b[0]) return a[1] > b[1]; else return a[0] < b[0];});

    vector<int> prev(3);
    vector<int> ans(n);
    for(auto x : p) {
        auto it = cur.lower_bound(x[1]);
        if(it == cur.end()) {ans[x[2]] = -1; cur.insert(x[1]); continue;}
        else ans[x[2]] = *it;
        cur.insert(x[1]);
        
        if(prev[0] == x[0] && prev[1] == x[1]) {ans[prev[2]] = 0; ans[x[2]] = 0;}
        prev = x;
    }

    cur.clear();

    // for(int x : ans) cout << x << "\n";

    sort(p.begin(), p.end(), [&](auto &a, auto &b) {if(a[1] == b[1]) return a[0] < b[0]; else return a[1] > b[1];});


    for(auto x : p) {
        if(ans[x[2]] == -1 || ans[x[2]] == 0) {cur.insert(x[0]); prev = x; continue;}
        auto it = cur.upper_bound(x[0]);
        if(it == cur.begin()) {ans[x[2]] = -1; cur.insert(x[0]); prev = x; continue;}
        else ans[x[2]] -= (*--it)-1;
        ans[x[2]] -= x[1]-x[0]+1;
        cur.insert(x[0]);
        
        //dum dupe
        prev = x;
    }

    for(int x : ans) if(x == -1) cout << "0\n"; else cout << x << "\n";
    
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}