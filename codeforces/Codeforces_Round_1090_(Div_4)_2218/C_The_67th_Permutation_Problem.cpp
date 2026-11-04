#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> p(3*n);
    for(int i = 0; i < n; i++) {
        p[3*i] = i+1;
        p[3*i+1] = 3*n - 2*i;
        p[3*i+2] = 3*n - 2*i-1; 
    }
    for(int x : p) cout << x << ' ';
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