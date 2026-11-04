#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
vector<ll> pre;

void solve() {
    int n; cin >> n;
    
    cout << pre[n];
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 1e6;
    vector<int> sieve(N+1);
    vector<vector<int>> fac(N+1);
    for(int i = 2; i <= N; i++) if(!sieve[i]) {
        for(int j = i; j <= N; j+=i) {
            sieve[j] = true;
            fac[j].push_back(i);
        }
    }

    
    ll MOD = 1e9+7;
    pre = vector<ll>(N);

    for(int i = 2; i <= N; i++) {
        for(int p : fac[i]) {
            int x = (p-i/p%p)%p;
            if(x == p-1) pre[i] += p-1;
            else pre[i]--;
        }
    }

    for(int i = 4; i <= N; i+=8) pre[i] = (pre[i] + 2)%MOD;
    for(int i = 8; i <= N; i+=8) pre[i] = (pre[i] - 2+MOD)%MOD;

    for(int i = 1; i <= N; i++) pre[i] = (pre[i] + pre[i-1])%MOD;

    for(int i = 1; i <= N; i++) pre[i] = (pre[i] + pre[i-1])%MOD;


    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}