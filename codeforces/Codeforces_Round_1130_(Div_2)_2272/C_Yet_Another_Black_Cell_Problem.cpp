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
    int n, x; cin >> n >> x;
    vector<int> a(n); for(int &i : a) cin >> i;
    ll lo = 1, hi = 1e9;
    while(lo < hi) {
        ll mid = (lo+hi)>>1;
        vector<int> dp;
        vector<bool> single(n, 1);
        for(int i = 0; i < n; i++) {
            if(i && a[i]-a[i-1]<=mid) single[i] = 0;
            if(i+1<n && a[i+1]-a[i]<=mid) single[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            if(single[i]) {
                int bst = 1 + (sz(dp)>=1 ? dp.back() : 0);
                if(i && single[i-1] && a[i]-a[i-1] <= 2*mid) bst = min(bst, 1 + (sz(dp)>=2 ? dp[sz(dp)-2] : 0));
                dp.push_back(bst);
            }
        }

        if(dp.empty() || dp.back() <= x) hi = mid;
        else lo = mid+1;
    }

    cout << lo;
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