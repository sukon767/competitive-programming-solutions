#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int q; cin >> q;
    int N = 5e5;
    int sn = sqrt(5e5);
    vector<ll> a(N+1);
    vector<vector<ll>> pre(sn+1);
    for(int i = 1; i <= sn; i++)
        pre[i] = vector<ll>(i);

    bool fty = true;

    
    for(int i = 0; i < q; i++) {
        int t; cin >> t;
        int x, y; cin >> x >> y;
        if(t == 1) {
            a[x]+=y;
            for(int i = 1; i <= sn; i++) pre[i][x%i]+=y;
        } else {
            if(!fty) cout << "\n";
            else fty = false;
            if(x <= N/x) {
                cout << pre[x][y];
            } else {
                ll ans = 0;
                for(int i = y; i <= N; i+=x) ans+=a[i];
                cout << ans;
            }

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