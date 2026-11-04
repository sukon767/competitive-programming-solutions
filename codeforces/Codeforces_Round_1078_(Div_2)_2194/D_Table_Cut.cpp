#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, m; cin >> n >> m;
    int tot = 0;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {cin >> grid[i][j]; if(grid[i][j]) tot++;}

    pair<int, int> place;
    ll cur = 0;
    for(int i = n-1; i >= 0; i--) {
        bool done = false;
        for(int j = 0; j < m; j++) {
            if(grid[i][j]) cur++;
            if(cur == tot/2) {place = {i, j}; done = true; break;}
        }
        if(done) break;
    }

    string ans;
    for(int i = 0; i < place.first; i++) ans += 'D';
    for(int i = 0; i < place.second+1; i++) ans += 'R';
    ans += 'D';
    for(int i = place.second+1; i < m; i++) ans += 'R';
    for(int i = place.first+1; i < n; i++) ans += 'D';

    cout << cur*(tot-cur) << "\n";
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