#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define sz(x) (int)(x).size()
 
const ll MOD = 1e9+7;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> ivls(n, {0, n-1, 0});
    vector<int> taken;
 
    bool poss = true;
    for(int i = 0; i < k; i++) {
        int s, r, c; cin >> s >> r >> c; --r, --c;
        if(r+c != n-(s+1)/2) poss = false;
 
        string S; if(s > 1) cin >> S;
        for(int i = 0; i < sz(S)-1-i; i++) if(S[i] == S[sz(S)-1-i]) poss = false;
        
        if(poss) {
            int pos = r;
            vector<int> arr = {r};
            for(int i = 0; i < sz(S)/2; i++) {
                if(S[i] == 'D') pos++;
                arr.push_back(pos);
            }
            for(int i = sz(arr)-1; i > 0; i--) arr[i] -= arr[i-1];
            reverse(arr.begin(), arr.end());
 
            for(int i = 0; i < sz(arr)-1; i++) {
                if(arr[i] == 1) ivls[i][1] = min(ivls[i][1], pos-1);
                else ivls[i][0] = max(ivls[i][0], pos+1);
            }
 
            taken.push_back(pos);
            ivls[s/2][0] = INT_MAX;
        }
    }
 
    if(!poss) {cout << 0; return;}
 
 
    sort(ivls.begin(), ivls.end(), [](const auto &a, const auto& b) {return a[1]-a[0] < b[1]-b[0];});
 
    for(int x : taken) {
        for(int i = 0; i < n; i++) {
            if(ivls[i][0] <= x && x <= ivls[i][1]) ivls[i][2]++;
        }
    }
 
    ll ans = 1;
    for(int i = 0; i < n; i++) {
        if(ivls[i][0] == INT_MAX) continue;
        if(ivls[i][1]-ivls[i][0]+1-ivls[i][2] <= 0) {
            cout << 0; return;
        }
        ans *= ivls[i][1]-ivls[i][0]+1-ivls[i][2];
        ans %= MOD;
        for(int j = i+1; j < n; j++) {
            if(ivls[j][0] <= ivls[i][0] && ivls[i][1] <= ivls[j][1]) ivls[j][2]++;
        }
    }
 
    cout << ans;
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