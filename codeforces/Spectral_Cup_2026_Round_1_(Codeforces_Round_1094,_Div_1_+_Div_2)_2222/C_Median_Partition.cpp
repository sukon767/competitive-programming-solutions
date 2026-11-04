#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n), b;
    for(int& i : a) cin >> i;
    b = a;
    sort(b.begin(), b.end());
    int m = b[n/2];
    
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int geq = 0, leq = 0;
        bool hasm = false;
        for(int j = i-1; j >= 0; j--) {
            if(a[j] == m) hasm = true;
            if(a[j] > m) geq++;
            if(a[j] < m) leq++;

            if(i%2 == j%2) continue;

            // if(i == 3) {
            //     cout << j << " " <<  geq << " " << leq << " " << hasm << endl;
            // }
            if(dp[j] != -1 && geq <= (i-j)/2 && leq <= (i-j)/2 && hasm) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        // cout << i << " " << dp[i] << endl;
    }

    cout << dp[n];
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