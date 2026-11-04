#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, l, r;
    cin >> n >> l >> r; l--; r--;
    vector<int> a(n); iota(a.begin(), a.end(), 1);
    if(l == 0) a[r] = 0;
    else {a[l-1] = n+1; a[r] = n+1;}
    for(int i = n-1; i > 0; i--) a[i] = a[i-1]^a[i];
    for(int x : a) cout << x << " ";
    // cout << "\n" << l << " " << r;
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