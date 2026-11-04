#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

 void solve() {
        ll n, X; cin >> n >> X;
        vector<ll> a(n); for(ll &i : a) cin >> i;
        sort(a.begin(), a.end()); ll l = 0, r = n-1;

        vector<ll> ans;
        ll num = 0;
        ll cur = 0;

        
        while(l <= r) {
            if((cur+a[r])/X > cur/X) {
                cur+=a[r]; num += a[r];
                ans.push_back(a[r]);
                r--;
            } else {
                cur+=a[l];
                ans.push_back(a[l]);
                l++;
            }
            
        }

        cout << num << "\n";
        for(ll i = 0; i < n; i++) {
            if(i) cout << " ";
            cout << ans[i];
        }
    }
    
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ll t; cin >> t;
        //ll t = 1;
        for(ll i = 0; i < t; i++) {
            if(i)   cout << "\n";
            solve();
        }
    }