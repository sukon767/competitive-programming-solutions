#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n), ans(n); multiset<int> bSort;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        bSort.insert(x); bSort.insert(x+n);
    }

    // for(int x: bSort)
    //     cout << x << "\n";
    // cout << "\n";
    
    for(int i = 0; i < n; i++) {
        auto it1 = bSort.lower_bound((n-a[i])%n); auto it2 = it1;
        if(*it1 < n)
            it2 = bSort.lower_bound(*it1 + n);
        else
            it2 = bSort.lower_bound(*it1 - n);
        ans[i] = (a[i] + *it1)%n; bSort.erase(it1); bSort.erase(it2);
        // cout << *it1 << "\n";
    }

    for(int i = 0; i < n-1; i++)
        cout << ans[i] << " ";
    cout << ans[n-1];

}