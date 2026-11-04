#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string s; cin >> s;
    map<char, int> cnt;
    for(int i = 0; i < s.size(); i++) cnt[s[i]]++;
    int odds = 0;
    for(auto x : cnt) if(x.second%2) {if(odds) {cout << "no"; return;} else odds = 1;}

    cout << "yes";


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