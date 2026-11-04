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
    string a, b; cin >> a >> b;

    int ans = 0;
    for(int t = 0; t < 2; t++) {
        string sa, sb;
        for(int i = t; i < n; i+=2) {
            sa += a[i]; 
            sb += b[i];
        }
        int c = 0;
        int ra = 0, rb = 0;
        int ca = 0, cb = 0;
        for(int i = 0; i < sz(sa); i++) {
            c += (sa[i]-'0') - (sb[i] - '0');
            ca += sa[i]-'0';
            cb += sb[i]-'0';
            if(sa[i] == '0') ra += ca;
            if(sb[i] == '0') rb += cb;
        }
        if(c != 0) {
            cout << "NO"; 
            return;
        }
        ans += abs(ra - rb);
    }

    cout << "YES";
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