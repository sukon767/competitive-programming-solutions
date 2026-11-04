#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> comp(n);

    for(int i = 0; i < n; i++) {
        cin >> comp[i].first >> comp[i].second;
    }

    ld ans = 0;

    for(int i = n-1; i >= 0; i--) {
        // cout << ans << " " << ans*ld(100-comp[i].second)/100 + comp[i].first << endl;
        if(ans*ld(100-comp[i].second)/100 + comp[i].first > ans) {
            ans = ans*ld(100-comp[i].second)/100 + comp[i].first;
            // cout << "yay" << i << endl;
        }
    }

    cout << setprecision(10) << ans;
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