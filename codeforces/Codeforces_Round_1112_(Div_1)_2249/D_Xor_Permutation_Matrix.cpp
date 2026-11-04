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
    int n, x; cin >> n >> x;
    if(n&1) {cout << -1; return;}
    if(n==2) {
        if(x==0) cout << "0 1\n1 0";
        else cout << -1;
        return;
    }
    int hb = __builtin_ctz(n);
    if(n != 1<<hb) {cout << -1; return;}
    int a = 1 + (x==1); int b = x^a;
    vector<int> p1, p2;
    vector<bool> vis(n); int on = 0;
    while(sz(p1)*2 < n) {
        while(on < n && vis[on]) on++;
        p1.push_back(on); p2.push_back(on^a);
        if(x) {p1.push_back(on^x); p2.push_back(on^b);}
        vis[on] = vis[on^x] = vis[on^a] = vis[on^b] = 1;
    }
    vector<vector<int>> A(n, vector<int>(n));
    for(int i = 0; i < n; i+=2) A[0][i] = p1[i>>1];
    for(int i = 1; i < n; i+=2) A[0][i] = p2[i>>1];
    for(int i = 0; i < n; i+=2) A[1][i] = A[0][i]^a;
    for(int i = 1; i < n; i+=2) A[1][i] = A[0][i]^b;

    for(int i = 2; i < n; i++)
        for(int j = 0; j < n; j++) A[i][j] = A[i&1][j]^p1[i>>1];
    for(auto&v : A) {for(auto& i : v) cout << i << " "; cout << "\n";}
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