#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    k = n^k;

    int hb = (31-__builtin_clz(n));
    int hk = (31-__builtin_clz(k));
    if(k==0) hk = -1;
    // cout << hb << " " << hk << " " << k << endl;
    if(hk > hb) {
        cout << "NO";
    } else if(hk == hb) {
        if(n == (1<<hb)) {
            cout << "NO";
        } else {
            cout << "YES\n";
            //last xors are k, 1<<hb, n;
            for(int i = 1; i < n; i++) {
                if(i==(k^(1<<hb)) || i==(1<<hb)) continue;
                cout << i << " ";
            }
            cout << 0;
            if(k^(1<<hb)) cout << " " << (k^(1<<hb));
            cout << " " << (1<<hb);
        }
    } else {
        cout << "YES\n";
        //last xors are k, n;
        for(int i = 1; i < n; i++) {
            if(i==k) continue;
            cout << i << " ";
        }
        cout << 0;
        if(k) cout << " " << k;
    }
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