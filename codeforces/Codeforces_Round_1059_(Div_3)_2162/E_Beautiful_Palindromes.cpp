#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, k; cin >> n >> k;
    vector<bool> seen(n);
    vector<int> a(n); for(int &i : a)  {cin >> i;  i--; seen[i] = true;}

    if(n == 1) {
        for(int i = 0; i < k; i++) {
            if(i)   cout << " ";
            cout << 1;
        }
        return;
    }

    if(n == 2) {
        for(int i = 0; i < k; i++) {
            if(i)   cout << " ";
            cout << ((1 + i + a[n-1])%2)+1;
        }
        return;
    }

    int sig = -1;
    for(int i = 0; i < n; i++)  if(!seen[i]) {sig = i; break;}

    if(sig != -1) {
        vector<int> cycle;
        int b = 0;
        while(b == sig || b == a[n-1])    b++;
        cycle.push_back(sig);   cycle.push_back(b); cycle.push_back(a[n-1]);
        for(int i = 0; i < k; i++) {
            if(i)   cout << " ";
            cout << cycle[i%3]+1;
        }
    } else {
        for(int i = 0; i < k; i++) {
            if(i)   cout << " ";
            cout << a[i]+1;
        }
    }


    
        


    
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