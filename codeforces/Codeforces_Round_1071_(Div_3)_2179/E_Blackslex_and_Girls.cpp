#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    ll n, x, y; cin >> n >> x >> y;
    string s;
    cin >> s;
    vector<ll> p(n); for(ll &i : p) cin >> i;
    ll a = 0, b = 0;
    ll sum = x+y;
 
    char prev;
    bool mul = false;
 
    for(ll i = 0; i < n; i++) {
        if(i == 0) prev = s[i];
        else if(s[i] != prev) {mul = true;}
        sum -= p[i];
        if(s[i] == '0') {
            if(p[i]%2) {
                a++;
                b += p[i];
            } else {
                a += 2;
                b+=p[i];
            }
        } else {
            if(p[i]%2) {
                a-=p[i];
                b --;
            } else {
                a -= p[i];
                b-=2;
            }
        }
    }
 
    // cout << a << " " << b << " " << sum << " " << mul << " " << (x-y) << "\n";
    if(sum < 0) {cout << "NO"; return;}
 
    if(!sum) {
        if(((x-y-a)%2 == 0) && (a <= x-y) && (x-y <= b)) cout << "YES";
        else cout << "NO";
    } else {
        
        if(mul) {
            if((a - sum <= x-y) && (x-y <= b+sum)) cout << "YES";
            else cout << "NO"; 
        } else {
            if(prev == '0') {
                if((max(n, a-sum) <= x-y) && (x-y <= b+sum)) cout << "YES";
                else cout << "NO";
            } else {
                if((a - sum <= x-y) && (x-y <= min(-n, b+sum))) cout << "YES";
                else cout << "NO";
            }
        }
 
    }
 
    
 
 
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    ll t; cin >> t;
    //ll t = 1;
    for(ll i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}