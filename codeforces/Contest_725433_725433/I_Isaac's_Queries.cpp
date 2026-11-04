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
    vector<vector<int>> ans(n+1, vector<int>(n+1, -2));
    auto dfs = [&](auto&&self, vector<int> a) -> void {
        vector<vector<int>> same(31);
        vector<int> ret;
        for(int i = 1; i < sz(a); i++) {
            cout << "? " << a[0]+1 << " " << a[i] << endl;
            int x; cin >> x; if(x == -2) return;
            ans[a[0]+1][a[i]] = x;
            ret.push_back(x);
            same[x+1].push_back(a[i]);
        }
        for(int i = 0; i < sz(ret); i++) {
            for(int j = i+1; j < sz(ret); j++) {
                if(ret[i] != ret[j]) {
                    ans[a[i+1]+1][a[j+1]] = max(ret[i], ret[j]);
                }
            }
        }
        for(auto v : same) if(sz(v) >= 2) self(self, v);
    };

    vector<int> in(n+1); iota(all(in), 0);
    dfs(dfs, in);

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            assert(ans[i][j] != -2);
        }
    }

    cout << "!" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

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