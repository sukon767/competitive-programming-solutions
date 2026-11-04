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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    int lo = 0, hi = n;
    while(lo < hi) {
        int m = (lo+hi+1)>>1;
        //everything less than m
        int extra = 0;
        int left = m;
        vector<bool> f(m);
        for(int x : a) {
            if(x < m && !f[x]) {f[x] = 1; left--;}
            else extra++;
        }
        if(extra >= left && left <= k) lo = m;
        else hi = m-1;
    }
    cout << lo;
}

//king of the sun o_O
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