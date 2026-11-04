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
    int n, q; cin >> n >> q;
    vector<int> a(n); for(int &i : a) cin >> i;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += __builtin_popcount(a[i])&1;
    }
    cout << n-cnt;
    for(int i = 0; i < q; i++) {
        int p, x; cin >> p >> x; --p;
        cnt -= __builtin_popcount(a[p])&1;
        a[p] = x;
        cnt += __builtin_popcount(a[p])&1;
        cout << " " << n-cnt;
    }
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