#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n); for(int &i : a) cin >> i;

    if(n == 1) {
        if(a[0] == 0) cout << "1";
        else if(a[0] == 1) cout << "1";
        else cout << 0;
        return;
    }

    queue<int> up;
    ll ans = 1, MOD = 1e9+7;

    if(a.back() > n) {cout << 0; return;}
    for(int i = 0; i < a.back(); i++) up.push(i);

    for(int i = n-2; i >= 0; i--) {
        
        if(a[i] > n) {cout << 0; return;}
        if(a[i] < a[i+1]) {cout << 0; return;}
        if(a[i] == a[i+1]) {
            if(!up.size()) {cout << 0; return;}
            b[i+1] = up.front();
            ans = ans*up.size()%MOD;
            up.pop();
        } else {
            b[i+1] = a[0]+1;
            ans = ans*(i+2)%MOD;
            for(int j = a[i+1]+1; j < a[i]; j++) up.push(j);
        }
        // cout << i+1 << " " << ans << endl;
    }
    if(!up.size()) {b[0] = a[0]+1;}
    else {b[0] = up.front(); up.pop();}
    
    if(up.size()) {cout << 0; return;}

    map<int, bool> check; for(int x : b) check[x] = true;
    int mon = 0;
    while(check[mon]) mon++;
    if(mon != a.back()) {cout << 0; return;}
    cout << ans;
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