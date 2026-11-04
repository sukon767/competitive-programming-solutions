#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n); for(int& i : a) cin >> i;
    vector<int> stk;
    vector<int> rt(n, n), lt(n, -1);

    for(int i = 0; i < n; i++) {
        while(sz(stk) && a[stk.back()] > a[i]) {
            rt[stk.back()] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }
    stk.clear();
    for(int i = n-1; i >= 0; i--) {
        while(sz(stk) && a[i] > a[stk.back()]) {
            lt[stk.back()] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }
    
    vector<int> rt2(n, n);
    for(int i = 0; i < n; i++) {
        if(lt[i] != -1 && rt[i] != n) {
            rt2[lt[i]] = min(rt2[lt[i]], rt[i]);
        }
    }

    vector<vector<int>> qu;
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        qu.push_back({--l, --r, i, -1});
    }

    sort(qu.begin(), qu.end());
    
    
    int on = q-1;
    int ans = n;
    for(int i = n-1; i >= 0; i--) {
        ans = min(ans, rt2[i]);
        while(on>=0 && qu[on][0] == i) {
            qu[on].back() = (ans <= qu[on][1]);
            on--;
        }
    }
    // cout << "asdf" << endl; 

    sort(qu.begin(), qu.end(), [&](const auto& a, const auto& b) {return a[2] < b[2];});

    for(int i = 0; i < q; i++) {
        if(!qu[i].back()) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
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