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
    int n, T; cin >> n >> T;
    T--;
    vector<int> a(n+1); for(int i = 1; i <= n; i++) cin >> a[i];
    if(T > n) {
        int d = T-n;
        for(int i = 1; i <= n; i++) a[i] -= d;
        T = n;
    }
    vector<int> inds(n+1);
    for(int i = 1; i <= n; i++) {
        a[i] -= i;
        if(i <= T-max(0, a[i])) inds[max(0, a[i])]++;
    }

    int ans = 0;
    int cur = 0;
    for(int i = 0; i <= n; i++) {
        cur += inds[i];
        ans = max(ans, cur);
        // cout << i << " " << cur << endl;
        if(1 <= T-i && a[T-i] <= i) cur--;
        // cout << i << " " << cur << endl;
    }
    cout << ans;
}

//king of the sun o_O
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