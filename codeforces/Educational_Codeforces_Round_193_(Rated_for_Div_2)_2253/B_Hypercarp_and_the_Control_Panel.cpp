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
    vector<int> a(n);
    for(int &i : a) cin >> i;
    vector<pair<int, int>> rn;
    for(int i = 0; i < n; i++) {
        if(!sz(rn) || rn.back().f != a[i]) rn.push_back({a[i], 1});
        else rn.back().s++;
    }

    int bst = 0;
    int s = sz(rn);
    for(int j = 0; j < 2; j++) {
        for(int i = 0; i+1 < s; i++) {
            if(rn[i].s > 1 && (i+2 >= s || rn[i].f != rn[i+2].f)) bst = 1;
        }

        reverse(all(rn));
    }
    for(int i = 0; i+1 < s; i++) {
        if(rn[i].s > 1 && rn[i+1].s > 1) bst = 2;
    }


    cout << s+bst;
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