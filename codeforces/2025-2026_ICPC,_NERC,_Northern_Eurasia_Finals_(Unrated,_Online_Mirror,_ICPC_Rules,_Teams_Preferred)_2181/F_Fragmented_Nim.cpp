#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    int c = 0;
    bool d = false;
    for(int x : a) if(x > 1) d = true; else c++;
    c %= 2;
    if(d) {
        if(c)   cout << "Bob"; 
        else    cout << "Alice"; 
    } else {
        if(c)   cout << "Alice"; 
        else    cout << "Bob";
    }

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