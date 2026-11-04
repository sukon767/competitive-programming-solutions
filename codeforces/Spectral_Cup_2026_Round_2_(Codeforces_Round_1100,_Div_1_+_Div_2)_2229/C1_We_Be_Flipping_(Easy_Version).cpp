#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) cin >> i;
    vector<int> ans;
    for(int i = n-1; i >= 0; i--) {
        if(i == n-1) {
            if(a[i] > 0) ans.push_back(i);
        } else if((a[i] > 0) != (a[i+1] > 0)) {
            ans.push_back(i);
        }
    }

    cout << sz(ans) << "\n";
    for(int x : ans) cout << x+1 << " ";

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