#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll n, m; cin >> n >> m;
    ll l = (1LL << (m-1)), r = (1LL << (m-1));
    ll ans = (1LL << (m-1)) -1;
    map<ll, bool> visited;

    for(ll i = 0; i < n; i++) {
        string s; cin >> s; ll b = 1;
        ll x = 0;
        for(ll j = s.size()-1; j >= 0; j--) {if(s[j] == '1') x+=b; b<<=1;}
        visited[x] = true;
        if(x <= ans) l--;
        else r--;

        while(visited[ans] || !(l == r || l == r+1)) {
            if(visited[ans]) {
                if(l >= r) ans--;
                else {ans++; if(!visited[ans]) {l++; r--;}}
            } else {
                if(l > r) {l--; r++; ans--;}
                else {ans++; if(!visited[ans]) {l++; r--;}}
            }
        }
    }

    string a;
    for(ll i = m-1; i >= 0; i--) if(ans & (1LL<<i)) a += '1'; else a += '0';
    cout << a;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}