#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for(int &i : a) cin >> i;

    bool yes = true;
    for(int i = 0; i < m-1; i++) {
        if(a[i] >= a[i+1]) {yes = false; break;}
    }

    if(yes) cout << n-a[m-1]+1;
    else cout << 1;
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