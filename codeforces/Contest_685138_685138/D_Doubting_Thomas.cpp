#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for(int& i: a) cin >> i;
    swap(a[k-1],a[n-1]);
    set<int> s(a.begin(),a.begin()+n-1);
    int mx = 0;
    while(s.find(mx) != s.end()) mx++;
    if(a[n-1] < mx) cout << k << " " << n;
    else cout << -1 << " " << -1;
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