#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {

    int n; cin >> n;

    if(n == 1){ cout << 1 << " " << 1; return;}

    cout << 1 << " " << n << " ";
    for(int i = n-2; i >=1; i--) cout << i << " ";
    cout << n-1 << " " << n << " ";
    for(int i = 2; i < n; i++) cout << i << " ";

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