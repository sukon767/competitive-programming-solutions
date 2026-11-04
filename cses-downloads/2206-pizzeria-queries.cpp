#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int n;
vector<ll>  minUp, minDown;
int M = INT_MAX;
void build(int i = 1, int l = 0, int r = n-1) {
    if(l == r) {minUp[i] = l; minDown[i] = n-1-l; return;}
    int m = (l+r)>>1;
    build(i << 1, l, m);  build(i << 1 | 1, m+1, r);
    minUp[i] = min(minUp[i<<1], minUp[i<<1|1]);
    minDown[i] = min(minDown[i<<1], minDown[i<<1|1]);
}
void add(int k, int dx, int i = 1, int l = 0, int r = n-1) {
    if(l == r) {minUp[i] += dx; minDown[i] += dx; return;}
    int m = (l+r)>>1;
    if(k <= m)  add(k, dx, i<<1, l, m);
    else    add(k, dx, i<<1|1, m+1, r);
    minUp[i] = min(minUp[i<<1], minUp[i<<1|1]);
    minDown[i] = min(minDown[i<<1], minDown[i<<1|1]);
    // if(dx == -6)
    //     cout << l << " " << r << " " << i << " " << minDown[i];
}
pair<int, int> query(int p, int q, int i = 1, int l = 0, int r = n-1) {
    pair<int, int> ans = {M, M};
    if(p > q)   return ans;
    if(p <= l && r <= q)    return  {minUp[i], minDown[i]};
    int m = (l+r)>>1;
    if(p <= m) {
        pair<int, int>  kid = query(p, q, i<<1, l, m);
        ans = {min(ans.first, kid.first), min(ans.second, kid.second)};
    }
    if(m+1 <= q) {
        pair<int, int>  kid = query(p, q, i<<1|1, m+1, r);
        ans = {min(ans.first, kid.first), min(ans.second, kid.second)};
    }
    return ans;
}
int solve() {
    int q; cin >> n >> q;
    minUp = minDown = vector<ll>(4*n+1);
    vector<ll> p(n);
    for(int i = 0; i < n; i++)  cin >> p[i];
    bool firstbruh = false;
    build();
    for(int i = 0; i < n; i++)
        add(i, p[i]);
    // cout << query(0, n-1).first << " " << query(0, n-1).second << "\n";
    for(int i = 0; i < q; i++) {
        int type; cin >> type;
        if(type == 1) {
            int k, x; cin >> k >> x;
            // cout << "\n";
            k--;
            add(k, x-p[k]);
            p[k] = x;
            // cout << "\n" << query(0, n-1).first << " " << query(0, n-1).second;
        }
        else {
            if(firstbruh) cout << "\n";
            else    firstbruh = true;
            int k; cin >> k;
            k--;
            cout << min(query(0, k-1).second - (n-1-k), query(k, n-1).first - k);
        }
    }
    return 0;
}
int main() {
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}
