#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<string> s(k);
    for(int i = 0; i < k; i++) cin >> s[i];

    string anss;
    for(int i = 1; i <= n; i++) {
        if(n%i) continue;
        string ans;

        bool fin = true;

        for(int r = 0; r < i; r++) {
            vector<bool> t(26, true);
            for(int d = 0; d < n/i; d++) {
                vector<bool> cont(26);
                for(int j = 0; j < k; j++) cont[int(s[j][d*i + r]) - int('a')] = true;
                for(int i = 0; i < 26; i++) t[i] = t[i]&&cont[i];
            }
            bool work = false;
            for(int j = 0; j < 26; j++) if(t[j]) {ans += char(int('a') + j); work = true; break;}
            if(!work) {fin = false; break;}
        }
        
        if(fin) {
            for(int j = 0; j < n/i; j++) anss += ans;
            break;}
    }

    cout << anss;
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