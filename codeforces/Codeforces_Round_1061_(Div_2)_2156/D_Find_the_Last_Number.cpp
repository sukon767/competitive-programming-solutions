#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    set<int> still;
    for(int i = 1; i <= n; i++) still.insert(i);

    set<int> inds;  for(int i = 0; i < n-1; i++) inds.insert(i);


    int ans = 0;
    int bit = 0;
    while(inds.size()) {

        int ones = 0;
        for(int x : still)
            if(x%2) ones++;

        vector<bool> poop(n);
        for(int x : inds) {
            cout << "? " << x+1 << " " << (1<<bit) << endl << flush;
            int c; cin >> c;
            if(c) {poop[x] = true; ones--;}
        }

        if(ones) {
            set<int> s1, s2;
            for(int x : still) {
                if(!(x%2)) {;}
                else {s2.insert(x/2);}
            }

            still = s2;

            for(int x : inds) {
                if(!poop[x]) {;}
                else s1.insert(x);
            }

            inds = s1;

            ans |= (1<<bit);

        } else {
            set<int> s1, s2;
            for(int x : still) {
                if(x%2) {;}
                else {s2.insert(x/2);}
            }
            still = s2;

            for(int x : inds) {
                if(poop[x]) {;}
                else s1.insert(x);
            }

            inds = s1;

        }

        bit++;
    }
    if(*still.begin()) ans |= (1<<bit);

    cout << "! " << ans << endl << flush;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        // if(i)   cout << "\n";
        solve();
    }
}