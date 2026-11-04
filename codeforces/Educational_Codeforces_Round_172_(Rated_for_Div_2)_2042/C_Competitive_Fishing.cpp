#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    int c = 0;
    priority_queue<int> take;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '0') c--;
        else c++;
        if(i && (c > 0)) take.push(c); 
    }

    int ans = 1;
    while(take.size() && k > 0) {
        ans++; k-=take.top(); take.pop();
        // cout << k << endl;
    }

    if(k > 0) cout << "-1";
    else cout << ans;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}