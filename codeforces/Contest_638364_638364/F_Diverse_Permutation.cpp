#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int solve() {
    int n, k;
    cin >> n >> k;

    vector<int> p;

    for(int i = 0; i < k; i++)
        if(i%2) p.push_back(n - i/2);
        else p.push_back(i/2 + 1);

    if(k%2)
        for(int i = k; i < n; i++)
            p.push_back(k/2 + i-k + 2);
    else
        for(int i = k; i < n; i++)
            p.push_back(n - k/2 - (i-k));

    for(int i = 0; i < n; i++) {
        if(i)   cout << " ";
        cout << p[i];
    }


    return 0;
}

int main() {
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}