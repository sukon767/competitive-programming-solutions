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
    int n; cin >> n;
    int x = -1;
    vector<int> ret;
    for(int i = 0; i < n; i++) {
        int y; cin >> y;
        if(x != -1) {
            ret.push_back(0);
            ret.push_back(x);
            ret.push_back(y);
            ret.push_back(x|y);
            ret.push_back(x&y);
            ret.push_back(x^y);
            ret.push_back(x&(~y));
            ret.push_back((~x)&y);  
        }
        x = y;
    }
    sort(all(ret));
    ret.erase(unique(all(ret)), ret.end());
    cout << sz(ret);
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
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