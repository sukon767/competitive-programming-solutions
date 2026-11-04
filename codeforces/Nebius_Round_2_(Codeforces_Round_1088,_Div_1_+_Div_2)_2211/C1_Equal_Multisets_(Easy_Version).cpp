#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n); for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    vector<bool> tak(n+1);
    for(int i = 0; i < n; i++) {
        if(b[i] != -1) {
            if(tak[b[i]]) {cout << "NO"; return;}
            else tak[b[i]] = true;
        }
    }

    for(int i = 0; i < n-k; i++) {
        if(b[i] == -1) {
            if(tak[a[i]]) {cout << "NO"; return;}
        } else if(b[i] != a[i]) {
            {cout << "NO"; return;}
        }
        b[i] = a[i];
        tak[a[i]] = true;
    }

    for(int i = k; i < n; i++) {
        if(b[i] == -1) {
            if(tak[a[i]]) {cout << "NO"; return;}
        } else if(b[i] != a[i]) {
            {cout << "NO"; return;}
        }
        b[i] = a[i];
        tak[a[i]] = true;
    }

    cout << "YES";
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