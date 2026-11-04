#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    ll d, k; cin >> d >> k;
    map<int, bool> bound;

    ll top = d/k*k;
    ll y = d/k * k;
    ll x = 0;
    while(y >= 0) {
        bound[x-y] = true;
        // cout << x-y << "\n";
        x+=k;
        if(x > top) break;
        while(x*x + y*y > d*d) {
            y-=k;
        }
    }

    x = 0; y = 0;
    int i = 0;

    while(x*x + y*y <= d*d) {
        // cout << i << "\n";
        if(bound[x-y]) {
            // cout << x-y << "\n";
            if(i%2) cout << "Ashish";
            else cout << "Utkarsh";
            return;
        }
        x+=k;
        i++;
    }

    
}

int main() {
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}