#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

const int oo = 1e7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    //ind, maxpref+ind, curpref+ind.
    //goal: maximize the min.
    vector<vector<pair<int, int>>> dp(2*n+1, vector<pair<int, int>>(n+1, {-oo, 0}));
    dp[0][0].f=0;
    vector<vector<pair<int, int>>> t(2*n+1, vector<pair<int, int>>(n+1, {-oo, 0}));

    for(int i = 1; i <= n; i++) {
        for (auto &v : t) fill(all(v), pair{-oo, 0});

        for(int k = 0; k <= 2*n; k++) {
            for(int l = 0; l <= 2*n; l+=2) {
                if(dp[k][l/2].f==-oo) continue;

                int mp = k-(i-1), cp = l-(i-1);
                if(s[i-1]!='T') {
                    //F
                    cp++;
                    int x = min(mp, cp) + i, y = (cp+i)/2;
                    t[x][y].s = max(t[x][y].s, dp[k][l/2].s+1);
                    t[x][y].f = min(max(t[x][y].f, dp[k][l/2].f+1), t[x][y].s - (2*y-x));
                    cp--;
                }
                if(s[i-1] != 'F') {
                    //T
                    cp--;
                    int x = min(mp, cp) + i, y = (cp+i)/2;
                    t[x][y].s = max(t[x][y].s, dp[k][l/2].s);
                    t[x][y].f = min(max(t[x][y].f, dp[k][l/2].f), t[x][y].s - (2*y-x));
                    cp++;
                }
            }
        }
        dp = t;
    }

    int ans = 0;
    for(auto &v : dp) for(auto &p : v) ans = max(ans, p.f);

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