#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> e(n, -1);
    vector<int> o(n, -1);

    vector<int> window(n-1);

    for(int i = 0; i < n; i++) {
        int c1 = 0, c2 = n-1;
        if((i-c1+1) %2) c1++;
        if((c2-i+1) %2) c2--;
        if(i >= n/2-1 && i > c1) {
            //query down
            cout << "? " << c1+1 << " " << i+1 << endl;
            int v; cin >> v;
            e[i] = (i-c1+1)/v%2;
            if(i-c1+1 == 2) window[c1] = e[i];
        }
        if(i <= n/2+1 && c2 > i) {
            //query up
            cout << "? " << i+1 << " " << c2+1 << endl;
            int v; cin >> v;
            o[i] = (c2-i+1)/v%2;
            if(c2-i+1 == 2) window[i] = o[i];
        }
    }
    
    for(int i = n-3; i >= 0; i--) {
        if(e[i] != -1 && e[i+2] != -1) {
            window[i+1] = (e[i] + e[i+2])%2;
        } else break;
    }

    for(int i = 2; i < n; i++) {
        if(o[i] != -1 && o[i-2] != -1) {
            window[i-2] = (o[i] + o[i-2])%2;
        } else break;
    }

    // for(int i = 0; i < n; i++) cout << i << " " << e[i] << " " << o[i] << endl;

    //now we have all windows. finish
    string s;
    // for(int i = 0; i < n-1; i++) cout << i << " " << window[i] << endl;

    if(window[0]) s += "10";
    else s += "00";
    for(int i = 1; i < n-1; i++) {
        if(window[i] == window[i-1]) s += s[s.size()-2];
        else s += 1-(s[s.size()-2]-'0') + '0';
    }

    cout << "! " << s << endl;
    int v; cin >> v;
    if(!v) {
        for(char &c : s) c = 1-(c-'0') + '0';
        cout << "! " << s << endl;
        cin >> v;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve();
        // if(t)   cout << "\n";
    }
}