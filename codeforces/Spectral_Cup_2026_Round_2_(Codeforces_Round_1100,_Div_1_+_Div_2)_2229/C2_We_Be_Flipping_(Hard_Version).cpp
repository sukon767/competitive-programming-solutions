#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<ll> a(n); for(ll& i : a) cin >> i;

    while(sz(a) && a.back() < 0) {
        a.pop_back();
        n--;
    }

    int ind = -1;

    ll cura = 0;
    ll suf = accumulate(a.begin(), a.end(), 0);
    ll bst = suf;

    for(int i = 0; i < n; i++) {
        suf -= a[i];

        if(a[i] > 0) {
            if(-a[i] + suf + cura > bst) {
                ind = i;
                bst = -a[i] + suf + cura;
            }
        }

        cura += abs(a[i]);
    }

    // cout << ind << "\n";

    if(ind > -1) {
        //do C1 until ind-1 and flip.
        vector<int> ans;
        for(int i = ind-1; i >= 0; i--) {
            if(i == ind-1) {
                if(a[i] > 0) ans.push_back(i);
            } else if((a[i] > 0) != (a[i+1] > 0)) {
                ans.push_back(i);
            }
        }
        ans.push_back(ind);

        cout << sz(ans) << "\n";
        for(int x : ans) cout << x+1 << " ";

    } else {
        cout << "0\n";
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