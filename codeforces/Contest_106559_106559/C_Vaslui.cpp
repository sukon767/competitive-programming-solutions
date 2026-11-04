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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + 2*(s[i-1]-'0')-1;
    }

    int ans = 0;
    int mx = 0;
    int rn = 0;
    vector<int> zo;
    for(int i = 0; i < k-1; i++) if(s[i] == '0') zo.push_back(i);
    
    for(int i = k; i <= n; i++) {
        if(i-k) rn += 2*(s[i-k-1]-'0')-1;
        mx = max(mx, rn);
        if(s[i-1] == '0') zo.push_back(i-1);
        while(2*ans + pre[i] - mx < 0) {
            assert(sz(zo));
            s[zo.back()] = '1'; zo.pop_back();
            ans++;
        }
    }
    cout << ans;
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