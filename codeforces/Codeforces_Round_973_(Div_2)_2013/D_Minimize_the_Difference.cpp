#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int solve() {
    int n;
    cin >> n;
// cout << "asdf";

    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

// cout << "asdf";

    b[0] = a[0];    
    for(int i = 1; i < n; i++)
        b[i]=a[i]+b[i-1];

        // cout << "asdf";

    ll mini = 1e15;
    for(int i = 0; i < n; i++)  {b[i]/=i+1; mini = min(mini, b[i]);}

// cout << "asdf";

    c[n-1] = a[n-1];    
    for(int i = n-2; i >= 0; i--)
        c[i]=a[i]+c[i+1];

        // cout << "asdf";

    ll maxi = 0;

//  cout << maxi << " " << mini << "\n";

    for(int i = n-1; i >= 0; i--)  {c[i]= ceil((ld)c[i]/(n - i)); maxi = max(maxi, c[i]);}

    // cout << maxi << " " << mini << "\n";

    cout << maxi-mini;


    

    




    return 0;
}

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}