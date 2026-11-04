#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    // cout << n << endl;
    int ev = 0; int ind = -1;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
    {   cin >> a[i]; }

    for(int i = 0; i < n; i++) {
        if(!(a[i]%2))
        if(ev) {cout << ev << " " << a[i]; return;}
        else {ev = a[i]; ind = i;}}
        
 
 
    if(ev) {
        for(int i = ind-1; i >= 0; i--) {
            if(!((ev%a[i])%2)) {cout << a[i] << " " << ev; return;}
        }
    }
 
 
 
    if(ev) a.erase(a.begin() + ind);
 
 
 
    for(int i = 0; i < a.size()-1; i++) {
        if(!((a[i+1]%a[i])%2)) {cout << a[i] << " " << a[i+1]; return;}
    }
 
    for(int i = 0; i < a.size(); i++)
        for(int j = i+1; j < a.size(); j++) {
            if(!((a[j]%a[i])%2)) {cout << a[i] << " " << a[j]; return;}
        }
 
    cout << -1;
 
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}