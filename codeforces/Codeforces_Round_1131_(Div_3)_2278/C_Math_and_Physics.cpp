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
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    for(int i = 1; i+1 < n; i++) {
        if(a[i] != 1) {
            cout << (accumulate(all(a), 0)-1);
            return;
        }
    }

    if(a[0] != 1 || a.back() != 1) {
        cout << (a[0]+a.back()-1); return;
    }
    cout << -1;
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