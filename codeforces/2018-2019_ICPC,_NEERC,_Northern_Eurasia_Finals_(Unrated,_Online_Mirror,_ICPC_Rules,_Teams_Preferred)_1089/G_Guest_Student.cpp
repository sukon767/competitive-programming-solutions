#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll k; cin >> k;
    deque<int> a(7); for(int& i : a) cin >> i;

    ll tot = LLONG_MAX;
    for(int i = 0; i < 7; i++) {
        ll l = k;
        ll t = 0;
        ll s = accumulate(a.begin(), a.end(), 0);
        t += (l-1)/s*7;
        l=(l-1)%s+1;
        for(int j = 0; j < 7; j++) {
            t++;
            l-=a[j];
            if(!l) break;
        }
        tot = min(tot, t);

        a.push_back(a.front()); a.pop_front();
    }

    cout << tot;
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