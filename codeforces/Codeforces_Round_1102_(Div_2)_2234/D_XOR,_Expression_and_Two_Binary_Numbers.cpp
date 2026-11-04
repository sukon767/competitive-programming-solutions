#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll n, k; cin >> n >> k;
    string s, z; cin >> s >> z;
    vector<ll> t(4);
    for(int i = 0; i < n; i++) {
        t[2*(s[i]-'0') + (z[i]-'0')]++;
    }

    ll ans = 0;
    for(int i = 1; i < 4; i++) {
        vector<ll> x(2);
        for(int j = 0; j < 4; j++) {
            x[((j>>1&1)*(i>>1&1))^((j&1)*(i&1))] += t[j];
        }
        ans += x[0]*x[1]*(((1LL << k) + 1)/3 + bool(i!=3 && k%2==0));
    }

    cout << ans;
}
 
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

 /* new testament
 * nick belov always reads the entire problem statement.
 */