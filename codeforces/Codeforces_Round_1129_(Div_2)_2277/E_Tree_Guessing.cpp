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
    vector<pair<int, int>> sn = {{n, 1}};
    for(int i = 2; i <= n; i++) {
        cout << "? 1 " << n-1 << " ";
        int on = 1;
        for(int j = 2; j <= n; j++) {
            if(j == i) cout << n << " ";
            else {cout << on << " "; on++;}
        }
        cout << endl;
        int sum; cin >> sum;
        sn.push_back({sum - (n-1)*n, i});
    }

    sort(sn.rbegin(), sn.rend());
    vector<pair<int, int>> ans;
    ans.push_back({sn[0].s, sn[1].s});
    int prev = (n-1)*n + sn[1].f;

    for(int i = 2; i < n; i++) {
        vector<int> p(n+1);
        for(int j = 0; j <= i; j++) p[sn[j].s] = n-(i-j);
        for(int j = i+1; j < n; j++) p[sn[j].s] = j-i;
        cout << "? 1 "; for(int i = 1; i <= n; i++) cout << p[i] << " ";
        cout << endl;

        prev -= n;
        int sum; cin >> sum;
        int k = (sum-prev)/sn[i].f;

        ans.push_back({sn[i-k].s, sn[i].s});
        prev = sum;
    }

    cout << "!" << endl;
    for(auto &[u, v] : ans) cout << u << " " << v << endl;
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