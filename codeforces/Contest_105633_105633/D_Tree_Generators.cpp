#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    string s1, s2;
    for(int i = 0; i < 2; i++) {
        string t; cin >> t;
        for(char c : t) {
            if(c == '1') s1 += "(1)";
            else s1 += c;
        }
        swap(s1, s2);
    }

    int n = sz(s1);
    vector<int> suf1(n), suf2(n);
    for(int j = 0; j < 2; j++) {
        for(int i = n-1; i >= 0; i--) {
            if(i < n-1) suf1[i] = suf1[i+1];
            if(s1[i] == '1') suf1[i]++;
        }
        swap(suf1, suf2); swap(s1, s2);
    }

    int N = suf1[0];
    vector<pair<int, int>> cont(N-1, {INT_MAX, INT_MAX});
    vector<int> dual1(n), dual2(n);

    for(int j = 0; j < 2; j++) {
        vector<int> stk;
        for(int i = n-1; i >= 0; i--) {
            if(s1[i] == '(') {
                dual1[i] = stk.back();
                dual1[stk.back()] = i;
                stk.pop_back();
            } else if(s1[i] == ')') {
                stk.push_back(i);
            }
        }

        
        for(int i = 0; i+1 < n; i++) {
            if(s1[i] == ')' && s1[i+1] == '(') {
                int x = N-1-suf1[i];
                cont[x].f = min(cont[x].f, suf1[dual1[i]] - suf1[i]);
                cont[x].s = min(cont[x].s, suf1[i+1] - suf1[dual1[i+1]]);
            }
        }

        swap(s1, s2); swap(suf1, suf2); swap(dual1, dual2);
    }

    for(auto & p : cont) {
        if(p.f == INT_MAX) p.f = 1;
        if(p.s == INT_MAX) p.s = 1;
    }

    const ll MOD = 998244353;
    ll ans = 1;
    for(int i = 0; i < N-1; i++) ans = ans*cont[i].f%MOD*cont[i].s%MOD;
    cout << ans;
}

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

 /* new testament
 * nick belov always reads the entire problem statement.
 */