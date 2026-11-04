#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for(auto&i : a) for(auto &j : i) cin >> j;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if((i+j)%2) {b[i][j] = 720720 + a[i][j]*a[i][j]*a[i][j]*a[i][j];}
            else b[i][j] = 720720;
        }

    for(auto &i : b) {
        for(auto &j : i) cout << j << " ";
        cout << "\n";
    }

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