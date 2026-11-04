#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, h, l; cin >> n >> h >> l;
    int r = min(h, l), s = max(h, l);
    vector<int> a(n);
    int x1 = 0, x2 = 0;
    for(int &i : a) {
        cin >> i;
        if(i <= r) x1++;
        if(i <= s) x2++; 
    }
    x2 -= x1;
    cout << min(x2, x1) + max(0, (x1-x2)/2);
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