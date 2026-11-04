#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, k; cin >> n >> k;
    string t; cin >> t;
    vector<int> le, ri;

    for(int i = 0; i < n; i++) {
        if(t[i] == '(') le.push_back(i);
    }

    for(int i = n-1; i >= 0; i--) {
        if(t[i] == ')') ri.push_back(i);
    }


    int bst = INT_MAX;
    string ans;
    for(int j = 0; j <= k; j++) {
        string s;
        for(int i = 0; i < n; i++) s += '0';
        for(int i = 0; i < min(sz(le), j); i++) s[le[i]]='1';
        for(int i = 0; i < min(sz(ri), k-j); i++) s[ri[i]]='1';
        
        int op = 0, x = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') continue;

            if(t[i] == '(') {
                op++;
            } else {
                if(op) {
                    op--;
                    x+=2;
                }
            }
        }

        if(x < bst) {
            ans = s;
            bst = x;
        }
    }
    
    cout << ans;
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