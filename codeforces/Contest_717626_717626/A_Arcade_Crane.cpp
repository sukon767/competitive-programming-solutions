#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

int hasha(vector<int> a) {
    int ans = 0;
    int p = 1;
    for(int i = 0; i < 5; i++) {ans += a[i]*p; p *= 5;}
    return ans;
}

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i, i--;
    vector<pair<int, int>> ans;

    auto mv = [&](int i, int j, vector<int> c) {
        vector<int> b;
        vector<int> x, y(c.begin()+i, c.begin()+i+3);
        for(int k = 0; k < sz(c); k++) {
            if(k < i || k >= i+3) x.push_back(c[k]);
        }
        for(int k = 0; k < j; k++) b.push_back(x[k]);
        for(int k = 0; k < 3; k++) b.push_back(y[k]);
        for(int k = j; k < sz(x); k++) b.push_back(x[k]);

        return b;
    };

    for(int i = n-1; i >= 5; i--) {
        int j = distance(a.begin(), find(all(a), i));
        if(j < 2) {
            ans.push_back({j, 2});
            a = mv(j, 2, a);
            j = 2;
        }
        ans.push_back({j-2, i-2});
        a = mv(j-2, i-2, a);
    }

    //last 5.
    int p5 = 1; for(int i = 0; i < 5; i++) p5 *= 5;
    vector<bool> seen(p5);
    queue<pair<vector<int>, vector<pair<int, int>>>> bfs;
    bfs.push({{0, 1, 2, 3, 4}, {}});
    seen[hasha(bfs.front().f)] = 1;
    
    vector<int> inv(5);
    for(int i = 0; i < 5; i++) {
        assert(a[i] < 5);
        inv[a[i]] = i;
    }
    vector<pair<int, int>> last5;

    while(1) {
        auto [p, moves] = bfs.front(); bfs.pop();

        if(p == inv) {
            last5 = moves;
            break;
        }

        vector<pair<vector<int>, pair<int, int>>> poss;
        for(int r = 0; r < 3; r++) {
            for(int s = 0; s < 3; s++) {
                if(r == s) continue;
                poss.push_back({mv(r, s, p), {r, s}});
            }
        }

        for(auto [q, nmv] : poss) {
            int hsh = hasha(q);
            if(seen[hsh]) continue;
            seen[hsh] = 1;
            vector<pair<int, int>> nmoves = moves; nmoves.push_back({nmv}); 
            bfs.push({q, nmoves});
        }
    }
    
    int q = sz(ans) + sz(last5);
    assert(sz(ans) + sz(last5) <= 5000);
    cout << q << "\n";
    for(auto &p : ans) cout << p.f+1 << " " << p.s+1 << "\n";
    for(auto &p : last5) cout << p.f+1 << " " << p.s+1 << "\n";
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