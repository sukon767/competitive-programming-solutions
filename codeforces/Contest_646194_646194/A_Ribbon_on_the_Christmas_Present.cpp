#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) cin >> i;
    
    int ans = 0;
    while(1) {
        int mn = INT_MAX;
        for(int i =0 ; i < n; i++) {
            if(a[i]) {
                mn = min(mn, a[i]);
            }
        }
        if(mn == INT_MAX) break;

        int rn = 0;
        bool prev = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > mn) {
                if(prev) {
                    a[i] -= mn;
                }
            } else if(a[i] == mn) {
                if(!prev) rn++;
                prev = 1;
                a[i] -= mn;
            }
            else prev = 0;
        }
        ans += rn;
    }
    cout << ans;
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