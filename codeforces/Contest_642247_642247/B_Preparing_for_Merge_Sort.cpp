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
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) cin >> i;
    vector<vector<int>> arr;
    for(int x : a) {
        int lo = 0, hi = sz(arr);
        while(lo < hi) {
            int m = (lo+hi)>>1;
            if(arr[m].back() >= x) lo = m+1;
            else hi = m;
        }
        if(lo < sz(arr)) arr[lo].push_back(x);
        else arr.push_back({x});
    }
    for(auto &v : arr) {
        for(auto &x : v) cout << x << " ";
        cout << "\n";
    }
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