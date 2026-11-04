#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int &i : a) cin >> i;
    sort(a.begin(), a.end()); reverse(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < k; i++) {
        if(a[i] > 0) ans+=a[i];
        else if(a[i] < 0) {break;}
    }
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