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
    ll ans = 0;
    for(int k = n-1; k > 1; k--) {
        int i = 0;
        for(int j = k-1; j > 0; j--) {
            while(i+1 < j && a[i]+a[j] <= max(a[k], a.back()-a[k])) i++;
            while(i >= j) i--;
            // cout << i << " " << j << " " << k << endl;
            if(a[i]+a[j] > max(a[k], a.back()-a[k])) ans += j-i;
        }
    }

    cout << ans;
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