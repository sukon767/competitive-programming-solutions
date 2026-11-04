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
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<int> a(x), b(y);
    vector<int> f(n+m);
    for(int& i : a) cin >> i, f[--i]++;
    for(int& i : b) cin >> i, f[--i]+=2;
    ll ans = 0;
    int lft = n+m-1;
    int lft1 = n, lft2 = m; 
    for(int i = n+m-1; i >= 0; i--) {
        if(lft == 0) break;
        if(f[i] == 3) {
            lft--; ans += i+1;
        } else if(f[i] == 1 && lft1) {
            lft--; lft1--; ans += i+1;
        } else if(f[i] == 2 && lft2) {
            lft--; lft2--; ans += i+1;
        }
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