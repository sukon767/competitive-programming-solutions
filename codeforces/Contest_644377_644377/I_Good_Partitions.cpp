#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); for(int &i : a) cin >> i;
    vector<vector<int>> fac(n+1);
    for(int i = 1; i <= n; i++) for(int j = i; j <= n; j+=i) fac[j].push_back(i);
    vector<int> sum(n);
    vector<int> f(n+1);
    int cnt = 0;

    auto upd = [&](int i, int dx) {
        cnt += dx;
        for(int d : fac[i]) {
            f[sum[d]]--;
            sum[d]+=dx;
            f[sum[d]]++;
        }
    };
    f[0] = n-1;
    for(int i = 1; i < n; i++) {
        if(a[i-1] > a[i]) upd(i, 1);
    }

    cout << f[cnt]+(cnt==0);

    for(int i = 0; i < q; i++) {
        cout << "\n";
        int p, v; cin >> p >> v; p--;
        if(0 < p && a[p-1] > a[p]) upd(p, -1);
        if(p+1 < n && a[p] > a[p+1]) upd(p+1, -1);
        a[p] = v;
        if(0 < p && a[p-1] > a[p]) upd(p, 1);
        if(p+1 < n && a[p] > a[p+1]) upd(p+1, 1);
        cout << f[cnt]+(cnt==0);

        // cout << endl;
        // for(int i = 0; i < n; i++) cout << i << " " << sum[i] << endl;
        // for(int i = 0; i < n; i++) cout << i << " " << f[i] << endl;
    }
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