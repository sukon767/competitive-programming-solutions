#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    for(int i =0; i < n;i++) {
        if(a[i] == n) {
            int x = a[0];
            a[0] = a[i];
            a[i] = x;
            break;
        }
    }

    for(int i : a) cout << i << " ";
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