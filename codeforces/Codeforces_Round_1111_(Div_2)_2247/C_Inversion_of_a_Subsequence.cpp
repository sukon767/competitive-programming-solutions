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
    int oo = 0, nn = 0;
    int s = 0;
    int nm = 0;
    vector<int> a(n), b(n);
    for(int& i : a) cin >> i;
    for(int& i : b) cin >> i;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) {
            if(a[i]==0) oo++;
            else nn++;
        } else {
            nm++;
            s += a[i];
        }
    }

    if(s%2==1) {
        cout << 1;
    } else if(s) {
        cout << 2;
    } else if(nm==0) {
        cout << 0;
    } else if(oo && nn) {
        cout << 2;
    } else cout << -1;
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