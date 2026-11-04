#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    int c2 = 0, c3 = 0;
    int cur = 1;
    string s; cin >> s;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i-1]) cur++;
        else {
            if(cur > 3) {cout << "NO"; return;}
            else if(cur == 3) c3++;
            else if(cur == 2) c2++;
            cur = 1;
        }
    }
    if(cur > 3) {cout << "NO"; return;}
    else if(cur == 3) c3++;
    else if(cur == 2) c2++;

    if(c3 > 1) {cout << "NO"; return;}
    if(c3 == 1 && c2) {cout << "NO"; return;}
    if(c3 == 0 && c2 > 2) {cout << "NO"; return;}
    cout << "YES";
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