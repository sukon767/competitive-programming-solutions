#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t; cin >> t; vector<string> ans;
    for(int d = 0; d < t; d++) {
        int n; cin >> n; vector<int> a(n), b(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];

        sort(a.begin(), a.end()); sort(b.begin(), b.end()); 
        a.erase(unique(a.begin(), a.end()), a.end()); b.erase(unique(b.begin(), b.end()), b.end());
        vector<int> c;
        for(ll ai : a)
            for(ll bi : b)
                c.push_back(ai+bi);
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        if(c.size() >= 3)
            ans.push_back("YES");
        else
            ans.push_back("NO");
    }
    for(int i = 0; i < t - 1; i++)
        cout << ans[i] << "\n";

    cout << ans[t-1];
}