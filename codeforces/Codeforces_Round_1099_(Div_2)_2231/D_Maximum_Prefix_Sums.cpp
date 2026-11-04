#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define sz(x) (int)(x).size()
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n);
    vector<ll> c(n); for(int& i : a) cin >> i;
    for(ll& i : c) cin >> i;
 
 
    vector<ll> b(n);
    string pre;
    for(int i = 0; i < n; i++) pre += '0';
 
    //build initial determined b[i]s.
    for(int i = 1; i < n; i++) {
        if(c[i] < c[i-1]) {
            cout << "NO"; return;
        } else if(c[i] > c[i-1]) {
            pre[i] = '1';
            b[i] = c[i];
        }
    }
 
    if(s[0] == '1' && a[0] != c[0]) {
        cout << "NO"; return;
    } else {
        a[0] = c[0];
        s[0] = '1';
        pre[0] = '1';
        b[0] = a[0];
    }
 
    //check
 
    //forwards
    bool run = false;
    for(int i = 0; i < n; i++) {
        if(run) {
            if(s[i] == '0') run = false;
            else {
                ll cand = b[i-1] + a[i];
 
                if(pre[i] == '1') {
                    if(b[i] != cand) {cout << "NO"; return;}
                } else {
                    b[i] = cand;
                    pre[i] = '1';
                }
            }
            
        }
        if(!i || c[i] != c[i-1]) {
 
            if(pre[i] == '1') {
                if(b[i] != c[i]) {cout << "NO"; return;}
            } else {
                b[i] = c[i];
                pre[i] = '1';
            }
 
            run = true;
        }
    }
 
    //backwards
    run = false;
    for(int i = n-1; i >= 0; i--) {
        if(run) {
            // cout << i << endl;
 
            if(s[i+1] == '0') run = false;
            else {
 
                ll cand = b[i+1] - a[i+1];
 
                // if(i == 3) {
                //     cout << cand << endl;
                // }
 
                if(pre[i] == '1') {
                    if(b[i] != cand) {cout << "NO"; return;}
                } else {
                    b[i] = cand;
                    pre[i] = '1';
                }
            }
        }
 
        if(!i || c[i] != c[i-1]) {
 
            if(pre[i] == '1') {
                if(b[i] != c[i]) {cout << "NO"; return;}
            } else {
                b[i] = c[i];
                pre[i] = '1';
            }
 
            run = true;
        }
    }
 
    for(int i = 0; i < n; i++) {
        if(pre[i] == '1' && b[i] > c[i]) {
            cout << "NO"; return;
        }
    }
 
    // for(ll x : b) {
    //     cout << x << " ";
    // }
    // cout << endl;
 
    //nuke
    for(int i = 0; i < n; i++) {
        if(pre[i] == '0') {
            if(pre[i-1] == '1') {
                //nuke down
                b[i] -= 1e16;
            } else {
                //maintain
                if(s[i] == '1') {
                    b[i] = b[i-1] + a[i];
                } else b[i] = b[i-1];
            }
        }
    }
 
    for(int i = n-1; i > 0; i--) {
        b[i] -= b[i-1];
    }
 
    cout << "YES\n";
    for(ll x : b) cout << x << " ";
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