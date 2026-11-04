#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<pair<int, int>>  qs(q);
    for(int i = 0; i < q; i++) {
        cin >> qs[i].first >> qs[i].second;
        qs[i].first--;  qs[i].second--;
    }


    vector<int> logp(n), nonp(n), p2p1(n);

    logp[0] = log2(a[0]);
    
    int k = a[0];
    while(k>1) {
        if(k%2) {nonp[0]++; break;}
        k/=2;
    }

    k = a[0];
    bool temp = true;
    if(k%2) {
        k/=2;
        while(k>1) {
            if(k%2) {temp = false; break;}
            k/=2;
        }
    } else  temp = false;

    if(temp)    p2p1[0]++;

    for(int i = 1; i < n; i++)  {
        logp[i] = logp[i-1] + log2(a[i]);
        
        nonp[i] = nonp[i-1];

        int k = a[i];
        while(k>1) {
            if(k%2) {nonp[i]++; break;}
            k/=2;
        }
        
    }
    
    for(int i = 1; i < n; i++) {
        p2p1[i] = p2p1[i-1];

        int k = a[i];
        bool adder = true;

        if(k%2) {
            k/=2;
            while(k>1) {
                if(k%2) {adder = false; break;}
                k/=2;
            }
        } else  adder = false;
        if(adder)   {p2p1[i]++;
            // cout << p2p1[i] << " " << i << "\n";
        }

        
    }
    
    for(int i = 0; i < q; i++) {
        if(i)   cout << "\n";

        int l = qs[i].first; int r = qs[i].second;

        int ans = logp[r] + nonp[r];

        if(l)   ans -=  logp[l-1] + nonp[l-1];

        // cout << logp[r] << " " << nonp[r] << "\n";

        // if(l)   cout << logp[l-1] << " " << nonp[l-1] << "\n";

        int fin = p2p1[r];  if(l)   fin -= p2p1[l-1];

        // cout << fin << "asdf\n" << "\n";

        ans += fin/2 - fin;

        cout << ans;
    }

    // for(int i = 0; i < n; i++) {
    //     cout << "\n";
    //     bitset<10>  x(a[i]);
    //     cout << x;
    // }

    

    return 0;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}