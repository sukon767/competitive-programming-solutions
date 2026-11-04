#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, X; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    cin >> X;
    int miner = INT_MAX, maxer = INT_MIN;
    for(int x : a) {miner = min(x, miner); maxer = max(x,  maxer);}
    if(miner <= X && X <= maxer) cout << "YES";
    else cout << "NO";
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