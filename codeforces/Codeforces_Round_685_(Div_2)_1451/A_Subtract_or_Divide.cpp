#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;

    int ans = 0;
    if(n == 1)  {cout << 0; return;}
    if(n == 2)  {cout << 1; return;}
    if(n%2)    {ans++; n--;}
    if(n > 2){
            ans++; n = 2;

    }
    ans++;

    cout << ans;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}