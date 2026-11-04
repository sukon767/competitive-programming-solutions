#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string a;
    cin>>a; 
    int n = a.size();
    for(int i= 0; i < n-1; i++) if((a[i] == '>' && a[i+1] == '<') || (a[i] == '>' && a[i+1] == '*') || (a[i] == '*' && a[i+1] == '<') || (a[i] == '*' && a[i+1] == '*')) {cout << -1; return;}
    for(int i = 0; i < n; i++) if(a[i] == '*') {cout << max(i+1, n-i); return;}

    for(int i = 0; i < n; i++) if(a[i] == '>') {cout << max(i, n-i); return;}
    cout << n;

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