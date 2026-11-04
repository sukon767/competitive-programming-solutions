#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<set<pair<int, int>>>> u(11, vector<set<pair<int, int>>>(10));
    for(int i = 0; i < m; i++) {
        int a, d, k;
        cin >> a >> d >> k; a--;
        u[d][a%d].insert({a, a+d*k});
    }

    for(int d = 1; d <= 10; d++)
        for(int r = 0; r < d; r++) {
            set<pair<int, int>> merge;
            if(u[d][r].size()) {
                merge.insert(*u[d][r].begin());
                for(auto it = ++u[d][r].begin(); it != u[d][r].end(); it++) {
                    auto p = *(--merge.end());
                    if((*it).first <= p.second) {
                        merge.erase(p);
                        p.second = max((*it).second, p.second);
                        merge.insert(p);
                    }
                    else merge.insert(*it);
                }
            }

            u[d][r] = merge;
        }

    vector<int> par(n, -1);
    function<int(int)> find = [&](int x){return par[x]<0 ? x : par[x] = find(par[x]);};
    function<bool(int, int)>    unite = [&](int x, int y) {
        x = find(x); y = find(y);
        if(x == y)  return 0;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return 1;
    };

    int ans = n;

    for(int i = 1; i < n; i++) 
        for(int d = 1; d <= min(i, 10); d++) {
            int r = i%d;
            if(u[d][r].size()) {
                auto it = u[d][r].lower_bound({i+1, i+1});
                it--;

                if(it == u[d][r].end()) continue;
                
                if((*it).first+d <= i && i <= (*it).second)   {if(unite(i, i-d)) ans--;}
            }
            
            
        }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}