#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        int n, q; cin >> n >> q;
        multiset<int> a; for(int i = 0; i < n; i++) {int u; cin >> u; a.insert(u);}
        
        while(q--) {
            int c; cin >> c;
            int ans = 0;
            multiset<int> erased, trash;

            for(int b = 29; b >= 0; b--) {
                if(!(c & (1 << b))) continue;
                int x = *(--a.end());
                if(x >= ((1<<(b+1)) - 1)) break;
                if(x >= (1 << b)) {a.insert(x ^ (1<<b)); trash.insert(x ^ (1<<b));}
                else {ans += (1<<b) - x; a.insert(0); trash.insert(0);}
                erased.insert(x); a.erase(a.find(x));
            }

            for(int x : erased) a.insert(x);
            for(int x : trash) a.erase(a.find(x));
            
            cout << ans << "\n";
        }
    }
}