#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//1, 1, 2, vs 4
//1, 1, 0 vs 2
//1 : impossible.
//0, 0, 0, good.

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    int cnt = 0;
    vector<int> a(n); for(int &i : a) {cin >> i; cnt += (i==0);}
    if(cnt == 1) {
        cout << "NO"; return;
    }
    int on = 0;
    string s;
    for(int x : a) {
        if(x == 0) {
            s += 'A'+on;
            on = (on+1)%3;
        } else if(x == 1) {
            s += 'C';
        } else s += 'A';
    }
    cout << "YES\n" << s;
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