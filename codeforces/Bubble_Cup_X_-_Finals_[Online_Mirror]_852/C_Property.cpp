#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >>n;
    vector<int> A(n);
    for(int &i : A) cin >> i;

    vector<pair<int, int>> s;
    for(int i = 0; i < n; i++) s.push_back({A[i]+A[(i+1)%n], i});

    sort(s.begin(), s.end());
    vector<int> ans(n);
    for(int i= 0; i < n; i++) {
        ans[s[i].second] = i;
    }

    for(int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << ans[i];
    }






}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}