#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll n; cin >> n;
    int tot = 0;
    vector<int> dig;
 
    while(n) {
        if(n>=10) {
            dig.push_back(n%10);
        } else dig.push_back(n%10 -1);
        tot += n%10;
        n /= 10;
    }
    // cout << tot << endl;
 
    sort(dig.begin(), dig.end());
    // for(int x : dig) cout << x << " ";
    // cout << endl;
    int ans = 0;
    for(int i = int(dig.size())-1; i >= 0; i--) {
        if(tot < 10) break;
        tot -= dig[i]; ans++;
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