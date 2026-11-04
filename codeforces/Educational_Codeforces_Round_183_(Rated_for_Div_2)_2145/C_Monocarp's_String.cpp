#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int solve() {
    int n;  cin >> n;
    string s;
    cin >> s;

    int diff = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == 'a') diff++;
        else    diff--;

    vector<int> pre(n);
    if(s[0] == 'a') pre[0] = 1;
    else    pre[0] = -1;

    for(int i = 1; i < n; i++) {
        pre[i] = pre[i-1];
        if(s[i] == 'a') pre[i]++;
        else    pre[i]--;
    }

    map<int, set<int>>  ind;
    ind[0].insert(-1);

    int ans = n;

    for(int i = 0; i < n; i++) {
        ind[pre[i]].insert(i);
        if(ind[pre[i] - diff].size()) {
            int x = *ind[pre[i] - diff].rbegin();
            ans = min(ans, i - x);
        }
    }
        

    if(ans == n)  cout << -1;
    else cout << ans;
    

    return 0;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}