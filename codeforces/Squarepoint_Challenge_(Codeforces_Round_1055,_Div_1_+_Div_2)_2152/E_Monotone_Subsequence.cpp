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
    int N = n*n+1;
    vector<pair<int, int>> dp(N, {1, -1});
    vector<bool> on(N, 1); int s = N;
    for(int i = 1; i <= n; i++) {
        cout << "? " << s;
        for(int j = 0; j < N; j++) if(on[j]) cout << " " << j+1;
        cout << endl;
        int c; cin >> c;
        vector<int> a(c); for(int& i : a) {cin >> i; i--;}
        if(c >= n+1) {
            cout << "!";
            for(int j = 0; j < n+1; j++) cout << " " << a[j]+1;
            cout << endl;
            return;
        }
        for(int j = 0; j < c; j++) {
            on[a[j]] = 0; s--;
            for(int k = a[j]+1; k < (j+1<c?a[j+1]:N); k++) {
                if(on[k]) dp[k] = {i+1, a[j]};
            }
        }
    }

    for(int i = N-1; i >= 0; i--) {
        if(dp[i].f == n+1) {
            vector<int> ans;
            int cur = i;
            while(cur != -1) {
                ans.push_back(cur);
                cur = dp[cur].s;
            }
            reverse(all(ans));
            cout << "!";
            for(int x : ans) cout << " " << x+1;
            cout << endl;
            return;
        }
    }

    assert(0==1);
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