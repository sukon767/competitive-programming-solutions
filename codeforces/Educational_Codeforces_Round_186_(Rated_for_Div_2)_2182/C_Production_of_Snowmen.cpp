#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<vector<int>> abc(3, vector<int>(n));
    for(auto &v : abc) for(int &i : v) cin >> i;

    int sh1 = 0, sh2 = 0;

    for(int i = 0; i < n; i++) {
        bool x = true;
        for(int j = 0; j < n; j++) {
            if(abc[1][j] >= abc[2][(j+i)%n]) {x = false; break;}
        }   
        if(x) {sh1++;}
    }

    for(int i = 0; i < n; i++) {
        bool x = true;
        for(int j = 0; j < n; j++) {
            if(abc[0][j] >= abc[1][(j+i)%n]) {x = false; break;}
        }
        if(x) {sh2++;}
    }

    // cout << sh1 << " " << sh2 << endl;

    cout << ll(sh1)*sh2*n;
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */