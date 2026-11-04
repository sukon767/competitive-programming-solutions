#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    string s; cin >> s;
    int n = sz(s);
    if(s[0] != '>') {cout << "No"; return;}
    for(int i = n-1; i >= n-3; i--) if(s[i] != '>') {cout << "No"; return;}
    int cnt = 0;
    for(char c : s) cnt += (c == '-');
    if(cnt == 0) {cout << "No"; return;}
    vector<pair<int, int>> ops;
    int r = n-1;
    while(r >= 4) {
        if(s[r-2] != '>') break;
        ops.push_back({0, r});
        r--;
    }
    r++;
    for(int i = 1; i < r-2; i++) {
        if(s[i] == '>') ops.push_back({i, r});
    }

    cout << "Yes " << sz(ops) << "\n";
    for(auto &p : ops) cout << (p.f+1) << " " << (p.s-p.f+1) << "\n";
}

//king of the sun o_O
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