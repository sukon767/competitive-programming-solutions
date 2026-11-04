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
    string s; cin >> s;
    vector<vector<int>> next(n, vector<int>(10, n));
    for(int i = n-2; i >= 0; i--) {
        next[i] = next[i+1];
        next[i][s[i+1]-'0'] = i+1;
    }
    vector<ll> ans(n);
    vector<pair<ll, ll>> q1, q2;
    for(int l = 0; l < n; l++) {
        int c = (s[l]=='2' ? l : next[l][2]);
        if(c==n) continue;
        c = next[c][0];
        if(c==n) continue;
        c = next[c][2];
        if(c==n) continue;

        
        int n5 = next[c][5], n6 = next[c][6];
        // cout << l << " " << c << " " << n5 << " " << n6 << endl;
        if(n5 >= n6) continue;
        //n5 to n6-1.
        q1.push_back({n5+1, n6+1});
        q2.push_back({l, n6-n5});

    }

    for(auto [l, r] : q1) {
        if(l < n) ans[l]--;
        if(r < n) ans[r]++;
    }
    partial_sum(all(ans), ans.begin());

    // for(ll x : ans) cout << x << ' ';
    // cout << endl;

    for(auto [l, del] : q2) {
        ans[l]+=del;
        // cout << l << " " << del << endl;
    }
    partial_sum(all(ans), ans.begin());

    // for(ll x : ans) cout << x << " ";

    for(ll i = 0; i < n; i++) {
        cout << (i+1)*(n-i) - ans[i] << " ";
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