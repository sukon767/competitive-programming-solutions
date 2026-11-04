#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(auto& p : a) cin >> p.first;
    for(auto& p : a) cin >> p.second;
    int fl = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].second < a[i].first) {
            swap(a[i].first, a[i].second);
            fl++;
        }
    }

    bool any = n&1;
    sort(a.begin(), a.end());
    for(int i = 0; i < n-1; i++) {
        if(a[i].first > a[i+1].first || a[i].second > a[i+1].second) {
            cout << "NO"; return;
        }
        if(((i+1)&1 || (n-i-1)&1) && (a[i].second < a[i+1].first && a[i].first < a[i+1].second)) any = true;
    }

    if(any) cout << "YES";
    else if(fl%2==0) cout << "YES";
    else cout << "NO";
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