#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, d; cin >> n >> d;
    vector<int> p(n); for(int& i : p) cin >> i;
    vector<vector<int>> plc(n);

    for(int i = 0; i < n; i++) plc[p[i]].push_back(i);
    
    for(int i = 0; i < n; i++) {
        int lst = -1;
        bool ok = 1;
        for(int j = 0; j < sz(plc[i]); j++) {
            if(plc[i][j] <= lst) {ok = 0; break;}
            int st = plc[i][j];
            // if(i==0) {cout << st << endl;}
            while(j+1 < sz(plc[i]) && plc[i][j+1] < st+d) j++;
            lst = max(lst + 2*d, plc[i][j]+d);
        }
        if(ok) {cout << i; return;}
    }

    cout << n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
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