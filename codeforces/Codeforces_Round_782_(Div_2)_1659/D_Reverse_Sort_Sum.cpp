#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int> c(n), b;
    for(int &i : c) cin >> i;

    int it = 0; int prev = -1;

    bool done = false;

    while(b.size() < n) {
        int x;
        if(it >= b.size()) {
            x = c[it];
        }   else x = c[it] - b[it]*it + it;
        
        for(int i = prev+1; i < x; i++)   {
            b.push_back(1);
            if(b.size() == n) {done = true; break;}
            
        }

        if(done) {break;}

        b.push_back(0);

        prev = b.size()-1;
        it++;
    }

    for(int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << b[i];
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