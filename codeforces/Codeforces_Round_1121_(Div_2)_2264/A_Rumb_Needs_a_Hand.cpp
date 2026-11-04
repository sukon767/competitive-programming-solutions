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
    vector<int> p(n);
    for(int &i : p) cin >> i, i--;
    vector<int> ind; for(int i = 0; i < n; i++) if(p[i] != i) ind.push_back(i);
    for(int i = 0; i < sz(ind)-1-i; i++) {
        swap(p[ind[i]], p[ind[sz(ind)-1-i]]);
    }
    for(int i = 0; i < n; i++) if(p[i] != i) {cout << "NO"; return;}
    cout << "YES";
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