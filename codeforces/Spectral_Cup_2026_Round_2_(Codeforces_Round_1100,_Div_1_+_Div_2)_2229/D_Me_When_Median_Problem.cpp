#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int&i : a) cin >> i;
    for(int&i : b) cin >> i;

    int lo = 1, hi = 2*n;
    while(lo < hi) {
        int m = (lo+hi+1)>>1;
        vector<int> a1(n), b1(n);
        for(int i = 0; i < n; i++) {
            if(a[i] < m) a1[i] = 0;
            else a1[i] = 1;
            if(b[i] < m) b1[i] = 0;
            else b1[i] = 1;
        }

        //remove all 0s
        int r = 0, s = 0;
        //r: #11s, s: #00 runs
        bool run = false;
        for(int i = 0; i < n; i++) {
            if(a1[i] != b1[i]) continue;
            if(a1[i] == 1) {
                r++; run = false;
            } else {
                if(!run) s++;
                run = true;
            }
        }
        if(r <= s) {
            hi = m-1;
        } else {
            lo = m;
        }
    }

    cout << lo;

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