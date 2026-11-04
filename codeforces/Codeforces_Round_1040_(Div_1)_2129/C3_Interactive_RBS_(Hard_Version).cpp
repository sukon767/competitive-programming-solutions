#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

vector<int> pat;
int m = 11;

void solve() {
    int n; cin >> n;
    vector<bool> ans(n);
    for(int k = 1; k <= n; k+=m) {
        cout << "? " << sz(pat);
        for(int x : pat) {
            cout << " " << (x ? min(n, x+k-1) : 1);
        }
        cout << endl;
        int l; cin >> l;
        for(int b = 0; b < m; b++) {
            ans[min(n, k+b) -1] = l>>b&1;
            // cout << min(n, k+b) << " " << (l>>b&1) << endl;
        }
    }


    string s;
    bool z = 0;
    for(int i = 0; i < n; i++) {
        if(ans[i]) {
            cout << "? 2 1 " << i+1 << endl;
            cin >> z;
            break;
        }
    }

    cout << "! ";
    for(int i = 0; i < n; i++) {
        cout << (ans[i]^z ? '(' : ')');
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < m; i++) {
        vector<int> block;
        int k = 1LL<<i;
        while(k) {
            ll j = 1;
            while((j+1)*(j+2)/2 <= k) j++;
            block.push_back(j);
            k -= j*(j+1)/2;
        }
        for(int x : block) {
            for(int j = 0; j < x; j++) {pat.push_back(0); pat.push_back(i+1);}
            pat.push_back(0);
        }
    }

    // for(int i = 0; i < 100; i++) {
    //     cout << pat[i] << " ";
    // }
    // cout << endl;

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