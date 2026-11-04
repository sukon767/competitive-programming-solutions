#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    vector<int> p(k); cin >> p[0];
    p[0]--;
    int c1 = 0, c2 = 0;
    for(int i = p[0]-1; i >= 0; i--) {
        if(a[i] != a[i+1]) c1++;
    }
    for(int i = p[0]+1; i < n; i++) {
        if(a[i] != a[i-1]) c2++;
    }

    int ans = max(c1, c2);

    cout << ans + (ans%2);


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