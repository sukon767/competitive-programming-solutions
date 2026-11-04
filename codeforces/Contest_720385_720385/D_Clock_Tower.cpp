#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    //1: 5:00
    //2: 5:08
    //3: 5:57  7:00 or 6: repeating number
    //4: 6:00  6:58
    //5: 7:00
    //6: 8:00
    //7: 8:05 maybe? no
    //8: 9:00
    cout << "5:00\n";
    cout << "5:08\n";
    cout << "5:57\n";
    cout << "6:00\n";
    cout << "7:00\n";
    cout << "8:00\n";
    cout << "8:05\n";
    cout << "9:00\n";
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */