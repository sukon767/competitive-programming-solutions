#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int n;
vector<ll> pre, t; vector<vector<ll>> z;
void build(int i = 1, int l = 0, int r = n-1) {
    if(l == r) {pre[i] = t[l]; return;}
    int m = (l+r)>>1;
    build(i<<1, l, m); build(i<<1|1, m+1, r);
    pre[i] = pre[i<<1] + pre[i<<1|1];
}
void add(vector<int> k, int p, int q, int i = 1, int l = 0, int r = n-1) {
    if(p <= l && r <= q)    {z[i][0]+=k[0]; z[i][1]+=k[1]; return;}
    int m = (l+r)>>1;
    if(p <= m) add(k, p, q, i<<1, l, m);
    if(m+1 <= q) add(k, p, q, i<<1|1, m+1, r);
    ll x = min(r, q); ll y = max(l, p);
    pre[i] += (x-y+1)*k[0] + (x*(x+1)/2 - (y-1)*y/2)*k[1];
}
ll query(int p, int q, int i = 1, int l = 0, int r = n-1) {
    //propagate
    pre[i] += (r-l+1)*z[i][0] + (ll(r)*(r+1)/2 - ll(l-1)*l/2)*z[i][1];
    if(l < r)   {z[i<<1][0]+=z[i][0]; z[i<<1][1]+=z[i][1]; z[i<<1|1][0]+=z[i][0]; z[i<<1|1][1]+=z[i][1];}
    z[i] = {0, 0};
    if(p <= l && r <= q)    return pre[i];
    int m = (l+r)>>1;
    ll ans = 0;
    if(p <= m)  ans += query(p, q, i<<1, l, m);
    if(m+1 <= q)    ans += query(p, q, i<<1|1, m+1, r);
    return ans;
} 
void solve() {
    int q; cin >> n >> q;
    pre = vector<ll>(4*n+1);
    z = vector<vector<ll>>(4*n+1, vector<ll>(2));
    t = vector<ll>(n);
    bool firsty = true;
    for(ll &i : t) cin >> i;
    build();
    for(int i =0; i < q; i++) {
        int x, u, v; cin >> x >> u >> v;
        u--; v--;
        if(x == 1) {
            add({1-u, 1}, u, v);
        } else {
            if(!firsty) cout << "\n";
            firsty = false;
            cout << query(u, v);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}
