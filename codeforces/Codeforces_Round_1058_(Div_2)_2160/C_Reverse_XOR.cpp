#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;

    while((n > 1) && (!(n%2)))   {n/=2;}

    
    int maxb = 0;

    
    for(int bit = 29; bit >= 0; bit--) {\
        if(((1<<bit) & n) == (1<<bit)) {
            maxb = bit; break;
        }
    }

    // cout << maxb << "\n";
    

    for(int i = 0; i <= maxb; i++) {
        if( !((((1 << i)&n)&&((1 << (maxb-i))&n)) || ((!((1 << i)&n))&&(!((1 << (maxb-i))&n)))) )
            {cout << "NO"; return;}
    }

    if(!(maxb % 2)) {
        if( ((1<<(maxb/2)) & n) == (1<<(maxb/2)) )
            {cout << "NO";  return;}
    }

    cout << "YES";
}

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}