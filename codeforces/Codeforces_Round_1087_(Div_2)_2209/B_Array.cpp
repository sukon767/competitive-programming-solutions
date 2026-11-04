#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--) {
        int x = 0, y = 0;
        for(int j = i+1; j < n; j++) {
            if(a[j] < a[i]) x++;
            else if(a[j] > a[i]) y++;
        }
        ans[i] = max(x, y);
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
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