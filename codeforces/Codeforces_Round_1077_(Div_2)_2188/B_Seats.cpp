#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int x = 0;
    int buf = 0;
    bool beg = true;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') buf++;
        else {
            x++;
            if(beg) x += (buf+1)/3;
            else x += buf/3;
            buf = 0;
            beg = false;
        }
    }

    if(beg) x += (buf+2)/3;
    else x += (buf+1)/3;
    cout << x;
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