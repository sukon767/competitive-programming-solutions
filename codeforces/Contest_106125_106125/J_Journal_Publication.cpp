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
    int n; cin >> n;
    vector<vector<string>> x(n);
    for(int i = 0; i < n; i++) {
        int p; cin >> p;
        for(int j = 0; j < p; j++) {
            string s; cin >> s; x[i].push_back(s);
        }
            
    }

    vector<string> ans(n);

    for(int i = 0; i < n; i++) sort(x[i].begin(), x[i].end());
    string cur = "";
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(x[i].begin(), x[i].end(), cur);
        if(it == x[i].end()) {cout << "impossible"; return;}
        else cur = *it;
        ans[i] = *it;
    }

    for(int i= 0; i < n; i++) {
        if(i) cout << "\n";
        cout << ans[i];
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