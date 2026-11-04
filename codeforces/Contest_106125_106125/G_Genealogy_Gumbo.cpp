#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

/*
dp[i] = it is possible to make intervals of size >= k up to i
iterate the right endpoint
iterate the left endpoint
for all intervals of size >=k that can be made valid 
interval -> [j, i]
take any such dp[j-1] and set dp[i] = dp[j-1]
how to find interval?
iterate right endpoint, iterate left starting at i-k+1
while everyone inside can be put inside it is good
dp[0] = true
dp[i] = false
iterate all valid max intervlas starting from 
i-k+1 to 0
24 * 1000 * 1000 * log(1000)

maintain set of transpositions s.t. it lands in interval
keep expanding window while there is nonoverlap

*/

void solve() {
    int n;
    cin >> n;
    vector<int> outdeg(2*n);
    vector<vector<int>> g(2*n);
    map<string,int> id;
    set<string> seen;
    int T = 0;
    for(int i = 0; i < n; i++) {
        string son, parent;
        cin >> son;
        string tmp;
        cin >> tmp;
        cin >> tmp;
        cin >> parent;
        son.pop_back();
        if(not seen.count(son)) {
            id[son]=T++;
            seen.insert(son);
        }
        if(not seen.count(parent)) {
            id[parent]=T++;
            seen.insert(parent);
        }
        outdeg[id[son]]++;
        g[id[son]].push_back(id[parent]);
        g[id[parent]].push_back(id[son]);
    }
    int c =0;
    for(int i = 0; i < T; i++) {
        if(outdeg[i]==0) c++;
    }
    bool connected = 1;
    vector<int> vis(2*n);
    auto DFS = [&](auto self, int v) ->void {
        for(auto u : g[v]) {
            if(vis[u]) continue;
            vis[u]=true;
            self(self, u);
        }
    };
    DFS(DFS, 0);
    for(int i = 0; i < T; i++) {
        if(not vis[i]) connected = 0;
    }
    if(!connected or c>=2) {
        cout << "impossible" << '\n';
    } else {
        cout << "possible" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}