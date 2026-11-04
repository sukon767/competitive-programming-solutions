#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define f first
#define s second

void solve() {
    int n; cin >> n;
    n = 2*n+1;
    int st = 1;
    vector<int> ans;

    for(int i = 0; i < 3; i++) {
        int l = 0, r = n-1;
        while(l < r) {
            int m = (l+r)>>1;
            int x;
            cout << "? " << m+1 << " ";
            for(int i = 0; i <= m; i++) {
                cout << (st+i-1)%n+1 << " ";
            }
            cout << endl;
            cin >> x;
            if((m+1)%2 == x%2) l = m+1;
            else r = m;
        }

        ans.push_back((st+l-1)%n+1);
        st = (st+l-1)%n+1;
    }


    cout << "! " << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
}
 
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