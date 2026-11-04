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
    int n; cin >> n;
    vector<string> small = {"0", "1", "11", "101", "0101"};
    if(n < sz(small)) {
        cout << small[n];
    } else {
        n++;
        string s;
        for(int i = 0; i < n; i++) s += '0';
        switch (n%6) {
            case 0:
                s[n/3] = s[n/3 + n/3] = '1';
                break;
            case 1:
                s[n/3] = s[n/3 + n/3] = '1';
                break;
            case 2:
                s[n/3 + 1] = s[n/3 + 1 + n/3] = '1';
                break;
            case 3:
                s[n/3] = s[n/3 + n/3 - 1] = s.back() = '1';
                break;
            case 4:
                s[n/3] = s[n/3 + n/3 + 1] = '1';
                break;
            default:
                s[n/3 + 1] = s[n/3 + 1 + n/3 + 1] = '1';
                break;
        }
        cout << s.substr(1);
    }

}

//king of the sun o_O
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */