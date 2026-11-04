#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>>  qs(q);
    for(int i = 0; i < q; i++) {
        cin >> qs[i].first >> qs[i].second;
        qs[i].first--;  qs[i].second--;
    }

    set<int>    dubs;
    for(int i = 0; i < n-1; i++)
        if(a[i] == a[i+1])  dubs.insert(i);

    vector<int> z(n), o(n);
    if(a[0])    o[0]++;
    else    z[0]++;

    for(int i = 1; i < n; i++) {
        z[i] = z[i-1];  o[i] = o[i-1];
        if(a[i])    o[i]++;
        else    z[i]++;
    }

    for(int i = 0; i < q; i++) {
        if(i)   cout << "\n";

        int l = qs[i].first; int r = qs[i].second;
        int zeros, ones;
        zeros = z[r];   ones = o[r];
        if(l) {zeros-=z[l-1]; ones-=o[l-1];}

        if((zeros%3) || (ones%3))   {cout << -1;    continue;}

        auto it = dubs.lower_bound(l);
        if(it != dubs.end() && ((*it) + 1) <= r) {
            cout << (r-l+1)/3;
        }   else {
            cout << 1 + (r-l+1)/3;
        }

    }

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