#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int N; cin >> N;
    vector<ll> a(N);
    vector<ll> og(N), og2(N), ex(N), ex2(N);
    for(ll &i : a) cin >> i;
 
    //forwards, backwards
    for(int b = 0; b < 2; b++) {
        set<int> near;
        vector<int> b2(N, -1);
        vector<pair<int, int>> ty;
        for(int i = 0; i < N; i++) ty.push_back({a[i], i});
        sort(ty.begin(), ty.end());
        for(auto &p : ty) {
            auto it = near.lower_bound(p.second);
            if(it != near.begin()) {it = prev(it);}
            if(it != near.begin()) {it = prev(it); b2[p.second] = *it;}
            near.insert(p.second);
        }
 
        ll s = 0;
        vector<int> stk;
        for(int i = 0; i < N; i++) {
            while(stk.size() && a[stk.back()] > a[i]) {
                int t = stk.back();
                stk.pop_back();
                s -= a[t]*(t+1);
                if(stk.size()) s += a[t]*(stk.back()+1);
            }
 
            if(stk.size()) ex[i] = max(ex[i], ex[stk.back()]);

            s += a[i]*(i+1);
            if(stk.size()) s -= a[i]*(stk.back()+1);
            og[i] += s;

            ll offset = 0;
            if(b2[i] != -1) {
                offset = og[b2[i]] + a[i]*(i-b2[i]) - og[i];
            } else if(stk.size()) {
                offset = (a[i] - a[stk.back()])*(stk.back()+1);
            }
 
            ex[i] = max(ex[i], offset);
 
            stk.push_back(i);
        }
 
        reverse(a.begin(), a.end());
        reverse(og.begin(), og.end());
        reverse(og2.begin(), og2.end());
        reverse(ex.begin(), ex.end());
        reverse(ex2.begin(), ex2.end());
        swap(ex, ex2);
        swap(og, og2);
    }

    // for(int i =0 ; i < N; i++) {
    //     cout << i << " " << og[i] << " " << ex[i] << " " << og2[i] << " " << ex2[i] << endl;
    // }
 
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        ans = max(ans, og[i] + og2[i] + max(ex[i], ex2[i]) - a[i]);
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
