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
    int n, m, k, b; cin >> n >> m >> k >> b;
    int ans = 0;
    int poss = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        int delta = 0;
        for(int j = 0; j < m; j++) {
            int c; cin >> c;
            sum += c;
            if(c <= 0) delta++;
            else delta--;
        }
        if(sum >= k) ans++;
        else if(sum + delta >= k) poss++;
    }

    cout << (ans+min(b, poss));
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