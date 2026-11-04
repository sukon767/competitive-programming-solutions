#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int l1, b1, l2, b2, l3, b3; cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    for(int i = 0; i < 2; i++) {
        if(l1 == l2 && l2 == l3 && b1+b2+b3==l1) {cout << "YES"; return;}
        swap(l1, b1); swap(l2, b2); swap(l3, b3);
    }

    for(int i = 0; i < 2; i++) {
        if(b2 == b3 && l2+l3 == l1 && l1==b3+b1) {cout << "YES"; return;}
        swap(l1, b1); swap(l2, b2); swap(l3, b3);
    }

    cout << "NO";
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