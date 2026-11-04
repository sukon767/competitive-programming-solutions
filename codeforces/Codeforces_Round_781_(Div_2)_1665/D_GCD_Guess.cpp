#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int a = 0;
    //(x+a + 2^k, x+a+2^k+2^{k+1}) 
    //2^k then dont add 2^k. otherwise add it.

    for(int bit = 0; bit < 30; bit++) {
        int y;
        if(a) {
            cout << "? " << a << " " << (a+(1<<(bit+1))) << endl;
            cin >> y;
            if(y == (1<<bit)) a += (1<<bit);
        } else {
            cout << "? " << (a+(1<<bit)) << " " << (a+(1<<bit)+(1<<(bit+1))) << endl;
            cin >> y;
            if(y > (1<<bit)) a += (1<<bit);
        }
        
    }
    cout << "! " << (1<<30)-a << endl;
    //4
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}