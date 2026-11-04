#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, a, b; cin >> n >> a >> b; a--; b--;
    bool ok = 0;
    if(b==0) {
        swap(a, b);
        ok = 1;
    }
    if(0 < a+b && a+b < n) {
        cout << "yes\n";
        vector<int> h(n);
        for(int i = 0; i < a; i++) h[i] = i+1;
        h[a] = n;
        for(int i = a+1; i < n; i++) h[i] = i;
        //a + (n-a-b)
        // cout << (a + (n-a-b)+1) << endl;
        reverse(h.begin() + (a + (n-a-b)), h.end());
        if(ok) reverse(all(h));
        for(int x : h) cout << x << " ";
    } else cout << "no";
}

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

 /* new testament
 * nick belov always reads the entire problem statement.
 */