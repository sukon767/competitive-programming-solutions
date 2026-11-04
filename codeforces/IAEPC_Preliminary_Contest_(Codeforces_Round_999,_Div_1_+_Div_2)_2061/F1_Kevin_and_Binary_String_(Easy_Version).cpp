#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    string s, t; cin >> s >> t;
    vector<int> a, b;
    int n = sz(s);
    int c1 = 0, c2 = 0;
    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < n; i++) {
            if(a.size() && s[i] == s[i-1]) a.back()++;
            else a.push_back(1);
            if(s[i] == '0') c1++;
        }
        swap(s, t); swap(a, b); swap(c1, c2);
    }

    if(c1 != c2) {cout << -1; return;}

    int op = 0;
    if(s[0] != t[0]) {
        if(sz(a) > 2) {
            a[2] += a[0];
            a = vector<int>(a.begin()+1, a.end());
        } else {
            swap(a[0], a[1]);
        }
        op++;
    }   
    if(sz(a) > 2 && s.back() != t.back()) {
        // cout << "asdf" << endl;
        // cout << sz(a) << " " << sz(b) << endl;
        a[sz(a) - 3] += a.back();
        a.pop_back();
        op++;
    }

    if(sz(a) < sz(b)) {cout << -1; return;}

    // for(int x : a) cout << x << " ";
    // cout << endl;
    // for(int x : b) cout << x << " ";
    // cout << endl;

    int prev = 0, i = 0, cur = 0;
    for(int j = 0; j < sz(b); j++) {
        while(i < sz(a) && cur < b[j]) {
            cur += a[i];
            if(i != prev) op++;
            i += 2;
        }
        //now cur >= b[j]
        // cout << j << " " << cur << " " << b[j] << endl;
        if(cur > b[j]) {cout << -1; return;}
        //cur = b[j]
        cur = 0;
        i--;
        if(i < sz(a)) {
            for(int k = prev+1; k < i; k+=2) {
                a[i] += a[k];
            }
            prev = i;
        } else break;
    }

    cout << op;
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