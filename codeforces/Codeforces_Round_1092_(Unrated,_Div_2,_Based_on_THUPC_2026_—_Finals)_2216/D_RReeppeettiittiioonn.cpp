#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define f first
#define s second

vector<vector<ll>> base;

bool tidy(ll n, ll b, ll p) {
    vector<ll> temp;
    while(n) {
        temp.push_back(n%b);
        n /= b;
    }

    if(temp.size()%p) return false;
    for(int i = 0; i < temp.size()/p; i++) {
        for(int j = 1; j < p; j++) {
            if(temp[p*i+j] != temp[p*i+j-1]) return false;
        }
    }

    return true;
}

void solve() {
    ll n; cin >> n;
    vector<ll> fac;
    for(ll i = 1; i*i <= n; i++) {
        if(!(n%i)) {
            if(i > 2) fac.push_back(i);
            if(n/i != i && n/i > 2) fac.push_back(n/i);
        }
    }

    ll ans = 0;
    //try b+1 = d
    for(ll d : fac) {
        // cout << d << endl;
        ll b = d-1;
        //conv
        if(tidy(n, b, 2)) {ans++;
            //  cout << n << " " << b << endl;
            }
    }

    for(ll i = 2; i < base.size(); i++)
        for(ll j = 2; j < base[i].size(); j++) {
            if(base[i][j] > n) break;
            // if(j == 10) cout << i << " " << j << " " << base[i][j] << endl;
            if(!(n%base[i][j])) {
                if(tidy(n, j, i)) ans++;
            }
        }

    cout << ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;

    ll maxN = 1e12;
    base.push_back({}); base.push_back({}); base.push_back({});
    for(int i = 3; i < 67; i++) {
        // cout << i << endl;
        if(ll(pow(2, i))-1 > maxN) break;

        base.push_back({});
        base[i].push_back(0LL); base[i].push_back(0LL);
        ll j = 2;
        while((i == 3 && j*j + j + 1 <= maxN) || (i > 3 && base[i-1][j]+(ll)pow(j, i-1) <= maxN)) {
            // cout << j << endl;
            if(i == 3) base[i].push_back(j*j + j + 1);
            else base[i].push_back(base[i-1][j]+(ll)pow(j, i-1));
            j++;
        }
    }

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