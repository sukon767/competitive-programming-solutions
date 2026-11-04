#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b; cin >> a >> b;
    int log2a = 0, log2b = 0;
    int a1 = a, b1 = b;
    while(a1) {log2a++; a1>>=1;}
    while(b1) {log2b++; b1>>=1;}
    if(log2b > log2a) {cout << "-1"; return;}

    vector<int> as;
    for(int i = 0; i < 31; i++) {
        if((b & (1<<i)) != (a & (1<<i))) {
            as.push_back((1<<i));
        }
    }

    cout << as.size() << "\n";
    for(int x : as) cout << x << " ";
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}
