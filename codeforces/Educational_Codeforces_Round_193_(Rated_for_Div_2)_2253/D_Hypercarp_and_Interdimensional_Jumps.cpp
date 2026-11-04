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
    ll x, y; cin >> x >> y;
    ll s = 0;
    while((s+1)*(s+2)/2 <= x+y) {
        s++;
    }
    ll sm = s*(s+1)/2;
    ll d = min(min(x, y), (x+y - sm)/2);
    x -= d; y -= d;
    d = x+y-sm;
    if(x+y > sm) {
        if(x) x-=d;
        else y-=d;
    }

    //x is gol
    string ans = "";
    while(x >= s && s > 0) {
        ans += 'X';
        x -= s;
        s--;
    }

    for(int i = 0; i < s; i++) {
        if(s-i == x) ans += 'X';
        else ans += 'Y';
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