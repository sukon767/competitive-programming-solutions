#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

const int M = 5e5+1;
vector<int> ans(M, INT_MAX);

void solve() {
    int m; cin >> m;
    if(ans[m]==INT_MAX) cout << -1;
    else cout << ans[m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> multi(M, INT_MAX); multi[1] = 0;
    for(int i = 1; i < M; i++) {
        if(multi[i]==INT_MAX) continue;
        ans[i] = multi[i]+1;
        for(int j = i+2; j < M; j+=i+2) {
            if(multi[j/(i+2)] != INT_MAX) multi[j] = min(multi[j], ans[i]+multi[j/(i+2)]);
        }
    }

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