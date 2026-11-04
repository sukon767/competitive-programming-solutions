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
    map<string, vector<int>> mp;
    pair<vector<int>, string> best;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            string s; cin >> s;
            if(mp.find(s) == mp.end()) {
                mp[s].resize(11);
            }
            mp[s][0]++;
            mp[s][j+1]++;
        }
    }

    int cnt = 0;
    vector<int> bstv(11);
    string tst;
    for(auto &p : mp) {
        if(p.s > bstv) {
            cnt = 1;
            bstv = p.s;
            tst = p.f;
        } else if(p.s == bstv) {
            cnt++;
        }
    }

    if(cnt > 1) {
        cout << "tie";
    } else {
        cout << tst;
    }
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