#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define sz(x) (ll)(x).size()
 
void solve() {
    ll n; cin >> n;
    vector<ll> a(n); for(ll& i : a) cin >> i;
    ll x = 0;
    for(ll i= 1; i < n; i++) {
        if(a[i] > a[x]) x = i;
    }
    // for(ll i = 0; i < n; i++) {
    //     vector<ll> ub(n, 0);
    //     for(ll j = i+1; j < i+n; j++) {
    //         ub[j%n] = max(a[(j-1)%n], ub[(j-1)%n]);
    //     }
    //     for(ll j = i-1; j > i-n; j--) {
    //         ub[(j+n)%n] = min(max(a[(j+n)%n], ub[(j+1+n)%n]), ub[(j+n)%n]);
    //     }
        
    //     ll s = accumulate(ub.begin(), ub.end(), 0LL);
    //     cout << s << " ";
    // }

    vector<vector<ll>> fall(n);
    vector<ll> forw, bak;
    ll cur = 0;
    for(ll i = n-1; i >= 0; i--) {
        while(sz(forw) && a[i] > a[forw.back()]) forw.pop_back();
        forw.push_back(i);
    }
    for(ll i = 0; i < n; i++) {
        while(sz(bak) && a[i] > a[bak.back()]) bak.pop_back();
        bak.push_back(i);
    }

    for(ll i = sz(forw)-1; forw[i] != x; i--) {
        // cout << forw[i] << endl;
        cur += abs(forw[i-1]-forw[i])*a[forw[i]];
    }
    for(ll i = sz(bak)-1; bak[i] != x; i--) {
        cur += abs(bak[i-1]-bak[i])*a[bak[i]];
    }

    // cout << endl;
    // reverse(forw.begin(), forw.end());
    // for(ll x : forw) cout << x << " ";
    // reverse(forw.begin(), forw.end());
    // cout << endl;
    
    for(ll i = n-1; i >= 0; i--) {
        while(sz(forw) && a[i] > a[forw.back()]) {
            fall[(i+1)%n].push_back(forw.back());
            forw.pop_back();
        }
        reverse(fall[(i+1)%n].begin(), fall[(i+1)%n].end());
        forw.push_back(i);
    }
    cout << cur;
    //THE UPDATE :(((((
        
    
    
    for(ll i = 1; i < n; i++) {
        //FORW GAINS SHIT
        //since we went twice around I think forw is always 2 elem
        assert(sz(forw) > 1);
        cur -= (forw[sz(forw)-2] - forw[sz(forw)-1]+n)%n*a[forw.back()];
        forw.pop_back();
        // it takes care of it when forw.back() == x i think idk why
        
        for(ll j : fall[i]) {
            //have to be careful of looping AHHHH fuck this shit
            cur += (forw.back() - j + n)%n*a[j];
            forw.push_back(j);
        }
        
        // cout << endl << i << endl;
        // reverse(forw.begin(), forw.end());
        // for(ll x : forw) cout << x << " ";
        // reverse(forw.begin(), forw.end());
        // cout << endl;

        //this part ez or is it?
        while(sz(bak) && a[i-1] > a[bak.back()]) {
            assert(sz(bak) > 1);
            cur -= (bak[sz(bak)-1]-bak[sz(bak)-2]+n)%n*a[bak.back()];
            bak.pop_back();
        }

        assert(sz(bak) > 0);
        cur += (i-1 - bak.back() + n)%n*a[i-1];
        bak.push_back(i-1);


        cout << " " << cur;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    //ll t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}
 
/* benq's 5 commandments
 * ll overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
 
 /* new testament
 * nick belov always reads the entire problem statement.
 */