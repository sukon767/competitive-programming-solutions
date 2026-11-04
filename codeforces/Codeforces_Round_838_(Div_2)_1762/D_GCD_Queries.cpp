#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    set<int> inds;
    for(int i = 0; i < n; i++)  inds.insert(i);

    while(inds.size() > 2) {
        auto it = inds.begin();
        int a = *it; int b = *next(it); int c = *next(next(it));
        cout << "? " << a+1 << " " << b+1 << endl << flush;
        int x1; cin >> x1;
        cout << "? " << a+1 << " " << c+1 << endl << flush;
        int x2; cin >> x2;
        if(x1 == x2) inds.erase(a);
        else if(x1 > x2) inds.erase(c);
        else inds.erase(b);
    }

    cout << "! " << (*inds.begin())+1 << " " << (*(next(inds.begin())))+1 << endl << flush;
    int ans; cin >> ans;
    if(ans == -1) {exit(0);}
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}