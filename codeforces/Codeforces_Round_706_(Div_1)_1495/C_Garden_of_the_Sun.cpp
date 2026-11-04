#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];
    
    int s;
    if((n%3) == 1) s = 0; else s = 1;
    for(int i = s; i < n; i+=3) {
        for(int j = 0; j < m; j++) grid[i][j] = 'X';
    }

    for(int i = 0; i < n; i++) {
        if(i%3 == s%3) continue;
        if(i%3 == (s+1)%3) {
            for(int j = 0; j < m; j++) if(grid[i][j] == 'X') {if(i+1 < n) grid[i+1][j] = 'X'; i++; break;} 
        } else {
            int con = 0;
            for(int j = 0; j < m; j++) if(grid[i][j] == 'X') {con = j; break;} 
            grid[i][con] = 'X'; if(i-1 >= 0) grid[i-1][con] = 'X';
        }
        
    }

    for(int i = 0; i < n; i++) cout << grid[i] << "\n";

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