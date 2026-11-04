#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

// Extended Euclidean Algorithm
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Modular inverse of a mod m (assumes gcd(a,m)=1)
ll inv(ll a, ll m) {
    ll x, y;
    exgcd(a, m, x, y);
    x %= m;
    if (x < 0) x += m;
    return x;
}

// Solve:
//   x ≡ a (mod m)
//   x ≡ b (mod n)
// Returns {x, lcm(m,n)} or {-1, -1} if no solution
pair<ll,ll> crt(ll a, ll m, ll b, ll n) {
    ll x, y;
    ll g = exgcd(m, n, x, y);

    if ((b - a) % g != 0)
        return {-1, -1};

    ll lcm = m / g * n;

    // Solve m*k ≡ (b-a) (mod n)
    ll k = ( (b - a) / g ) % (n / g);
    if (k < 0) k += (n / g);

    ll in = inv(m / g, n / g);
    k = ( (__int128)k * in ) % (n / g);

    ll res = a + (__int128)m * k;
    res %= lcm;
    if (res < 0) res += lcm;

    return {res, lcm};
}

void solve() {
    ll n, x, y, vx, vy; cin >> n >> x >> y >> vx >> vy;
    ll g = gcd(vx, vy);
    vx /= g, vy /= g;
    vector<ll> r1(3), r2(3);
    ll g1 = gcd(x, gcd(vx, n)), g2 = gcd(y, gcd(vy, n));
    r1 = {x/g1, vx/g1, n/g1}, r2 = {y/g2, vy/g2, n/g2};
    if(gcd(r1[1], r1[2]) > 1 || gcd(r2[1], r2[2]) > 1) {cout << -1; return;}

    // cout << r1[0] << " " << r1[1] << " " << r1[2] << endl;


    ll k1, k2;
    if(r1[2] == 1) k1 = 0;
    else {
        k1 = ((-r1[0])*inv(r1[1], r1[2])%r1[2]+r1[2])%r1[2];
    }

    if(r2[2] == 1) k2 = 0;
    else {
        k2 = ((-r2[0])*inv(r2[1], r2[2])%r2[2]+r2[2])%r2[2];
    }

    // cout << k1 << " " << r1[2] << " " << k2 << " " << r2[2] << endl;

    pair<ll, ll> solv = crt(k1, r1[2], k2, r2[2]);
    ll t = solv.first;
    if(t == -1) {cout << -1; return;}
    // cout << ans;
    pair<ll, ll> p1 = {x, y}, p2 = {x + t*vx, y + t*vy};
    // cout << p2.first << " " << p2.second << endl;


    ll l = n/gcd(gcd(vx, vy), n);
    vx *= l, vy *= l;
    ll sub = (p2.first-p1.first)/vx;
    p2.first -= vx*sub, p2.second -= vy*sub;
    ll ans = (p2.first/n-1 - p1.first/n) + (p2.second/n-1 - p1.second/n);
    ll s = p2.first+p2.second, d = p2.second-p2.first;
    ans += (abs(s/n)+1)/2 + (abs(d/n)+1)/2;
    if(s%(2*n) == n) ans -=2;
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