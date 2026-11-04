#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int>a(n); for(int &i : a) cin >> i;
    int l = 0, r = n-1;
    for(int i = 1; i <= n; i++) {
        if(a[l] == i) l++;
        else if(a[r] == i) r--;
        else {cout << "NO"; return;}
    }
    cout << "YES";
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