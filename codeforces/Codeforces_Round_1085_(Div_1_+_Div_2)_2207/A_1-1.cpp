#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0, ans2 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') ans++;
        else if(i > 0 && s[i-1] == '1' && i < n-1 && s[i+1] == '1') {s[i] = '1'; ans++;}
    }

// cout << s << endl;
    for(int i = 0; i < n; i++) {
        if(i == 0 || i == n-1) {
            if(s[i] == '1') ans2++;
            continue;
        }

        if(s[i] == '1' && s[i-1] == '1' && s[i+1] == '1') {s[i] = '0';}
        else if(s[i] == '1') ans2++;
    }

    cout << ans2 << " " << ans;
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