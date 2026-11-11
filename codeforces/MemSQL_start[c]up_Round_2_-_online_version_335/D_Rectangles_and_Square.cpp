#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

const int m = 3010;
//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    //vert, hor
    vector<vector<pair<int, int>>> up(m, vector<pair<int, int>>(m));
    auto down = up;
    vector<vector<int>> dp(m, vector<int>(m));
    auto dia = dp; auto coord = dp;
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1++, y1++, x2++, y2++;
        up[x1][y1].f++; up[x2][y1].f--;
        up[x1][y1].s++; up[x1][y2].s--;
        down[x2-1][y1].f++; down[x2-1][y2].f--;
        down[x1][y2-1].s++; down[x2][y2-1].s--;
        dp[x1][y1]++; dp[x1][y2]--; dp[x2][y1]--; dp[x2][y2]++;
        coord[x1][y1] = i+1;
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(i) {
                up[i][j].f += up[i-1][j].f;
                down[i][j].s += down[i-1][j].s;
            }
            if(j) {
                up[i][j].s += up[i][j-1].s;
                down[i][j].f += down[i][j-1].f;
            }
        }
    }

    for(int i = m-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(up[i][j].f && i+1<m && up[i+1][j].f) {
                up[i][j].f += up[i+1][j].f;
            }
            if(up[i][j].s && j+1<m && up[i][j+1].s) {
                up[i][j].s += up[i][j+1].s;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(down[i][j].f && j && down[i][j-1].f) {
                down[i][j].f += down[i][j-1].f;
            }
            if(down[i][j].s && i && down[i-1][j].s) {
                down[i][j].s += down[i-1][j].s;
            }
        }
    }
    
    //bull & shit
    for(int s = -(m-1); s <= m-1; s++) {
        int r, c;
        if(s < 0) {r = -s, c = 0;}
        else {r = 0, c = s;}
        vector<pair<int, int>> ev; //index, end.
        for(int i = 0; r+i<m && c+i<m; i++) {
            auto &p = up[r+i][c+i];
            if(p.f && p.s) {
                int mn = min(p.f, p.s);
                ev.push_back({r+i, r+i+mn-1});
            }
        }
        priority_queue<pair<int, int>> pq; //u think this is a joke
        int on = 0;
        for(int i = 0; r+i<m && c+i<m; i++) {
            while(on < sz(ev) && ev[on].f == r+i) {pq.push(ev[on]); on++;}
            while(!pq.empty() && r+i > pq.top().s) pq.pop();
            if(!pq.empty()) dia[r+i][c+i] = pq.top().f;
        }
    }

    //fill out dp
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(i) dp[i][j] += dp[i-1][j];
            if(j) dp[i][j] += dp[i][j-1];
            if(i && j) dp[i][j] -= dp[i-1][j-1];
        }
    }

    //dp
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(dp[i][j] && i && j) dp[i][j] += min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            //HEAVEN OR HELL LETS ROCK
            auto& p = down[i][j];
            if(p.f && p.s) {
                int mn = min(p.f, p.s)-1;
                int k = i-dia[i][j];
                if(dia[i][j] && i-mn <= dia[i][j] && dp[i][j]>=k+1) {
                    //WE DID IT
                    vector<int> ans;
                    for(int u = i-k; u <= i; u++) {
                        for(int v = j-k; v <= j; v++) {
                            if(coord[u][v]) ans.push_back(coord[u][v]);
                        }
                    }
                    cout << "YES " << sz(ans) << "\n";
                    for(int x : ans) cout << x << " ";
                    return;
                }
            }
        }
    }

    cout << "NO";
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