#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const ll oo = 1e18;

void solve() {
    ll n, a, b; cin >> n >> a >> b;
    vector<int> c(n); for(int& i : c) cin >> i;
    if(n==1) {cout << 0; return;}
    vector<int> ps;
    for(int i = 0; i < n; i+=n-1) {
        for(int j = -1; j < 2; j++) {
            int r = c[i]+j;
            for(int k = 2; k*k <= r; k++) {
                if(r%k==0) {
                    ps.push_back(k); while(r%k==0) r/= k;
                }
            }
            if(r>1) ps.push_back(r);
        }
    }

    sort(all(ps)); ps.erase(unique(all(ps)), ps.end());
    ll ans = oo;

    for(int p : ps) {
        // cout << p << endl;
        vector<ll> pre(n, oo), suf(n, oo);
        for(int i = 0; i < n; i++) {
            if(c[i]%p==0) pre[i] = i?pre[i-1]:0;
            else if((c[i]+1)%p==0 || (c[i]-1)%p==0) pre[i] = b+(i?pre[i-1]:0);
            else break;
        }
        for(int i = n-1; i >= 0; i--) {
            if(c[i]%p==0) suf[i] = i<n-1?suf[i+1]:0;
            else if((c[i]+1)%p==0 || (c[i]-1)%p==0) suf[i] = b+(i<n-1?suf[i+1]:0);
            else break;
        }

        for(int i = 0; i < n; i++) {
            if(pre[i]!=oo) pre[i]-=a*(i+1);
            if(i) pre[i] = min(pre[i], pre[i-1]);
        }

        // for(int i = 0; i < n; i++) cout << pre[i] << " ";
        // cout << endl;
        // for(int i = 0; i < n; i++) cout << suf[i] << " ";
        // cout << endl;

        ll ans2 = n*a + pre.back();
        for(int i = 0; i < n-1; i++) {
            ans2 = min(ans2, n*a + min(0LL, i?pre[i-1]:0) + suf[i+1] - (n-(i+1))*a);
        }

        ans = min(ans, ans2);
    }

    cout << ans;
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