#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    vector<int> e, o;
    pair<int, int> mo = {INT_MAX, INT_MIN}, me {INT_MAX, INT_MIN};

    for(int i = 0; i < n; i++) {
        if(a[i]%2) {o.push_back(a[i]); mo = {min(mo.first, a[i]), max(mo.second, a[i])};}
        else {e.push_back(a[i]); me = {min(me.first, a[i]), max(me.second, a[i])};}
    }
    
    set<int> cur;

    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < sz(e); i++) {
            if(!cur.size()) {cur.insert(e[i]); continue;}
            int mpre = *prev(cur.end());
            if(mpre > e[i]) {
                if(!sz(o) || (e[i] < mo.first && mo.second < mpre)) {
                    cout << "NO"; return;
                }
            }
            cur.insert(e[i]);
        }
        cur.clear();
        swap(e, o);
        swap(me, mo);
    }

    cout << "YES";
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