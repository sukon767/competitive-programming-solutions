#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t; vector<ll> ans;
    for(int d = 0; d < t; d++) {
        int n; cin >> n;
        vector<ll> len;
        for(int i = 0; i < n; i++) {
            vector<ll> a(n);
            for(int j = 0; j < n; j++)
                cin >> a[j];

            int c = 0;
            for(int j = n-1; j >= 0; j--)
                if(a[j] == 1)
                    c++;
                else
                    break;
            len.push_back(c);
        }
        sort(len.begin(), len.end());

        // for(ll x : len)
        //     cout << x << "\n";

        int c2 = 0;
        for(int i = 0; i < len.size(); i++)
            if(len[i] >= c2)
                c2++;

        ans.push_back(c2);
    }

    for(int i = 0; i < t-1; i++)
        cout << ans[i] << "\n";

    cout << ans[t-1];
}