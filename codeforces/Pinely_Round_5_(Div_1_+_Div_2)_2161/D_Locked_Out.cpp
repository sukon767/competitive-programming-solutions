#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<vector<int>> inds(n);
    vector<int> a(n); for(int i = 0; i < n; i++) {cin >> a[i]; inds[--a[i]].push_back(i);}
    for(auto &b : inds) sort(b.begin(), b.end());

    vector<int> cur;
    for(int i = 0; i <= inds[0].size(); i++)
        cur.push_back(i);

    for(int i = 1; i < n; i++) {
        // for(int x : cur) cout << x << " ";
        // cout << endl;

        int theend = INT_MAX;
        for(int x : cur) theend = min(theend, x);

        int r = 0;
        for(int j = 0; j < inds[i-1].size(); j++) {
            while(r < inds[i].size() && inds[i][r] <= inds[i-1][j]) {r++;} 
            // cout << r << " " << inds[i][r] << " " << inds[i-1][j] << endl;
            cur[j]+=inds[i].size()-r;
        }

        // for(int x : cur) cout << x << " ";
        // cout << endl;
        
        for(int j = cur.size()-2; j >= 0; j--) cur[j] = min(cur[j], cur[j+1]);

        vector<int> dp(inds[i].size()+1);
        r = 0;

        for(int j = 0; j < inds[i].size(); j++) {
            while(r < inds[i-1].size() && inds[i-1][r] <= inds[i][j]) r++;
            dp[j] = cur[r] + j;
        }
        dp[inds[i].size()] = inds[i].size() + theend;
        // cout << "last" << " " << inds[i].size() << " " << cur[0] << endl;
        cur = dp;
    }

    for(int i = 1; i < cur.size(); i++) cur[i] = min(cur[i-1], cur[i]);
    cout << cur.back();

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}