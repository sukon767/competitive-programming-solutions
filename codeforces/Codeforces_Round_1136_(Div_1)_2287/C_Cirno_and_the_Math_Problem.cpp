#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

const int N = 5e4;

vector<bitset<N+1>> ans;

//sukon always reads the entire problem statement.
void solve() {
    int n, m; cin >> n >> m;
    cout << ans[m][n];
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ans = vector<bitset<N+1>>(N+1);
    vector<bitset<N+1>> pre(N+1);
    vector<int> mu(N+1);
    mu[1] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 2*i; j <= N; j+=i) mu[j] -= mu[i];
    }
    vector<vector<int>> div(N+1);
    for(int i = 1; i <= N; i++) {
        for(int j = 2*i; j <= N; j+=i) div[j].push_back(i);
    }

    for(int i = 1; i <= N; i++) {
        for(int d : div[i]) if(mu[d] != 0) ans[i] ^= pre[d];
        ans[i] <<= 1;
        ans[i][1] = !ans[i][1];
        for(int d : div[i]) pre[d] ^= ans[i];
        pre[i] ^= ans[i];
    }

    for(int i = 1; i <= N; i++) ans[i] ^= ans[i-1];

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