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
    const int N = 1000;
    vector<int> f(N+1);
    for(int i= 0; i < n; i++) {
        int x; cin >> x; f[x]++;
    }
    ll ans = 0;
    for(int i = 0; i <= N; i++) {
        while(n-f[i] < f[i]-2) {
            f[i]--; n--;
        }
        ans += i*f[i];
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