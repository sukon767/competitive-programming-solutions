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
    vector<ll> a(n); for(ll& i : a) cin >> i;
    vector<pair<int, int>> rns = {{1, 1}};
    for(int i = 0; i < n-2; i++) {
        if(abs(a[i])%2 == abs(a[i+2])%2) rns.back().s++;
        else rns.push_back({rns.back().s+1, rns.back().s+1});
    }
    for(int i = n-1; i > 0; i--) a[i] -= a[i-1];
    for(auto &p : rns) {
        // if(p.s < n) {
            sort(a.begin()+p.f, a.begin()+min(n, p.s+1));
        // }
    }

    partial_sum(all(a), a.begin());
    for(ll x : a) cout << x << " ";
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