#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int k; ll x;
    cin >> k >> x;

    vector<int> a;

    int st = -1;
    for(int b = 0; b <= k; b++) {
        if(x&(1LL << b)) {st = b; break;}
    }

    for(int i = st+1; i <= k; i++) {
        if(x&(1LL << i)) {
            a.push_back(2);
        } else a.push_back(1);
    }

    cout << sz(a) << "\n";
    for(int x : a) cout << x << " ";
}
 
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

 /* new testament
 * nick belov always reads the entire problem statement.
 */