#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n, X, y; cin >> n >> X >> y;
    vector<int> a(X); for(int& i : a) {cin >> i; i--;}
    sort(all(a));
    int ans = X-2;
    vector<int> rns;
    for(int i = 0; i < X; i++) {
        int x = (a[(i+1)%X] - a[i] + n)%n -1;
        if(x > 1) rns.push_back(x);
        else ans += x;
    }

    //odds
    sort(all(rns));
    for(int x : rns) {
        if(x%2) {
            if(y >= x/2) {
                ans += x;
                y -= x/2;
            } else {
                ans += 2*y;
                y = 0;
            }
        }
    }

    //evens
    for(int x : rns) {
        if(x%2 == 0) {
            if(y >= x/2) {
                ans += x;
                y -= x/2;
            } else {
                ans += 2*y;
                y = 0;
            }
        }
    }

    cout << ans;
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

 /* new testament
 * nick belov always reads the entire problem statement.
 */