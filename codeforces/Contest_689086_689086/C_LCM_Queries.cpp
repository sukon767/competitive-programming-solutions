#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

int N = 1e6;
vector<bool> incont(N+1);
vector<int> ps;
vector<int> high(N+1);

void solve() {
    int n, q; cin >> n >> q;
    vector<bool> f(N+1);
    for(int i = 0; i < n; i++) {
        int x; cin >> x; f[x] = true;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j+=i) {
            if(f[j]) {incont[i] = true; break;}
        }
    }

    vector<vector<int>> pre(N+1), fac(N+1);
    for(int i = 1; i <= N; i++) {
        pre[i].push_back(0);
        for(int j = i; j <= N; j+=i) {
            pre[i].push_back(pre[i].back());
            if(incont[j]) {
                pre[i].back()++;
            }
            fac[j].push_back(i);
        }
    }

    vector<int> mob(N+1); mob[1] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 2*i; j <= N; j+=i) mob[j] -= mob[i];
    }

    for(int i = 1; i <= N; i++) {
        int l = 0, r = N;
        //latest nonzero
        while(l < r) {
            int mid = (l+r+1)>>1;
            int cnt = 0;
            //calc number of coprime from [mid, N]
            for(int d : fac[i]) {
                cnt += mob[d]*(pre[d][N/d] - pre[d][(mid-1)/d]);
            }

            if(!cnt) r = mid-1;
            else l = mid;
        }
        //1 always there so no need to check
        high[i] = l;
    }

    // for(int i = 1; i <= 10; i++) cout << high[i] << endl;
    
    vector<ll> ans(N+1);
    for(int i = 1; i <= N; i++) {
        if(high[i]) {
            for(int j = i; j <= N; j+=i) {
                ans[j] = max(ans[j], lcm(ll(j), ll(high[i])));
            }
        }
    }

    for(int i = 0; i < q; i++) {
        int x; cin >> x;
        cout << ans[x] << " ";
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