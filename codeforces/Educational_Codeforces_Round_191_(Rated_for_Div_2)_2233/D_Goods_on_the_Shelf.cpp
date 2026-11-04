#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

bool good(vector<int>& v) {
    int n = sz(v);
    map<int, bool> f;
    for(int i = 0; i < n; i++) {
        if(f[v[i]]) return false;
        if(i && (v[i] != v[i-1])) f[v[i-1]] = 1;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) cin >> i;
    map<int, vector<pair<int, int>>> bl;
    for(int i = 0; i < n; i++) {
        if(sz(bl[a[i]])==0 || i != bl[a[i]].back().second+1) bl[a[i]].push_back({i, i});
        else bl[a[i]].back().second++;
    }

    int t = -1;
    for(auto& p : bl) if(sz(p.second) > 1) {t = p.first; break;}
    if(t==-1) {cout << "YES"; return;}

    
    //now examine t.
    auto& v = bl[t];
    if(sz(v) > 3) {cout << "NO"; return;}
    
    // cout << "asdf " << t << endl;
    // for(auto&p : v) cout << p.first << " " << p.second << " ";
    // cout << endl;

    //try left
    for(int i = 0; i < sz(v); i++) {
        if(v[i].first-1>=0) {
            swap(a[v[0].first], a[v[i].first-1]);
            if(good(a)) {cout << "YES"; return;}
            swap(a[v[0].first], a[v[i].first-1]);
        }
        
        if(v[i].second+1 < n) {
            swap(a[v[0].first], a[v[i].second+1]);
            if(good(a)) {cout << "YES"; return;}
            swap(a[v[0].first], a[v[i].second+1]);
        }
    }
    
    //try right
    for(int i = 0; i < sz(v); i++) {
        if(v[i].first-1>=0) {
            swap(a[v.back().second], a[v[i].first-1]);
            if(good(a)) {cout << "YES"; return;}
            swap(a[v.back().second], a[v[i].first-1]);
        }
        
        if(v[i].second+1 < n) {
            swap(a[v.back().second], a[v[i].second+1]);
            if(good(a)) {cout << "YES"; return;}
            swap(a[v.back().second], a[v[i].second+1]);
        }
    }

    cout << "NO";
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