#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    map<int, int> cnt;
    for(int i = 0; i < 2*n; i++) {int y; cin >> y; cnt[y]++;}
    int ans = 0;
    int c4 = 0, c1 = 0;
    for(auto x : cnt) {if(!(x.second%4)) {c4++;} else if(!(x.second %2)) ans+=2; else c1++;}
    ans += c4/2*4; c4 -= c4/2*2; 
    int g = min(c4, c1/2);
    ans += 4*g; c4 -= g; c1 -= 2*g;
    ans += c4/2*4 + c1/2*2;
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