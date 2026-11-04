#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    ll sum = 0;
    for(int &i : a) sum += i;

    if(sum%2 || !((n*k)%2)) {cout << "YES";}
    else cout << "NO";
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