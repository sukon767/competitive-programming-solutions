#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve() {
    int n; cin >> n;
    vector<string> ms(10);
    for(int bit = 0; bit < 10; bit++) {
        string q;
        for(int i = 1; i <= n; i++)
            q += bool(i&(1 << bit)) + '0';
        cout << "? " << q << endl;
        cin >> ms[bit];
    }
    vector<int> ans(n);
    for(int bit = 0; bit < 10; bit++)
        for(int j = 1; j <= n; j++) 
            ans[j-1] += int(ms[bit][j-1]-'0') << bit;
    cout << "!";
    for(int i = 0; i < n; i++) {
        cout << " " << ans[i];
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}
