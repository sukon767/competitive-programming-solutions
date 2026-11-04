#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    sort(a.begin(), a.end());
    int es = -1, os = -1, en = -1, on = -1;
    for(int i = 0; i < n; i++) {
        if(!(a[i]%2)) {
            if(es == -1) es = i;
        } else {
            if(os == -1) os = i;
        }
    }

    for(int i = n-1; i >= 0; i--) {
        if(!(a[i]%2)) {
            if(en == -1) en = i;
        } else {
            if(on == -1) on = i;
        }
    }

    int ans = INT_MAX;
    if(es != -1 && en != -1) {
        ans = min(ans, es + n-1-en);
    }

    if(os != -1 && on != -1) {
        ans = min(ans, os + n-1-on);
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