#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> val(n, vector<int>(n));
    for(auto &x : val)
        for(auto &y : x) cin >> y;
    if(n == 2) {cout << (val[0][0]^val[0][1]); return;}

    for(int i = 0; i < n; i++) if(i%4 == 0 || i%4 == 1) grid[0][i] = 1;
    for(int i = 0; i < n; i++) if(!grid[0][i]) grid[0][i] = 2;
    if(grid[0][n-1] == 2) grid[0][n-1] = 0;
    for(int i = 0; i < n; i++) if(grid[0][i] == 1) grid[1][i] = 2;

    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n; j++) {
            if(!grid[i][j]) {
                if(j+1 < n && !grid[i][j+1]) {
                    grid[i][j] = grid[i][j+1] = 2;
                    grid[i+1][j] = grid[i+1][j+1] = 1;
                    if(i+2 < n) {grid[i+2][j] = grid[i+2][j+1] = 2;}
                    if(j-1 >= 0) grid[i+1][j-1] = 2;
                    if(j+2 < n) grid[i+1][j+2] = 2;
                } else {
                    grid[i+1][j] = grid[i+2][j] = 1;
                    grid[i][j] = 2;
                    if(j-1 >= 0) grid[i+1][j-1] = grid[i+2][j-1] = 2;
                    if(j+1 < n) grid[i+1][j+1] = grid[i+2][j+1] = 2;
                    if(i+3 < n) grid[i+3][j] = 2;
                }
            }
        }

    int ans = 0;

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) cout << grid[i][j];
    //     cout << "\n";
    // }
        
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 1) ans ^= val[i][j];

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