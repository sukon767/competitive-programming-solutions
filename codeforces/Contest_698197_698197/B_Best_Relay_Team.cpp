#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<pair<pair<ld, ld>, string>> run(n);
    for(int i = 0; i < n; i++) {
        cin >> run[i].second >> run[i].first.second >> run[i].first.first;
    }

    for(int i = 0; i < n; i++) {
        sort(run.begin(), run.end());
    }

    ld base = 0;
    for(int i = 0; i < 4; i++) base += run[i].first.first;
    ld ans = INFINITY;

    vector<string> name;

    for(int i = 0; i < n; i++) {
        if(i < 4) {
            ld t = base + run[i].first.second - run[i].first.first;
            if(t < ans) {
                name.clear();
                name = {run[i].second};
                for(int j = 0; j < 4; j++) {
                    if(j==i) continue;
                    name.push_back(run[j].second);
                }
                ans = min(t, ans);
            }
        } else  {
            ld t = base + run[i].first.second - run[3].first.first;
            if(t < ans) {
                name.clear();
                name.push_back(run[i].second);
                name.push_back(run[0].second);
                name.push_back(run[1].second);
                name.push_back(run[2].second);
                ans = min(t, ans);
            }
        }
    }

    cout << setprecision(20) << ans << "\n";
    for(string s : name) cout << s << "\n";
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