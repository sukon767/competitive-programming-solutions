#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    int cnt = 0;
    vector<vector<int>> G(n, vector<int>(n));
    for(auto &x : G)
        for(auto &y : x) {
            char c; cin >> c;
            if(c == '#') {
                y = 1; cnt++;
            }
        }

    for(int way = 0; way < 2; way++) {
        for(int sl = -1; sl < 2; sl+=2) {


            for(int j = 0; j < n; j++) {
                bool w = way;
                int amt = 0;
                int onx = sl == -1 ? n-1 : 0, ony = j;
                while(0 <= onx && onx < n && 0 <= ony && ony < n) {
                    if(G[onx][ony]) amt++;
                    if(w) onx+=sl;
                    else ony++;
                    w = !w;
                }

                if(amt == cnt) {cout << "YES"; return;}
            }

            for(int i = 0; i < n; i++) {
                bool w = way;
                int amt = 0;
                int onx = i, ony = 0;
                while(0 <= onx && onx < n && 0 <= ony && ony < n) {
                    if(G[onx][ony]) amt++;
                    if(w) onx+=sl;
                    else ony++;
                    w = !w;
                }

                if(amt == cnt) {cout << "YES"; return;}
            }
        }
    }

    if(cnt <= 4) {
        for(int i = 0; i < n-1; i++)
            for(int j = 0; j < n-1; j++)
                if(G[i][j] + G[i+1][j] + G[i][j+1] + G[i+1][j+1] == cnt) {cout << "YES"; return;} 
    }

    cout << "NO";

    
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