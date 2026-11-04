#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> xs;
    vector<pair<int, int>> temp;
    for(int i =0 ; i < n; i++) {
        int x, y; cin >> x >> y;
        xs.push_back(x);
        temp.push_back({x, y});
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    map<int, int> comp;
    for(int i =0; i < xs.size(); i++) comp[xs[i]] = i;

    vector<vector<int>> lis(xs.size());

    for(auto &p : temp) {
        lis[comp[p.first]].push_back(p.second);
    }

    for(auto &v : lis) sort(v.begin(), v.end());

    if(lis.size()%2) {
        xs.push_back(xs.back()+1); lis.push_back({});
    }


    for(int i = 0; i < lis.size(); i+=2) {
        int s1 = lis[i].size(), s2 = lis[i+1].size();
        int dif = abs(s1-s2);
        if(s1 < s2) {
            for(int j = 0; j < dif; j++) {
                if(!lis[i].size()) lis[i].push_back(0);
                else lis[i].push_back(lis[i].back()+1);
            }
        } else {
            for(int j = 0; j < dif; j++) {
                if(!lis[i+1].size()) lis[i+1].push_back(0);
                else lis[i+1].push_back(lis[i+1].back()+1);
            }
        }
    }


    int smol = -1e9;
    int big = 1e9;

    vector<pair<int, int>> ans;


    ans.push_back({xs[0]-1, smol});
    for(int i = 0; i < lis.size(); i+=2) {

        for(int j = 0; j < lis[i].size(); j++) {
            ans.push_back({xs[i], lis[i][j]});
            ans.push_back({xs[i+1], lis[i+1][j]});
        }
        ans.push_back({xs[i+1], big});
    }

    ans.push_back({xs.back()+1, smol});

    cout << ans.size() << "\n";
    for(auto &p : ans) cout << p.first << " " << p.second << "\n";
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