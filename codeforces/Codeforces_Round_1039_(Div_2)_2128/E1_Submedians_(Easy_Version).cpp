#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define sz(x) (int)(x).size()
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int& i : a) cin >> i;
 
    vector<int> pre(n);
    int lo = 1, hi = n;

    pair<int, int> arr = {0, n-1};
 
    while(lo < hi) {
        int m = (lo+hi+1)>>1;
 
        pair<int, int> pf;
 
        bool ok = false;
        fill(pre.begin(), pre.end(), 0);
        pair<int, int> bst = {0, -1};
 
        for(int i = 0; i < n; i++) {
            if(a[i] < m) pre[i]--;
            else pre[i]++;
            if(i) pre[i] += pre[i-1];
            
            if(i >= k-1) {
                if(pre[i] - bst.first >= 0) {
                    ok = true; arr = {bst.second+1, i};
                    break;
                }                                
                bst = min(bst, {pre[i-(k-1)], i-(k-1)});
            }
        }
 
        if(ok) lo = m;
        else hi = m-1;
    }

    cout << lo << " " << arr.first+1 << " " << arr.second+1;
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
 
 /* new testament
 * nick belov always reads the entire problem statement.
 */
