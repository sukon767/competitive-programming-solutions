#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {

    int n, q; cin >> n >> q;
    vector<int> o(n), z(n);
    string s;

    cin >> s;
    if(s[0] == '0') z[0]++; else o[0]++;
    for(int i = 1; i < n; i++) {
        if(s[i] == '0') z[i]++; else o[i]++;
        o[i]+=o[i-1];
        z[i]+=z[i-1];
    }

    // cout << "asdf\n";

    for(int i = 0; i < q; i++) {
        if(i)   cout << "\n";
        int l, r; cin >> l >> r; l--; r--;
        

        if(l) {

            if(s[l] == '0') {if(z[l-1])  {cout << "YES"; continue;}}
            else {
                // cout << l-1 << " " << o[l-1] << " " << s[l] << "\n";
                if(o[l-1])  {cout << "YES"; continue;}
            }
        }

        // cout << "asdf\n";
        if(r < n-1) {
            if(s[r] == '0') {
                if(z[n-1] - z[r])  {cout << "YES"; continue;}
            }
            else {
                if(o[n-1]-o[r])  {cout << "YES"; continue;}
            }
        }

        cout << "NO";
    }



}

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}