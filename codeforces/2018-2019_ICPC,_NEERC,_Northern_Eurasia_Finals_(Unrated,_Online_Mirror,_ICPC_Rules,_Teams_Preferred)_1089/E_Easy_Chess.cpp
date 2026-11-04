#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

string tr(pair<int, int> x) {
    string s;
    s+='a'+x.first;
    s+='1'+x.second;
    return (s+' ');
}

void solve() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> mv;
    bool ok = 0;

    if(n <= 14) {
        vector<pair<int, int>> t;
        for(int i = 0; i < 7; i++) {
            t.push_back({i, 0});
        }
        mv.push_back(t);
        t.clear();
        for(int i = 0; i < 7; i++) {
            t.push_back({7, i});
        }
        mv.push_back(t);
        mv.push_back({{7, 7}});
    } else if(n <= 28) {
        for(int r = 0; r < 3; r++) {
            vector<pair<int, int>> t;
            if(r%2) {
                for(int i = 7; i > 0; i--) {
                    t.push_back({i, r});
                }
            } else {
                for(int i = 0; i < 7; i++) {
                    t.push_back({i, r});
                }
            }
            mv.push_back(t);
            mv.push_back({{(r%2 ? 0 : 7), r}});
        }
        for(int i = 3; i < 7; i++) {
            mv.back().push_back({7, i});
        }
        mv.push_back({{7, 7}});
    } else {
        ok = 1;
        n -= 15;
        for(int r = 0; r < 6; r++) {
            vector<pair<int, int>> t;
            if(r%2) {
                for(int i = 7; i > 0; i--) {
                    t.push_back({i, r});
                }
            } else {
                for(int i = 0; i < 7; i++) {
                    t.push_back({i, r});
                }
            }
            mv.push_back(t);
            mv.push_back({{(r%2 ? 0 : 7), r}});
        }

        mv.back().push_back({0, 6});
    }

    n-=sz(mv)-1;
    for(auto& v : mv) {
        for(int i = 0; i < sz(v); i++) {
            if(!i) cout << tr(v[i]);
            else if(n) {
                cout << tr(v[i]); n--;
            }
        }
    }

    if(ok) {
        for(int i = 0; i < 7; i++) {
            cout << tr({i, 7});
        }
        for(int i = 6; i > 0; i--) {
            cout << tr({i, 6});
        }
        cout << tr({7, 6}) << tr({7, 7});
    }

}

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

 /* new testament
 * nick belov always reads the entire problem statement.
 */