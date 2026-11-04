#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n); for(int& i : a) cin >> i;
    for(int& i : b) cin >> i;
    for(int& x : a) if(x!=-1)x--;
    for(int& x : b) if(x!=-1)x--;
    vector<int> stk;
    for(int i = 0; i < n; i++) {
        if(b[i]!=-1) stk.push_back(i);
    }

    while(sz(stk)) {
        int i = stk.back(); stk.pop_back();
        if(b[a[i]] != -1 && b[a[i]] != a[b[i]]) {
            cout << "NO"; return;
        } else if(b[a[i]] == -1) {
            stk.push_back(a[i]);
            b[a[i]]=a[b[i]];
        }
    }

    vector<int> f(n);
    for(int x : b) if(x!=-1) f[x]++;
    for(int x : f) if(x>1) {
        cout << "NO"; return;
    }

    vector<vector<int>> cont(n+1);
    //what we need to do is, for each cycle with no indeg, get its representatively smallest element and index.
    vector<int> in(n);
    for(int i = 0; i < n; i++) {
        if(b[i]!=-1) in[b[i]]++;
    }

    vector<vector<int>> cyc;
    vector<bool> vis(n);
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            int x = i;
            cyc.push_back({});
            while(!vis[x]) {
                cyc.back().push_back(x);
                vis[x] = 1;
                x = a[x];
            }
        }
    }

    vector<int> sof(n);
    for(auto& v : cyc) {
        if(!in[v[0]]) {
            cont[sz(v)].push_back(*min_element(v.begin(), v.end()));
        }
        for(auto& x : v) sof[x]=sz(v);
    }

    for(int i = 0; i <= n; i++) {
        sort(cont[i].begin(), cont[i].end()); 
        reverse(cont[i].begin(), cont[i].end());
    }

    for(int j = 0; j < n; j++) {
        if(b[j]==-1) {
           b[j] = cont[sof[j]].back();
           cont[sof[j]].pop_back();
           stk.push_back(j);
        }
        while(sz(stk)) {
            int i = stk.back(); stk.pop_back();
            if(b[a[i]] != -1 && b[a[i]] != a[b[i]]) {
                cout << "NO"; return;
            } else if(b[a[i]] == -1) {
                stk.push_back(a[i]);
                b[a[i]]=a[b[i]];
            }
        }
    }
    
    fill(f.begin(), f.end(), 0);
    for(int x : b) if(x!=-1) f[x]++;
    for(int x : f) if(x>1) {
        cout << "NO"; return;
    }

    cout << "YES\n";
    for(int x : b) cout << x+1 << " ";
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