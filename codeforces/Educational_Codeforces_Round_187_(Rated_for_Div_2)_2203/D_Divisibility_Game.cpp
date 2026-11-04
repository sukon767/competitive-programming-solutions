#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, m; cin >> n >> m;
    vector<int> cnta(n+m+1), facnt(n+m+1), b(m); for(int i = 0; i < n; i++) {int u; cin >> u; cnta[u]++;} for(int &i : b) cin >> i;
    for(int i = 1; i <= n+m; i++)
        for(int j = i; j <= n+m; j+=i) {
            facnt[j] += cnta[i];
        }

    vector<int> ty(3);
    for(int x : b) {
        if(facnt[x] == n) ty[0]++;
        else if(facnt[x] == 0) ty[1]++;
        else ty[2]++;
    }


    if(ty[2]%2) {
        if(ty[0] >= ty[1]) cout << "Alice";
        else cout << "Bob";
    } else {
        if(ty[1] >= ty[0]) cout << "Bob";
        else cout << "Alice";
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