#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<ll>  a(n);   
    for(int i = 0; i < n; i++)  cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll>  w(k);
    for(int i = 0; i < k; i++)  cin >> w[i];

    int l = 0; int r = n-1;
    sort(w.begin(), w.end());
    ll sum = 0;

    for(int i = 0; i < k; i++) {
        if(w[i]==1) {sum+=2*a[r]; r--;}
        else    {
            break;
        }
    }

    for(int i = k-1; i >= 0 && w[i] != 1; i--) {
        sum += a[r] + a[l]; r--; l+=w[i]-1;
    }

    cout << sum;
        

    return 0;
}

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}