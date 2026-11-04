#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    set<int> bash, cur;
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(cur.find(a[i]) != cur.end()) {
            cout << ans << " ";
            continue;
        }

        for(auto it = bash.begin(); it != bash.end();) {
            int x = *it;
            if(x <= a[i]) {++it; continue;}
            if(x%a[i] + a[i] == x) it = bash.erase(it);
            else ++it;
            ans = max(ans, x%a[i] + a[i]);
        }

        auto it = cur.upper_bound(a[i]);
        if(it == cur.begin()) bash.insert(a[i]);
        else {
            int x = *--it;
            if(a[i]%x + x == a[i]) ans = max(ans, a[i]);
            else {
                //bash a[i]
                for(int y : cur) {
                    if(y >= a[i]) break;
                    ans = max(ans, a[i]%y + y);
                }
                bash.insert(a[i]); 
            } 
        }
        cur.insert(a[i]);
        cout << ans << " ";
    }
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