#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;

    int l = 0, r = n;

    while(l < r) {
        int mid = (l+r+1)>>1;
        
        // cout << mid << endl;

        vector<bool> hv(mid);
        vector<int> b;
        for(int i = 0; i < n; i++) {
            if(a[i] >= mid || hv[a[i]]) {
                b.push_back(a[i]);
            } else hv[a[i]] = true;
        }

        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());

        int on = mid-1;

        for(int i = 0; i < sz(b); i++) {
            // cout << i << " " << on << " " << b[i] << endl;
            while(on >= 0 && hv[on]) on--;
            if(on < 0) break;
            if(on*2 < b[i]) {hv[on] = true;}
        }

        while(on >= 0 && hv[on]) on--;

        if(on < 0) {
            l = mid;
        } else {
            r = mid-1;
        }
    }

    cout << l;

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

 /* new testament
 * nick belov always reads the entire problem statement.
 */