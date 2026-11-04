#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n, k; cin >> n >> k;
    if(k%2==1) {
        for(int i = 0; i < k; i++) cout << n << " ";
        return;
    }

    vector<int> a(k);
    int l = 0;
    for(int i = 30; i >= 0; i--) {
        if(n>>i&1) {
            for(int j = 0; j < k; j++) {
                if(l%k == j) continue;
                a[j]|=(1<<i);
            }
            l++;
        } else {
            for(int j = 0; j < l/2*2; j++) {
                if(j >= k) break;
                a[j]|=(1<<i);
            }
        }
    }

    for(int &i : a) cout << i << " ";
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