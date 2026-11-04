#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    int l = -1, r = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            if(l == -1) {l = i;}
            r = i;
        }   
    }

    int ans = 0;
    for(int i = l+1; i < r; i++) {
        if(a[i] == 0) ans++;
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