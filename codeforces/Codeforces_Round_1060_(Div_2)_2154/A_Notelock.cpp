#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int solve() {
    int n, k;
    cin >> n >> k;
    queue<char>  thing;
    string a;   cin >> a;
    int cur = 0;     int ans = 0;

    int start = k-1;
    for(int i = 0; i < k-1; i++) {thing.push(a[i]); if(a[i] == '1') {cur=1; ans++; start = i+1; break;}}

    // cout << cur << "cur" << "\n";

    for(int i = start; i < n; i++) {
        if(a[i] == '1' && !cur) ans++;
        if(thing.size() == k-1) {
            if(thing.front() == '1')
                cur--;
            thing.pop();
        }   
        
        if(a[i] == '1') cur++;
        thing.push(a[i]);
        
        
    }

    cout << ans;
    
    return 0;
}

int main() {
    int t;
    cin >>t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}