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
    if(n == 2) {
        cout << "3\n";
        for(int i = 0; i < 3; i++) cout << 3 << " ";
        return;
    }
    vector<int> ans;
    int st = 0;
    for(int b = 0; b < 3; b++) {
        for(int i = 2*n-st; i >= 2; i-=2) {
            ans.push_back(i);
            st = (st+2)%3;
        }
        st = (st+2)%3;
    }
    cout << sz(ans) << "\n";
    for(int x : ans) cout << x << " ";
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