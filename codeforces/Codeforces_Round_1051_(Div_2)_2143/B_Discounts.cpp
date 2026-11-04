#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(k);
    for(int &i : a) cin >> i; for(int &i : b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> inds;
    for(int i = 0; i < k; i++) {
        int nn = inds.size() ? inds.back()-b[i] : n-b[i];
        if(nn < 0 ) break;
        inds.push_back(nn);
    } 

    ll ans = 0;
    for(int i : a) ans +=i;
    for(int i : inds) ans-=a[i];
    cout << ans;
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