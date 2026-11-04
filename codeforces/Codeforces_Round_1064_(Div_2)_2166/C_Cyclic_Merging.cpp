#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

struct VecCmp {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        return a > b;          // lexicographically compare (a > b means a is "worse")
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int mm = 0;

    set<int> ab;
    for(int i = 0; i < n; i++) {int u; cin >> u; ab.insert(i); a[i] = u;}
    for(int i = 0; i < n; i++) mm = max(mm, a[i]);


    set<vector<int>> th;
    for(int i = 0; i < n-1; i++) th.insert({max(a[i], a[i+1]), i, i+1}); 
    th.insert({max(a[n-1], a[0]), n-1, 0});
    ll ans = 0;
    while(th.size() > 1) {
        auto top = *th.begin();
        th.erase(th.begin());
        int u = top[1], v = top[2];
        auto itu = ab.find(u), itv = ab.find(v);


        if(itu == ab.end() || itv == ab.end()) continue;

                // cout << top[0] << " " << top[1] << " " << top[2] << endl;


        ans += top[0];

        if(a[u] >= a[v]) {
            auto cc = itv; ++cc;
            if(cc == ab.end()) cc = ab.begin();
            int ccn = *cc;
            // cout << ccn << endl;
            th.erase({max(a[v], a[ccn]), v, ccn});
            th.insert({max(a[u], a[ccn]), u, ccn});
            ab.erase(v);
        } else {
            auto cc = itu;
            if(cc == ab.begin()) cc = --ab.end();
            else --cc;
            int ccn = *cc;
            // cout << ccn << endl;
            th.erase({max(a[ccn], a[u]), ccn, u});
            th.insert({max(a[ccn], a[v]), ccn, v});
            ab.erase(u);
        }
    }
    cout << ans;
    // auto what = *th.begin();
    // cout << what[0] << " " << what[1] << " " << what[2] << endl;

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