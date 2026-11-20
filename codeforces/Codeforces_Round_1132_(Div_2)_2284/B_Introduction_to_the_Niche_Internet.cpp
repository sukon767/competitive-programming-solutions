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
    vector<ll> a(n); for(auto &i : a) cin >> i;
    sort(all(a));
    int cnt = count(all(a), a.back());
    if(k < cnt) {
        cout << "NO"; return;
    }
    cout << "YES\n";
    for(int i = n-k; i < n; i++) cout << a[i] << " ";
    for(int i = n-k-1; i >= 0; i--) cout << a[i] << " "; 
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