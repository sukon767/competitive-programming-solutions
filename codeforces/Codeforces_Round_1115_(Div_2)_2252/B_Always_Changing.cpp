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
    string s; cin >> s;
    int r0 = 0, r1 = 0;
    int b0 = 0, b1 = 0;
    if(s[0] == '0') b0++;
    else b1++;
    if(s[n-1] == '0') b0++;
    else b1++;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) {
            if(s[i] == '0') r0++;
            else r1++;
        }
    }

    int ans = INT_MAX;

    for(int t = 0; t < 2; t++) {
        for(int i = r0; i <= r0 + b0; i++) {
            //alt
            if(r1 <= i && i <= r1+b1) {
                ans = min(ans, 2*i);
            }

            //0 1 0 1 0
            if(i) {
                if(r1 <= i-1 && i-1 <= r1+b1) {
                    ans = min(ans, 2*i-1);
                }
            }
        }

        swap(b0, b1); swap(r0, r1);
    }
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
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