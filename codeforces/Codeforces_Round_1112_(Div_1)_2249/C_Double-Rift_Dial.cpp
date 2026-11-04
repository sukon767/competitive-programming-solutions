#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

int N;
//sum, prefix max.
vector<pair<int, int>> seg;

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
    return {a.f+b.f, max(a.s, a.f+b.s)};
}

void upd(int k, int v, int i = 1, int l = 0, int r = N-1) {
    if(l==r) {seg[i] = {v, max(0, v)}; return;}
    int m = (l+r)>>1;
    if(k <= m) upd(k, v, i<<1, l, m);
    else upd(k, v, i<<1|1, m+1, r);
    seg[i] = merge(seg[i<<1], seg[i<<1|1]);
}

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n; N = 2*n-1; seg = vector<pair<int, int>>(4*N);
    vector<int> p(n), ip(n); for(int&i : p) cin >> i, i--;
    for(int i = 0; i < n; i++) ip[p[i]] = i;
    vector<int> cur(n, 1);
    vector<bool> vis(n);
    for(int i = 0; i < n; i++) {
        vis[p[i]]=1; upd(i, cur[p[i]]);
        if(p[i] && !vis[p[i]-1]) cur[p[i]-1]--;
        if(p[i]+1<n && !vis[p[i]+1]) cur[p[i]+1]--;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(seg[1].s <= 2) ans++;
        if(i+1 < n) {
            //update
            int c = 1;
            if(0<=p[i]-1) {
                c--;
                int j = ip[p[i]-1];
                cur[p[i]-1]++;
                upd(j+n*(j<=i), cur[p[i]-1]);
            }
            if(p[i]+1<n) {
                c--;
                int j = ip[p[i]+1];
                cur[p[i]+1]++;
                upd(j+n*(j<=i), cur[p[i]+1]);
            }
            upd(i, 0);
            cur[p[i]] = c; upd(i+n, c);
        }
    }

    cout << ans;
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