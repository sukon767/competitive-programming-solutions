#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

const int n = 1e6;
//sukon always reads the entire problem statement.
void solve() {
    ll N; cin >> N;
    ll Nog = N;
    vector<ll> pps;
    for(ll i = 2; i <= n; i++) {
        ll pp = 1;
        while(N%i==0) {
            pp *= i; N/=i;
        }
        if(pp>1) pps.push_back(pp);
        if(N==1) break;
    }
    if(N>1) pps.push_back(N);
    cout << sz(pps)+1 << "\n";
    for(ll x : pps) cout << Nog/x << " ";
    cout << Nog;
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