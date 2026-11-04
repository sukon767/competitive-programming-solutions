#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    map<int, int> x, y;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        x[a]++; y[a+b]++;
    }

    int xx, yy;
    for(auto p : x) if(p.second%2) {xx = p.first; break;}
    for(auto p : y) if(p.second%2) {yy = p.first-xx; break;}
    cout << xx << " " << yy;

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