#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    ll av; cin >> av;
    string a;

    ll t = av;
    while(t) {
        a = char((t%10) + '0') + a;
        t /= 10;
    }

    a = '0' + a;

    int n; cin >> n;
    vector<bool> d(10);

    int lb = -1, hb =-1;

    for(int i = 0; i < n; i++) {
        int x; cin >> x; d[x] = true;
        if(!i) lb = x;
        if(i == n-1) hb = x;
    }

    if(!av) {
        cout << lb; return;
    }
    
    vector<ll> dp1(sz(a)+1), dp2(sz(a)+1);
    vector<ll> p10(18); p10[0] = 1;

    for(int i = 1; i < 18; i++) p10[i] = p10[i-1]*10;
    vector<ll> ezsuf1(18), ezsuf2(18);
    ezsuf1[0] = hb;
    for(int i = 1; i < 18; i++) ezsuf1[i] = ezsuf1[i-1]*10 + hb;
    ezsuf2[0] = lb;
    for(int i = 1; i < 18; i++) ezsuf2[i] = ezsuf2[i-1]*10 + lb;

    for(int i = sz(a)-1; i >= 0; i--) {
        if(d[a[i]-'0'] && dp1[i+1] != -1) {
            dp1[i] = p10[sz(a)-1-i]*(a[i]-'0') + dp1[i+1];
        } else {
            dp1[i] = -1;
            for(int j = (a[i]-'0')-1; j >= 0; j--) {
                if(d[j]) {
                    dp1[i] = p10[sz(a)-1-i]*j + (i == sz(a)-1 ? 0 : ezsuf1[sz(a)-1-i-1]);
                    break;
                }
            }
        }
    }

    for(int i = sz(a)-1; i >= 0; i--) {
        // if(!i) cout << a[i] << " " << d[a[i]-'0'] << " " << dp2[i+1] << endl;

        if(d[a[i]-'0'] && dp2[i+1] != -1) {
            dp2[i] = p10[sz(a)-1-i]*(a[i]-'0') + dp2[i+1];
        } else {
            dp2[i] = -1;
            for(int j = (a[i]-'0')+1; j < 10; j++) {
                if(d[j]) {
                    dp2[i] = p10[sz(a)-1-i]*j + (i == sz(a)-1 ? 0 : ezsuf2[sz(a)-1-i-1]);
                    break;
                }
            }
        }
    }

    // for(ll x : dp1) cout << x << endl;

    ll ans = LLONG_MAX;

    for(ll x : dp1) {
        if(x != -1 && !(x==0 && !d[0])) ans = min(ans, abs(av-x));
    }

    for(ll x : dp2) {
        if(x != -1 && !(x==0 && !d[0])) ans = min(ans, abs(av-x));
    }
    
    for(ll x : ezsuf1) {
        if(x != -1 && !(x==0 && !d[0])) ans = min(ans, abs(av-x));
    }

    for(ll x : ezsuf2) {
        if(x != -1 && !(x==0 && !d[0])) ans = min(ans, abs(av-x));
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