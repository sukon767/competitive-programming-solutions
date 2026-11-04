#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    vector<ll> cnt(3); cin >> cnt[0] >> cnt[1] >> cnt[2];
    vector<ll> k(3); cin >> k[0] >> k[1] >> k[2];

    ll s = (cnt[0]+cnt[1]+cnt[2])>>1;

    vector<ll> m(s); for(ll& i : m) cin >> i;
    sort(m.begin(), m.end());

    ll lo = 0, hi = 1e18;

    while(lo < hi) {
        ll mid = (lo+hi+1)>>1;

        //test m
        vector<vector<vector<int>>> see(3, vector<vector<int>>(3));
        for(int i = 0; i < s; i++) {
            for(int j = 0; j < 3; j++) {
                for(int l = j; l < 3; l++) {
                    if(m[i]*(k[j]+k[l]) >= mid) {
                        see[j][l].push_back(i);
                    }
                }
            }
        }

        bool ok = true;
        vector<ll> left = cnt;
        vector<bool> dun(s);
        for(int i = 0; i < 3; i++) {
            for(int j = i; j < 3; j++) {
                for(int kay : see[i][j]) {
                    if(!dun[kay]) {
                        left[i]--; left[j]--;
                        if(left[i]<0 || left[j]<0) {
                            left[i]++; left[j]++;
                            break;
                        }
                        dun[kay] = 1;
                    }
                }
            }
            if(left[i]) {
                ok = false;
                break;
            }
        }

        if(ok) lo = mid;
        else hi = mid-1;
    }

    cout << lo;
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