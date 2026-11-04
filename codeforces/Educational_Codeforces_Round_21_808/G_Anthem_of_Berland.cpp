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
    string s, t; cin >> s >> t;
    int ns = sz(s), n = sz(t);
    vector<int> dp(n, -1); dp[0] = 0;
    vector<int> pi(n);
    vector<vector<int>> nxt(n, vector<int>(26));
    for(int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && t[i] != t[j])
            j = pi[j-1];
        if (t[i] == t[j])
            j++;
        pi[i] = j;
    }

    for(int k = 0; k < 26; k++) nxt[0][k] = t[0]=='a'+k;
    for(int l = 1; l < n; l++) {
        for(int k = 0; k < 26; k++) {
            if(t[l] == 'a'+k) nxt[l][k] = l+1;
            else nxt[l][k] = nxt[pi[l-1]][k];
        }
    }

    for(int i = 0; i < ns; i++) {
        vector<int> tmp(n, -1);
        int lb = 0, hb = 26;
        if(s[i] != '?') {lb = s[i]-'a'; hb = lb+1;}
        for(int l = 0; l < n; l++) {
            if(dp[l] == -1) continue;
            for(int k = lb; k < hb; k++) {
                int j = nxt[l][k];
                if(j==n) tmp[pi[n-1]] = max(tmp[pi[n-1]], dp[l]+1);
                else tmp[j] = max(tmp[j], dp[l]);
            }
        }
        dp = tmp;
    }
    cout << *max_element(all(dp));
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