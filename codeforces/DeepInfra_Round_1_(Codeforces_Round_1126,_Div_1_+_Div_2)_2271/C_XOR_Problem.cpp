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
    int p2 = 1<<(31 - __builtin_clz(n));
    vector<int> a(p2<<1); iota(all(a), 0);
    reverse(a.begin()+p2, a.end());
    // for(int x : a) cout << x << " ";
    // cout << endl;
    for(int i = (p2<<1)-1; i > 0; i--) {
        a[i] ^= a[i-1];
    }
    cout << ((p2<<2)-1) << "\n";
    for(int i = 1; i < (p2<<1); i++) cout << a[i] << " ";
    cout << p2 << " ";
    for(int i = 1; i < (p2<<1); i++) cout << a[i] << " ";
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