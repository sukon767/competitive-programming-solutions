#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    const int N = 10000000;
    vector<int> lp(N+1);
    vector<int> pr;

    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }

    vector<ll> nm(sz(pr));
    vector<int> mp(N+1); for(int i = 0; i < sz(pr); i++) mp[pr[i]]=i;
    int n; cin >> n;
    vector<ll> a(n); for(ll& i : a) cin >> i;
    sort(all(a));
    for(int i = 0; i < n; i++) {
        for(int j = i?a[i-1]+1:1; j <= a[i]; j++) {
            int k = j;
            while(k > 1) {
                nm[mp[lp[k]]]+=n-i;
                k/=lp[k];
            }
        }
    }

    ll lo = 0, hi = 1e14;
    while(lo < hi) {
        ll m = (lo+hi)>>1;
        bool ok = 1;
        for(int i = 0; i < sz(pr); i++) {
            ll z = 0; ll tm = m/pr[i];
            while(tm) {z+=tm; tm/=pr[i];}
            if(z < nm[i]) {ok=0; break;}
        }

        if(ok) hi = m;
        else lo = m+1;
    }
    cout << max(lo, 1LL);
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