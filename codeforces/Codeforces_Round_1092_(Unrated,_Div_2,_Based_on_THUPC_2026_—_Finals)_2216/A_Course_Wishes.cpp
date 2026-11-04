#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define f first
#define s second

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(k);
    vector<vector<int>> freq(k+1);
    for(int &i : a) cin >> i;
    for(int i = 0; i < n; i++) {
        int l; cin >> l;
        freq[--l].push_back(i+1);
    }
    vector<int> ans;
    for(int i = k-1; i >= 0; i--) {
        for(int x : freq[i]) {
            for(int j = i; j < k; j++) ans.push_back(x);
        }
    }

    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
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