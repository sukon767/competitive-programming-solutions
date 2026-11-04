#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> freq(n*n);
    vector<vector<int>> a(n, vector<int>(n));
    for(auto &x : a) for(auto &y : x) cin >> y;
    for(auto x : a) for(int y : x) freq[y-1]++;

    for(int x : freq) if(x > n*n - n) {cout << "NO"; return;}
    cout << "YES";
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