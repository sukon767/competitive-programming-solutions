#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int> move(n), ans(n);
    int t;
    cout << "+ " << n+1 << endl;
    cin >> t;
    cout << "+ " << n+2 << endl;
    cin >> t;
    for(int i = 1; i < n; i++) {
        cout << "? " << i << " " << i+1 << endl;
        cin >> t;
        move[i] = t;
    }

    ll s = move[1];
    ll high = max(0LL, s);
    for(int i = 1; i < n-1; i++) {
        cout << "? " << i << " " << i+2 << endl;
        cin >> t;
        if((abs(move[i]) + abs(move[i+1]) == t) == (move[i] < 0)) move[i+1] *= -1;
        s += move[i+1];
        high = max(high, s);
    }

    // for(int i = 1; i < n; i++) cout << move[i] << " " << endl;
    // cout << high << endl;

    //so it could be start = n-high

    s = n-high;
    for(int i = 1; i <= n; i++) {
        if(s%2) {
            ans[i-1] = 1+s/2;
        } else {
            ans[i-1] = n+1 - s/2;
        }
        if(i < n) s += move[i];
    }

    

    cout << "!";
    for(int i = 0; i < n; i++) cout << " " << ans[i];

    ans.assign(n, 0);
    for(int &x : move) x = -x;
    s = high+1;
    for(int i = 1; i <= n; i++) {
        if(s%2) {
            ans[i-1] = 1+s/2;
        } else {
            ans[i-1] = n+1 - s/2;
        }
        if(i < n) s += move[i];
    }
    for(int i = 0; i < n; i++) cout << " " << ans[i];
    cout << endl;
    cin >> t;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */