#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define f first
#define s second

void solve() {
    int n, k; cin >> n >> k;
    vector<int> c(n*k); for(int &i : c) {cin >> i; i--;}
    vector<bool> see(n);
    int left = n;
    int t = n/(k-1) + (bool)(n%(k-1));
    vector<int> cnt(n, -1);
    vector<pair<int, int>> ans(n);
    int cur = 0;
    for(int i = 0; i < n*k; i++) {
        if(cnt[c[i]] > -1 && !see[c[i]]) {
            left--;
            see[c[i]] = true;
            ans[c[i]] = {cnt[c[i]], i};
            cur++;
        } else if(cnt[c[i]] == -1) cnt[c[i]] = i;
        if(cur == t) {
            //dump
            cnt.assign(n, -1);
            cur = 0;
        }
        if(!left) break;
    }

    for(auto &p : ans) cout << p.f+1 << " " << p.s+1 << "\n";
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