#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) {cin >> i; i--;}
    vector<int> ia(n);
    for(int i = 0; i < n; i++) ia[a[i]] = i;
    string s;
    s.assign(n, ' ');
    s[a[0]] = 'a';
    for(int i = 0; i < n-1; i++) {
        if(a[i+1] == n-1 || (a[i] < n-1 && ia[a[i]+1] > ia[a[i+1]+1])) {
            if(s[a[i]] == 'z') {
                cout << -1; return;
            } else {
                s[a[i+1]] = s[a[i]]+1;
            }
        } else {
           s[a[i+1]] = s[a[i]];
        }
    }
    cout << s;
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
