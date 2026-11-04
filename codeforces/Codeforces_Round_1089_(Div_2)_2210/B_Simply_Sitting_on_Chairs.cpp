#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for(int &i : p) cin >> i;
    for(int &i : p) i--;
    vector<bool> mark(n);
    
    int c = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(!mark[i]) ans++;
        mark[p[i]] = true;;
        // cout << i << ' ' << p[i] << endl;
        c = max(c, ans);
    }

    cout << c;

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