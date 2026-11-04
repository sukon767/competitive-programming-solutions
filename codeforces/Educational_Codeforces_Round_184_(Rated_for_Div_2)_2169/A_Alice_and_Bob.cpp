#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, a; cin >> n >> a;
    int cnt= 0;
    int cnt2 = 0;
    vector<int> v(n); for(int &i : v) {cin >> i; if(i > a) cnt++; else if(i < a) cnt2++;}
    if(cnt2 > cnt) cout << a-1;
    else cout << a+1;

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