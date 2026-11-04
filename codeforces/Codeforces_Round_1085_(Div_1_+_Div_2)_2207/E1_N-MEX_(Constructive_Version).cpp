#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n); for(int &i : a) cin >> i;

    if(n == 1) {
        if(a[0] == 0) cout << "YES\n67";
        else if(a[0] == 1) cout << "YES\n0";
        else cout << "NO";
        return;
    }

    queue<int> up;

    if(a.back() > n) {cout << "NO"; return;}
    for(int i = 0; i < a.back(); i++) up.push(i);

    for(int i = n-2; i >= 0; i--) {
        
        if(a[i] > n) {cout << "NO"; return;}
        if(a[i] < a[i+1]) {cout << "NO"; return;}
        if(a[i] == a[i+1]) {
            if(!up.size()) {cout << "NO"; return;}
            b[i+1] = up.front();
            up.pop();
        } else {
            b[i+1] = a[0]+1;
            for(int j = a[i+1]+1; j < a[i]; j++) up.push(j);
        }
    }
    if(!up.size()) {b[0] = a[0]+1;}
    else {b[0] = up.front(); up.pop();}
    
    if(up.size()) {cout << "NO"; return;}

    map<int, bool> check; for(int x : b) check[x] = true;
    int mon = 0;
    while(check[mon]) mon++;
    if(mon != a.back()) {cout << "NO"; return;}
    cout << "YES\n";
    for(int x : b) cout << x << " ";
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