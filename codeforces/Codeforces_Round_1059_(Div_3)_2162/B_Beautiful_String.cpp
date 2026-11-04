#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        int n; string s; cin >> n;
        cin >> s; vector<int> a;
        for(int i = 0; i < n; i++) if(s[i] == '0') a.push_back(i+1);
        cout << a.size() << "\n";
        for(int x : a) cout << x << " ";
        cout << "\n";
    }
}