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
    ll x, y, m; cin >> x >> y >> m;
    string s; cin >> s;
    ll ans = x+y;
    for(int i = 0; i < m; i++) {
        if(s[i] == '+') {
            if(y) y++;
            else if(x) {
                x--; y++;
            }
        } else {
            if(y > 1) {
                y--; x++;
            } else if(x) x--;
            else if(y) {
                y--; x++;
            }
        }
        ans = max(ans, x+y);
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