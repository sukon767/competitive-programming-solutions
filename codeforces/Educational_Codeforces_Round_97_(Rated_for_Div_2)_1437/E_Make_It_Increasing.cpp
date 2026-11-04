#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); vector<int> b(k);
    for(int& i : a) cin >> i;
    for(int& i : b) {cin >> i; i--;}

    for(int i = 0; i < n; i++) a[i] -= i;

    for(int i = 0; i+1 < k; i++) {
        if(a[b[i]] > a[b[i+1]]) {cout << -1; return;}
    }

    int ans = k;

    for(int i = -1; i < k; i++) {
        int l = i >= 0 ? a[b[i]] : INT_MIN, r = i+1 < k ? a[b[i+1]] : INT_MAX;
        vector<int> lis;
        for(int j = (i >= 0 ? b[i]+1 : 0); j < (i+1 < k ? b[i+1] : n); j++) {
            // cout << i << ' ' << j << endl;
            if(a[j] < l || a[j] > r) continue;
            //latest thing less, so lowerbound and --
            auto it = upper_bound(lis.begin(), lis.end(), a[j]);
            if(it == lis.end()) {
                lis.push_back(a[j]);
            } else {
                *it = a[j];
            }
        }
        // cout << lis.size() << endl;
        ans += lis.size();
    }


    cout << n-ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
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

 /* new testament
 * nick belov always reads the entire problem statement.
 */