#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define f first
#define s second

void solve() {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> ps;
    vector<bool> seen(2*n);
    for(int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        if(r < l) swap(l, r);
        ps.push_back({--l, --r});
        seen[l] = true, seen[r] = true;
    }

    vector<int> ns; for(int i = 0; i < 2*n; i++) if(!seen[i]) ns.push_back(i);

    for(int i = 0; i < n-k; i++) {
        ps.push_back({ns[i], ns[i+(n-k)]});
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            int c = 0;
            if(ps[i].f < ps[j].f && ps[j].f < ps[i].s) c++;
            if(ps[i].f < ps[j].s && ps[j].s < ps[i].s) c++;
            if(c == 1) ans++;
        }
    }

    cout << (ans>>1);
   


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