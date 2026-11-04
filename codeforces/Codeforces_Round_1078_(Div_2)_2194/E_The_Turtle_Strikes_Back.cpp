#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m)), b(n, vector<ll>(m)), c(n, vector<ll>(m));

    for(auto &x : a)
        for(auto &y : x) cin >> y;

    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++) {
            b[i][j] = a[i][j];
            if(!i && !j) continue;
            if(!i && j) b[i][j] += b[i][j-1];
            else if(i && !j) b[i][j] += b[i-1][j];
            else {
                if(b[i][j-1] > b[i-1][j]) b[i][j] += b[i][j-1];
                else if(b[i-1][j] > b[i][j-1]) b[i][j] += b[i-1][j];
                else b[i][j] += b[i][j-1];
            }
        }

    for(ll i = n-1; i >= 0; i--)
        for(ll j = m-1; j >= 0; j--) {
            c[i][j] = a[i][j];
            if(i == n-1 && j == m-1) continue;
            if(i == n-1 && j < m-1) c[i][j] += c[i][j+1];
            else if(i < n-1 && j == m-1) c[i][j] += c[i+1][j];
            else {
                if(c[i][j+1] > c[i+1][j]) c[i][j] += c[i][j+1];
                else if(c[i+1][j] > c[i][j+1]) c[i][j] += c[i+1][j];
                else c[i][j] += c[i][j+1];
            }
        }

    vector<vector<ll>> hor(n, vector<ll>(m)), vert(n, vector<ll>(m));
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++) {
            hor[i][j] = b[i][j] + c[i][j] - a[i][j];
            if(j) hor[i][j] = max(hor[i][j], hor[i][j-1]);

            vert[i][j] = b[i][j] + c[i][j] - a[i][j];
            if(i) vert[i][j] = max(vert[i][j], vert[i-1][j]);
        }
    

    ll ans = b[n-1][m-1];
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++) {

            //block i, j
            ll rc = b[n-1][m-1] - 2*a[i][j]; 

            if(i < n-1 && j) {
                rc = max(rc, hor[i+1][j-1]);
            }
            if(j < m-1 && i) {
                rc = max(rc, vert[i-1][j+1]);
            }

            ans = min(ans, rc);
        }

    cout << ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    //ll t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}