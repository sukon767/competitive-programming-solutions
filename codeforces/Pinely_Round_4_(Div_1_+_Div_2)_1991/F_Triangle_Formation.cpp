#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); for(int& i : a) cin >> i;
    vector<bool> pp(6);
    vector<vector<int>> c1, c2;
    for(int y = 1; y < 6; y++) {
        for(int z = y+1; z < 6; z++) {
            fill(pp.begin(), pp.end(), 0);
            pp[0] = pp[y] = pp[z] = true;
            vector<int> t1, t2;
            for(int j = 0; j < 6; j++) {
                if(pp[j]) t1.push_back(j);
                else t2.push_back(j);
            }
            c1.push_back(t1); c2.push_back(t2);
        }
    }

    for(int b = 0; b < q; b++) {
        int l, r; cin >> l >> r; l--; r--;
        if(r-l > 50) {cout << "YES\n"; continue;}
        vector<int> t;
        for(int i = l; i <= r; i++) t.push_back(a[i]);
        sort(t.begin(), t.end());
        vector<int> tst;
        for(int i = 0; i+2 < sz(t); i++) {
            if(t[i] + t[i+1] > t[i+2]) tst.push_back(i);
        }
        
        if(sz(tst) > 1 && tst[0]+3 <= tst.back()) {cout << "YES\n"; continue;}
        
        bool ok = false;
        for(int i = 0; i+5 < sz(t); i++) {
            for(int j = 0; j < 10; j++) {
                auto& p = c1[j], q = c2[j];
                if(t[i+p[0]]+t[i+p[1]]>t[i+p[2]] && t[i+q[0]]+t[i+q[1]]>t[i+q[2]]) ok = true;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
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