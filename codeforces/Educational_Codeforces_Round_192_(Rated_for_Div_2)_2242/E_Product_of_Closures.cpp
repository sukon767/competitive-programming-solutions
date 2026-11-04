#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int l, r, n; cin >> l >> r >> n;
    int l1 = 31 - __builtin_clz(l), r1 = 31 - __builtin_clz(r);
    if(l & ((1<<l1) -1)) l1++;
    if(l1 < r1) {
        //case1
        for(int i = 0; i < n; i++) {
            if(i%(r1)==0 && i%(r1+1)==0) cout << 1;
            else cout << 0;
        }
        return;
    }

    l1 = 31 - __builtin_clz(l);
    int x = l, y = r;
    if(l1 < r1) {
        //case2
        y = 1<<r1;
    } else {
        //case3
        for(int b = 29; b >= 0; b--) {
            if((l>>b&1) != (r>>b&1)) {
                y = (r>>b<<b); break;
            }
        }
    }

    int b1 = l1, b2 = r1;
    for(int i = 0; i < n; i++) {
        cout << ((x>>b1&1)&(y>>b2&1));
        b1--, b2--;
        if(b1 < 0) b1 = l1;
        if(b2 < 0) b2 = r1;
    }
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