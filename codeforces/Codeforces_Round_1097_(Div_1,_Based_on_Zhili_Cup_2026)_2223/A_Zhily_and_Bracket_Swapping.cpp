#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    pair<int, int> pre = {0, 0};
    int on = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) {
            if(a[i] == '(') {
                pre.first++, pre.second++;
            } else {
                pre.first--, pre.second--;
            }
            
        } else {
            if(on%2) {
                pre.first++, pre.second--;
            } else {
                pre.first--, pre.second++;
            }
            on++;
        }
        if(pre.first < 0 || pre.second < 0) break;
    }
    if(!pre.first && !pre.second) {
        cout << "YES"; return;
    }

    pre = {0, 0};
    on = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) {
            if(a[i] == '(') {
                pre.first++, pre.second++;
            } else {
                pre.first--, pre.second--;
            }
            
        } else {
            if(!(on%2)) {
                pre.first++, pre.second--;
            } else {
                pre.first--, pre.second++;
            }
        }
        if(pre.first < 0 || pre.second < 0) break;
    }
    if(!pre.first && !pre.second) {
        cout << "YES"; return;
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