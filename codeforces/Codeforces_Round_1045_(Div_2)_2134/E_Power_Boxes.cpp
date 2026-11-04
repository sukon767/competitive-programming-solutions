#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> d(n+1); d[n-1]=1;
    vector<int> a(n, -1);
    for(int i = n-2; i >= 0; i--) {
        if(d[i+1]==d[i+2]) {d[i] = d[i+1]+1; continue;}
        cout << "throw " << i+1 << endl;
        int l; cin >> l;
        if(l==d[i+1]+1) a[i]=1;
        else a[i]=2;
        d[i]=l;
    }
    for(int i = 0; i < n-1; i++) {
        if(a[i]==-1) {
            cout << "swap " << i+1 << endl;
            cout << "throw " << i+2 << endl;
            int l; cin >> l;
            if(l==d[i+2]+1) a[i]=1;
            else a[i]=2;
        }
    }
    cout << "swap " << n-1 << endl;
    cout << " throw " << n-1 << endl;
    int l; cin >> l;
    if(l==2) a[n-1]=1;
    else a[n-1]=2;

    cout << "!";
    for(int x : a) cout << " " << x;
    cout << endl;
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