#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    map<int, int> asdf;
    for(int i = 0; i < n; i++) {int x; cin >> x; asdf[x]++;}
    int j =0;
    while(asdf[j]) {
        j++;
    }

    cout << j;
}

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}