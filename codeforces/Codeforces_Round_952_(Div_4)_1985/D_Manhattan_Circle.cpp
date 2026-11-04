#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for(string &i : a) cin >> i;
    int a1, a2, b1, b2;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '#') {a1 = i+1, a2 = j+1; break;}
        }
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(a[j][i] == '#') {b1 = j+1, b2 = i+1; break;}
        }

    cout << b1 << " " << a2;
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