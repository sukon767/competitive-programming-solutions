#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;

    a.erase(unique(a.begin(), a.end()), a.end());
    
    // int c = 0;
    function<ll(vector<int>)> bruh = [&](vector<int> a) -> ll {
        if(!a.size()) return 0;
        if(a.size() == 1 && a[0] == 1) {return 5;}


        // for(int x : a) cout << x << " ";
        // cout << endl;

        ll ans = -1;
        for(int i = 0; i < 42; i++) {
            vector<int> b;
            bool ad = true;
            for(int x : a) {
                if((x+i) % 42) {if((x+i)%6) {ad = false; break;}}
                else b.push_back((x+i)/42);
            }
                

            if(!ad) continue;

            b.erase(unique(b.begin(), b.end()), b.end());
            ll df = bruh(b);

            // if(i == 5) {
            //     cout << df << " why " << b.size() << endl;  
            // } 

            if(df != -1) {
                if(ans == -1) ans = i + 42*df;
                else ans = min(ans, i + 42*df);
            }
        }
        return ans;
    };

    cout << bruh(a);

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