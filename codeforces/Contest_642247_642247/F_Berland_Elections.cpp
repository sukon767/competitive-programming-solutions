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
    int n, k, m, a; cin >> n >> k >> m >> a;
    vector<array<int, 3>> c(n, {0, 0, 0});
    for(int i = 0; i < n; i++) c[i][2] = i;
    for(int i = 0; i < a; i++) {
        int x; cin >> x; x--;
        c[x][0]++; c[x][1] = -i;
    }
    if(n == k) {
        for(int i = 0; i < n; i++) {
            if(c[i][0]) cout << 1;
            else if(m-a) cout << 2;
            else cout << 3;
            cout << " ";
        }
        return;
    }
    
    sort(all(c));
    int acc = 0;
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        if(c[i][0] == 0 && m-a == 0) {ans[c[i][2]] = 3; continue;}

        if(i >= n-k && c[i][0]) {
            int votes = (c[i][0]+1)*(i - (n-k-1)) - acc;
            if(votes > m-a) {
                ans[c[i][2]] = 1;
                acc += c[i][0];
                continue;
            }
        }
        if(i >= n-k-1) acc += c[i][0];
        //2, 3
        if(i >= n-k || c[i][0] + m-a > c[n-k][0]) ans[c[i][2]] = 2;
        else ans[c[i][2]] = 3;
    }    

    for(int x : ans) cout << x << " ";
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