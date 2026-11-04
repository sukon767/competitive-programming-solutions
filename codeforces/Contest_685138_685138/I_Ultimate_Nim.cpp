#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    int ind = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] > a[ind]) ind = i; 
    }

    bool same = true;
    int l = -1;

    for(int i = 1; i <= n; i++) {
        if(a[i] < a[ind]) {same = false; l = i; break;}
    }

    int x, y;

    if(!same) {
        cout << "Alice" << endl;
        if(a[ind] %2) {
            cout << ind << " " << ind << endl;
        } else {
            cout << l << " " << ind << endl;
        }

        cin >> x >> y;
        while(x > 0) {
            cout << y << " " << ind << endl;
            cin >> x >> y;
        }

    } else {
        if(a[ind]%2) {

            cout << "Alice" << endl;
            cout << 1 << " " << 1 << endl;
            cin >> x >> y;
            while(x > 0) {
                cout << y << " " << 1 << endl;
                cin >> x >> y;
            }

        } else {
            cout << "Bob" << endl;
            cin >> x >> y;
            int in = x;

            while(x > 0) {
                cout << y << " " << in << endl;
                cin >> x >> y;
            }
        }



    }

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