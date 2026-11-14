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
    vector<int> a(n); for(int& i : a) cin >> i;
    pair<int, pair<int, int>> bst = {0, {0, 0}};
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(a[i], a[j]);
            vector<int> f;
            int on = 0;
            vector<bool> cnt(n);
            for(int i = 0; i < n; i++) {
                cnt[a[i]] = 1;
                while(on < n && cnt[on]) on++;
                f.push_back(on);
            }
            bst = max(bst, {f[n-k], {i, j}});
            swap(a[i], a[j]);
        }
    }
    auto p = bst.s;
    if(p.f == p.s) cout << -1;
    else cout << p.f+1 << " " << p.s+1;
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