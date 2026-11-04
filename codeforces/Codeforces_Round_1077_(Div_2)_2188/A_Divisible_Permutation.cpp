#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int on = 1;
    for(int i = n-1; i >= 0; i-=2) {
        a[i] = on; on++;
    }
    on = n;
    for(int i = n-2; i >= 0; i-=2) {
        a[i] = on; on--;
    }

    for(int x : a) cout << x << " ";
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