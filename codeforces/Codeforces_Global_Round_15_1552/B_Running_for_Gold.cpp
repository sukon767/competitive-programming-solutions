#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define f first
#define s second

void solve() {
    int n; cin >> n;
    vector<vector<int>> r(n, vector<int>(5));
    for(auto &i : r) for(int &j : i) cin >> j;

    int cur = 0;
    for(int i = 1; i < n; i++) {
        int c = 0;
        for(int j = 0; j < 5; j++) if(r[i][j] < r[cur][j]) c++;
        if(c >= 3) cur = i;
    }
    for(int i = 0; i < n; i++) {
        if(i == cur) continue;
        int c = 0;
        for(int j = 0; j < 5; j++) if(r[i][j] < r[cur][j]) c++;
        if(c >= 3) {cout << -1; return;}
    }
    cout << cur+1;
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */