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
    int n, a, b, k, f; cin >> n >> a >> b >> k >> f;
    map<array<string, 2>, int> cost;
    string lst = "";
    for(int i = 0; i < n; i++) {
        array<string, 2> t; cin >> t[0] >> t[1];
        int cst = a;
        if(lst == t[0]) cst = b;
        lst = t[1];
        sort(all(t));
        cost[t] += cst;
    }
    vector<int> hr;
    for(auto &p : cost) hr.push_back(p.s);
    sort(all(hr)); reverse(all(hr));

    for(int i = 0; i < min(sz(hr), k); i++) {
        hr[i] = min(hr[i], f);
    }
    cout << accumulate(all(hr), 0LL);
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