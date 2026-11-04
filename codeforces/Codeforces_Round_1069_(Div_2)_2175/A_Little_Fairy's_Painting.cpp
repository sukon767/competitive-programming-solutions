#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    map<int, bool> seen;
    int n; cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int u; cin >> u; 
        if(!seen[u]) cnt++;
        seen[u] = true;
    }
    while(!seen[cnt]) cnt++;
    cout << cnt;
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