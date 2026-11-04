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
    int c = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '#') c++;
        else {
            ans = max(ans, c);
            c = 0;
        }
    }
    ans = max(ans, c);
    ans = (ans>>1) + (ans&1);
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