#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//2 0 in a row its cooked
//all 0 ---- 0 +++ 0 +++ etc
//and all the runs are odd, then its 1.
//if you ever have 0++--++ its cooked for example +--+ and -++- are cooked and force 3. cnat rlly be thinking of other cases

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = '0' + s;
    n++;
    // int n = sz(s);
    vector<pair<char, int>> rn;
    for(int i = 0; i < n; i++) {
        if(i && s[i] == s[i-1] && s[i] == '0') {
            cout << -1; return;
        }
        if(!sz(rn) || rn.back().f != s[i]) rn.push_back({s[i], 1});
        else rn.back().s++;
    }

    bool q1 = true;
    for(int i = 0; i < sz(rn); i++) {
        if(i && rn[i].f != '0' && rn[i-1].f != '0') {
            q1 = false;
        }
        if(rn[i].f != '0' && rn[i].s%2==0 && i+1 < sz(rn)) {
            q1 = false;
        }
    }

    if(q1) {
        cout << 1; return;
    }

    bool q3 = false;
    for(int i = 1; i+1 < sz(rn); i++) {
        if(rn[i].s == 2 && rn[i].f == '+' && rn[i-1].f == '-' && rn[i+1].f == '-') q3 = true;
        if(rn[i].s == 2 && rn[i].f == '-' && rn[i-1].f == '+' && rn[i+1].f == '+') q3 = true;
    }
    if(q3) cout << 3;
    else cout << 2;
    
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