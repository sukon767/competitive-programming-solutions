#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), cnt(n+1);
    for(int &i : a) {cin >> i; cnt[i]++;}   for(int &i : b) {cin >> i; cnt[i]++;}
    for(int x : cnt) if(x%2) {cout << -1; return;}
    map<int, set<pair<int, bool>>> ind;
    vector<int> ans;
    for(int i = 0; i < n; i++) {ind[a[i]].insert({i, 0}); ind[b[i]].insert({i, 1});}

    for(int i = 0; i < n; i++) {
        auto it1 = ind[a[i]].find({i, 0}), it2 = ind[a[i]].find({i, 1});
        if(it1 == ind[a[i]].end() && it2 == ind[a[i]].end()) continue;
        //then start the cycling
        int prev = a[i], cur = i;
        while(true) {
            // cout << cur << " ";
            ind[a[cur]].erase({cur, 0}), ind[b[cur]].erase({cur, 1});
            if((prev == a[i] && b[cur] == a[i]) || (prev != a[i] && (a[cur] == a[i] || b[cur] == a[i]))) {
                if(a[cur] == a[i]) ans.push_back(cur);
                // cout << a[cur] << " " << b[cur]
                break;
            }

            if(a[cur] == prev) {
                //look at b's match, and dont swap
                prev = b[cur];
                auto it = ind[b[cur]].begin();
                cur = (*it).first;
            } else {
                //look at a's match, and swap
                ans.push_back(cur);
                prev = a[cur];
                auto it = ind[a[cur]].begin();
                cur = (*it).first;
            }
        }
        // cout << endl;
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int x : ans) cout << x+1 << " ";

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