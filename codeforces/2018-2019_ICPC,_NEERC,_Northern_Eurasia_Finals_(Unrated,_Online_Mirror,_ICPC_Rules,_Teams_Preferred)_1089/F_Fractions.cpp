#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve() {
    ll N; cin >> N;
    ll n = N;
    ll sqrtN = sqrt(n);
    vector<bool> sieve(sqrtN+1);
    vector<ll> pps;
    for(int i = 2; i <= sqrtN; i++) {
        if(!sieve[i]) {
            ll pp = 1;
            while(n%i==0) {n/=i; pp*=i;}
            if(pp>1) pps.push_back(pp);
            for(int j = i; j <= sqrtN; j+=i) sieve[i]=1;
        }
    }
    if(n>1) pps.push_back(n);
    if(sz(pps) <= 1) {cout << "NO"; return;}

    n = N;

    ll x=0, y=0;
    ll a = pps[0];
    ll b = n/a;
    gcd(a, b, x, y);

    // cout << a << " " << b << " " << x << " " << y << endl;
    
    x = (x%b+b)%b;
    y = (y%a+a)%a;

    x = (x*(a*b-1))%b;
    y = (y*(a*b-1))%a;

    assert(a*x+b*y==a*b-1);
    cout << "YES\n";
    cout << "2\n" << x << " " << n/a << "\n" << y << " " << n/b;
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