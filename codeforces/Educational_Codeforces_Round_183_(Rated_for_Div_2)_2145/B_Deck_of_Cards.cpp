#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int zeros, ones, twos;
    zeros = ones = twos = 0;
    for(int i = 0; i < k; i++)
        if(s[i] == '0') zeros++;
        else if(s[i] == '1')  ones ++;
        else twos++;

    if(n == k) {
        string ans(n, '-');
        cout << ans;
        return 0;
    }
        
    string ans(n, '+');
    for(int i = 0; i < zeros; i++) ans[i] = '-';
    for(int i = n-1; i >= n-ones; i--)   ans[i] = '-';
    for(int i = 0; i < twos; i++) {ans[zeros+i] = '?'; ans[n-ones-1-i] = '?';}

    cout << ans;

    return 0;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}