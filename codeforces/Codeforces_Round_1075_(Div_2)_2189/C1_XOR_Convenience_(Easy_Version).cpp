#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 1; i < n-1; i++) p[i] = (i+1)^1;
    p[n-1] = 1;
    if(p[n-2] == n) p[0] = n-1;
    else p[0] = n;
    for(int x : p) cout << x << " ";
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