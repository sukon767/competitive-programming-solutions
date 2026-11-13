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
    int n, k; cin >> n >> k;
    vector<int> f(n+1);
    for(int i = 0; i < n; i++) {
        int x; cin >> x; f[x]++;
    }
    int ans = 0, ex = 0;
    for(int i = 0; i < n; i++) {
        if(f[i]==0 || ex+f[i] < k) break;
        int a = max(1, k-ex);
        f[i] -= a;
        ex -= k-a;
        
        ex += f[i];
        ans++;
    }
    cout << ans;
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