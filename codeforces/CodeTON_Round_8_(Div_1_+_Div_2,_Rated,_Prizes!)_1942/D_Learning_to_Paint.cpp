#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> a(n+2, vector<int>(n+2));
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n);
    dp[0] = {0};
    for(int i = 0; i < n; i++) {
        ll lo = INT_MIN, hi = INT_MAX;
        if(i) dp[i].push_back(a[1][i]);
        dp[i].push_back(a[0][i]);
        sort(all(dp[i]));

        vector<int> loi(i+1);
        while(lo <= hi) {
            ll m = (lo+hi+1)>>1;
            ll t = 0;
            for(int j = 0; j <= i; j++) {
                int lo2 = 0, hi2 = sz(dp[j]);
                while(lo2 < hi2) {
                    int m2 = (lo2+hi2)>>1;
                    if(dp[j][m2] + a[j+2][i] >= m) hi2 = m2;
                    else lo2 = m2+1;
                }
                t += sz(dp[j]) - lo2;
                loi[j] = lo2;

            }

            if(lo==hi) {
                hi = lo-1; break;
            }

            if(t < k) hi = m-1;
            else lo = m;
        }

        // if(i==2) {
        //     for(int j = 0; j <= i; j++) {
        //         cout << j << endl;
        //         for(int x : dp[j]) cout << x << " ";
        //         cout << endl;
        //     }
        // }



        vector<int> tmp;
        int cntlo = 0;
        for(int j = 0; j <= i; j++) {
            for(int k = sz(dp[j])-1; k >= -1; k--) {
                if(k >= 0 && dp[j][k] + a[j+2][i] > lo) tmp.push_back(dp[j][k] + a[j+2][i]);
                else {
                    cntlo += k-loi[j]+1;
                    break;
                }
            }
        }

        dp[i] = tmp;
        while(cntlo>0 && sz(dp[i]) < k) {
            dp[i].push_back(lo);
            cntlo--;
        }
        sort(all(dp[i]));
    }

    reverse(all(dp.back()));
    for(int x : dp.back()) cout << x << " ";
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