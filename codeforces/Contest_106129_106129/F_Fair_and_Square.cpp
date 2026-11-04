#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int h, w; cin >> h >> w;
    vector<string> g(h);
    for(auto& s : g) cin >> s;
    
    int poss = 0;

    for(int i = 0; i < h; i++) {
        int r = 0;
        for(int j = 0; j < w; j++) {
            if(g[i][j] == '#') r++;
            else if(r) {
                poss = r;
                break;
            }
        }
        if(r) {poss = r; break;}
    }

    for(int d = poss; d >= 1; d--) {
        if(poss%d == 0) {
            bool why = 0;
            vector<string> t = g;
            for(int i = 0; i < h; i++) {
                for(int j = 0; j < w; j++) {
                    if(t[i][j] == '#') {
                        // cout << d << " " << i << " " << j << endl;
                        if(i+d > h || j+d > w) goto nxt;
                        for(int k = 0; k < d; k++) {
                            for(int l = 0; l < d; l++) {
                                if(t[i+k][j+l] != '#') goto nxt;
                                t[i+k][j+l] = '.';
                            }
                        }
                    }
                }
            }

            cout << d; return;

            nxt:
            why = 1;
        }
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