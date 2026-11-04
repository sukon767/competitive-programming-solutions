#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll n, k; cin >> n >> k;
    
    vector<int> p(n+1);
    int l = 1, r = n;
    for(int i = 1; i <= n; i++) p[i] = i;

    while(l < r) {
        if(2*(r-l) <= k) {
            swap(p[r], p[l]); k -= 2*(r-l);
            r--; l++;
        } else r--;
    }

    if(k) cout << "NO";
    else {
        cout << "YES\n";
        for(int i = 1; i <= n; i++) cout << p[i] << " ";
    }
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