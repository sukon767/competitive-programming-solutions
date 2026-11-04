#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

ld PI = 3.14159265358979323846;

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    pair<ld, int> best = {0, 0};
    for(int i = n/2; i >= 1; i--) {
        int g = gcd(i, n);
        ld nb = 2*sinl(PI*i/n)*(n/g);
        best = max(best, {nb, i});
        if(g == 1) break;
    }
    cout << best.s;
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
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