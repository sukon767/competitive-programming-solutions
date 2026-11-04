#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define f first
#define s second

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) {
        cin >> i;
    }

    for(int x : a) if(!x) {cout << "YES"; return;}

    
    ll p = 1;
    for(int i = 0; i < n; i++) p *= 3;

    for(int i = 0; i < p; i++) {
        int x1 = 0, x2 = 0;
        bool a1 = false;
        int k = i;
        for(int j = 0; j < n; j++) {
            
            if(k%3 == 1) {x1 += a[j]; a1 = true;}
            else if(k%3 == 2) {x2 += a[j]; a1 = true;}
            k /= 3;
        }
        if((x1 == x2) && a1) {cout << "YES"; return;}
    }
    cout << "NO";
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