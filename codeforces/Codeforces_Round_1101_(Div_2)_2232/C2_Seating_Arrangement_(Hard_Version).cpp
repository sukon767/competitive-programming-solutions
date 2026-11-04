#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll n, x, s; cin >> n >> x >> s;
    string u; cin >> u;

    vector<int> ambis, blocked;
    int ino = 0;
    for(int i = 0; i < n; i++) {
        if(u[i] == 'A') {
            ambis.push_back(i);
        } else if(u[i] == 'I') ino++;
    }

    reverse(ambis.begin(), ambis.end());
    while(sz(ambis) && ino < x) {
        u[ambis.back()] = 'I';
        ino++;
        ambis.pop_back();
    }

    ll ans = 0;
    ll ct = 0;
    for(int i = 0; i < n; i++) {
        if(u[i] == 'I') {
            if(ct < x) {
                ct++; ans++;
            }
        } else {
            if(ct*s-ans) {
                ans++;
            } else blocked.push_back(i);
        }
    }

    reverse(blocked.begin(), blocked.end());

    ll anser = ans;


    
    while(sz(ambis)) {
        ans--;
        while(sz(blocked) && blocked.back() < ambis.back()) blocked.pop_back();
        for(int i = 0; i < s; i++) {
            if(sz(blocked)) {
                blocked.pop_back(); ans++;
            } else break;
        }
        ambis.pop_back();
        anser = max(anser, ans);
    }

    cout << min(anser, min(n, x*s));
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