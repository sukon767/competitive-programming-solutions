#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    cout << 0 << endl;
    cout << "I 0" << endl;
    int x; cin >> x;
    bool xoror = false;
    
    if(x == 1) {
        //then we know c != 0, so its and.
        cout << "I " << (1LL << n)-1 << endl;
        cin >> x;
    } else xoror = true;

    //all thats there is 0 and c. BINARY SEARCH ON c
    ll l = 0, r = (1LL << n)-1;
    while(l < r) {
        ll m = (l+r+1)>>1;
        cout << "Q " << m << endl;
        cin >> x;
        if(!x) {
            r = m-1;
        } else {
            l = m;
        }
    }

    if(xoror) {
        //l = c now.
        ll y;
        if(l == (1LL << n)-1) {
            y = (1LL << n)-2;
            cout << "I " << y << endl;
            cin >> x;
            if(x == 2) {
                cout << "A 2 " << l << endl;
            } else {
                cout << "A 3 " << l << endl;
            }
        } else {
            y = (1LL << n)-1;
            cout << "I " << y << endl;
            cin >> x;
            cout << "Q " << y << endl;
            cin >> x;
            if(x) {
                cout << "A 2 " << l << endl;
            } else {
                cout << "A 3 " << l << endl;
            }
        }
    } else {
        cout << "A 1 " << l << endl;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve();
        // if(t)   cout << "\n";
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