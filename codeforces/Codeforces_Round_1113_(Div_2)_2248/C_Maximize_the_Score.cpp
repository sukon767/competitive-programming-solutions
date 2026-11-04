#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    vector<int> a(2*n);
    for(int&i : a) cin >> i, i--;
    vector<ll> dp(2*n);
    vector<int> s(n, -1);
    vector<int> bk(2*n, -1);
    for(int i = 0; i < 2*n; i++) {
        if(s[a[i]] == -1) {
            s[a[i]] = i;
        }
        else {
            bk[i] = s[a[i]];
        }
    }
    dp[0] = 1;
    for(int i = 1; i < 2*n; i++) {
        dp[i] = dp[i-1]+1;
        if(bk[i] != -1) {
            // cout << i << " bk " << bk[i] << endl;
            dp[i] = max(dp[i], (bk[i]?dp[bk[i]-1]:0) + ll(i-bk[i]+1)*(i-bk[i]+1));
        }
        // cout << i << " " << dp[i] << endl;
    }

    cout << dp[2*n-1];
}

//king of the sun o_O
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