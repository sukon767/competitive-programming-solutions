#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    map<int, int> ind;
    vector<int> a(n), b(n);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    for(int i = 0; i < n; i++) ind[a[i]] =i;
    bool work = false;
    for(int i = 0; i < n; i++) if(a[i] == b[i]) work = true;

    if(!work) {cout << "NO"; return;}
    for(int i = 0; i < n-1; i++) if(ind[b[i]] > ind[b[i+1]]) {cout << "NO"; return;}
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
