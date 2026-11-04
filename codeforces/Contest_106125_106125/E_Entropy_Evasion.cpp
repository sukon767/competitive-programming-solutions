#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<bool> v(n);
    while(1){
        int mn = 0, ind = -1, sm = 0;
        int a = 0, b = 0;
        int best = -1;
        for(int i = 0; i<n; i++){
            sm+=v[i] ? -1:1;
            if(sm-mn > best){
                best = sm-mn;
                a = ind+1;
                b = i;
            }
            if(sm < mn){
                mn = sm;
                ind = i;
            }
        }
        cout << a+1 << " " << b+1 << endl << flush;
        for(int i = 0; i<n; i++){
            int x; cin >> x;
            v[i] = x;
        }
        int y; cin >> y;
        if(y >= 70) break;
    }
    // int n,m; cin >> n >> m;
    // if(ll(n)*ll(n)-2LL*ll(n) > 4LL*ll(m) || (n&1)){
    //     cout << "impossible\n";
    //     return 0;
    // }
    // vector<vector<bool>> mat(n,vector<bool>(n));
    // while(m--){
    //     int a,b; cin >> a >> b;
    //     mat[--a][--b] = 1;
    //     mat[b][a] = 1;
    // }
    // function<void(int,vector<bool>&,vector<int>&,int&)> dfs = [&](int s, vector<bool>& vis, vector<int>& cnt, int& sz){
    //     vis[s] = 1;
    //     sz++;
    //     for(int i = 0; i<n; i++) if(mat[s][i]) cnt[i]++;
    //     for(int i = 0; i<n; i++) if(!vis[i] && cnt[i] == sz)
    //         dfs(i,vis,cnt,sz);
    // };
    // vector<bool> vis1(n),vis2(n);
    // vector<int> cnt(n);
    // int sz = 0;
    // dfs(0,vis1,cnt,sz);
    // fill(cnt.begin(),cnt.end(),0);
    // if(sz == n){
    //     for(int i = 0; i<n/2; i++) cout << "r\n";
    //     for(int i = 0; i<n/2; i++) cout << "b\n";
    //     return 0;
    // }
    // if(sz < n/2){
    //     cout << "impossible\n";
    //     return 0;
    // }
    // sz = 0;
    // for(int i = 0; i<n; i++) if(!vis1[i]){
    //     dfs(i,vis2,cnt,sz);
    //     break;
    // }
    // if(sz < n/2){
    //     cout << "impossible\n";
    //     return 0;
    // }
    // vector<int> a,b,both;
    // for(int i = 0; i<n; i++){
    //     if(vis1[i] && vis2[i]){
    //         both.push_back(i);
    //     }else if(vis1[i]){
    //         a.push_back(i);
    //     }else if(vis2[i]){
    //         b.push_back(i);
    //     }else{
    //         cout << "impossible\n";
    //         return 0;
    //     }
    // }
    // while(a.size() < n/2 && both.size()){
    //     a.push_back(both.back());
    //     both.pop_back();
    // }
    // while(both.size()){
    //     b.push_back(both.back());
    //     both.pop_back();
    // }
    // if(a.size() != n/2 || b.size() != n/2){
    //     cout << "impossible\n";
    //     return 0;
    // }
    // vector<bool> ret(n);
    // for(int i: a) ret[i] = 1;
    // for(bool b: ret) cout << (b?"r\n":"b\n");
}