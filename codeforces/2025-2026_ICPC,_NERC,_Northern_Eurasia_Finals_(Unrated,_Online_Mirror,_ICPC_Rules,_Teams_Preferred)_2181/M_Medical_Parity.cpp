#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    string x, y; cin >> x >> y;
    string yo;
    yo += y[0];
    for(int i = 1; i < y.size(); i++) {
        if(y[i] != y[i-1]) {yo += '1';}
        else {yo += '0';}
    }

    // cout << yo << "\n";
    int ans = 0;
    for(int i = 0; i < y.size()-1; i++) {
        if(yo[i] != x[i] && yo[i+1] != x[i+1]) {yo[i] = x[i]; yo[i+1] = x[i+1]; ans++;}
    }

    for(int i = 0; i < y.size(); i++) if(yo[i] != x[i]) ans++;
    cout << ans;


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