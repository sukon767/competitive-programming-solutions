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
    string S; cin >> S;
    int n = sz(S);
    for(int i = 0; i < n; i++) if(S[i] == '\\') S[i] = '1';
    string cur = "";
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cur += S[i];
        if(cur == "0" || cur == "11") {
            ans++; cur = "";
        } else if(cur == "10") {
            cout << ans; return;
        } else if(cur == "111") {
            cout << "INVALID"; return;
        }
    }
    if(cur != "") {
        cout << "INVALID"; return;
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