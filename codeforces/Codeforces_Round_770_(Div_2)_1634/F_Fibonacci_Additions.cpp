#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, q, MOD; cin >> n >> q >> MOD;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<ll> f(n); f[0] = 1;
    for(int i = 1; i < n; i++) {
        if(i) {f[i] += f[i-1]; f[i] %= MOD;}
        if(i > 1) {f[i] += f[i-2]; f[i] %= MOD;}
    }

    int cnt = 0;
    for(int i = n-1; i >= 0; i--) {
        if(i) {a[i] += MOD -a[i-1]; a[i] %= MOD; b[i] += MOD -b[i-1]; b[i] %= MOD;}
        if(i > 1) {a[i] += MOD -a[i-2]; a[i] %= MOD; b[i] += MOD -b[i-2]; b[i] %= MOD;}
        if(a[i] == b[i]) cnt++;
    }

    for(int s = 0; s < q; s++) {
        char x; cin >> x;
        int l, r; cin >> l >> r;
        l--; r--;

        if(a[l] == b[l]) cnt--;
        if(x == 'A') {
            a[l]++; a[l] %= MOD;
        } else {
            b[l]++; b[l] %= MOD;
        }
        if(a[l] == b[l]) cnt++;
        for(int i = r+1; i <= r+2; i++) {
            if(i < n) {
                if(a[i] == b[i]) cnt--;
                if(x == 'A') {
                    a[i] += MOD-f[(r+2-i)+r-l]; a[i]%=MOD;
                } else {
                    b[i] += MOD-f[(r+2-i)+r-l]; b[i]%=MOD;
                }
                if(a[i] == b[i]) cnt++;
            }
        }
        if(cnt == n) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
}
 
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