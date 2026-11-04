#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    string a1 = a, b1 = b;
    int q; cin >> q;
    vector<int> p(n);

    for(int i = 0; i < n-2; i++) {
        if(a[i] == a[i+2] && a[i] == '0') b1[i+1] = '1';
    }
    for(int i = 0; i < n-2; i++) {
        if(b1[i] == b1[i+2] && b1[i] == '1') a1[i+1] = '1';
    }
    
    for(int i = 0; i < n; i++) {
        p[i] = a1[i]-'0';
        if(i) p[i] += p[i-1];
    }

    for(int s = 0; s < q; s++) {
        int l, r; cin >> l >> r;
        l--; r--;
        if(r-l+1 <= 4) {
            string x = a.substr(l, r-l+1);
            string y = b.substr(l, r-l+1);
            for(int i = 0; i < r-l-1; i++) {
                if(x[i] == x[i+2] && x[i] == '0') y[i+1] = '1';
            }
            for(int i = 0; i < r-l-1; i++) {
                if(y[i] == y[i+2] && y[i] == '1') x[i+1] = '1';
            }
            int ans = 0;
            for(char c : x) ans += c - '0';
            cout << ans << "\n";
            // cout << x << " " << y << endl;
        } else {
            int ans = p[r-2] - p[l+1];
            string x, y;
            x = a.substr(l, 2)+a.substr(r-1, 2);
            y = b.substr(l, 2)+b.substr(r-1, 2);
            if(x[0] == '0' && a[l+2] == '0') y[1] = '1';
            if(a[r-2] == '0' && x[3] == '0') y[2] = '1';
            
            if(y[0] == '1' && b1[l+2] == '1') x[1] = '1';
            if(b1[r-2] == '1' && y[3] == '1') x[2] = '1';

            // cout << x << " " << y << " " << ans << " " << endl;
            for(char c : x) ans += c-'0';
            cout << ans << "\n";
        }
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