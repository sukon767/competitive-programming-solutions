#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        if(n%7==0) {
            cout << n << "\n";
            continue;
        }
        n /= 10;
        for(int i = 0; i < 10; i++) {
            if((10*n+i)%7==0) {
                cout << 10*n+i << "\n";
                break;
            }
        }
    }
}