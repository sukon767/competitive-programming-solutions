#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(auto &v : a) for(auto &i : v) cin >> i;
        if(n%2 == 0) {
            vector<vector<int>> ans(n, vector<int>(m));
            for(int i = 0; i < n; i++) {
                for(int j = 1; j < sz(a); j++) {
                    if(a[j] == a[0]) {
                        ans[i] = ans[i+n/2] = a[0];
                        a.erase(a.begin() + j); a.erase(a.begin());
                        break;
                    }
                }
            }
            vector<int> answer;
            for(auto &v : ans) for(auto &i : v) answer.push_back(i);
            for(int i = 0; i < sz(answer)/2; i++) cout << answer[i] << " ";
        } else {
            //find middle
            auto check = [&](auto &u, auto&v) {
                return u[0] == v[m/2];
            };

            int mid = 0;
            for(int i = 0; i < n; i++) {
                int cnt = 0;
                for(int j = 0; j < n; j++) {
                    if(check(a[i], a[j]) || check(a[j], a[i])) cnt++;
                    // cout << i << " " << j << " " << check(a[i], a[j]) << endl;
                }
                if(cnt == 2) {mid = i; break;}
            }
            // assert(mid != -1);
            vector<int> ord = {mid};

            for(int i = 1; i < n; i++) {
                auto &v = a[ord.back()];
                for(int j = 0; j < n; j++) {
                    if(check(a[j], v)) {
                        ord.push_back(j); break;
                    }
                }
            }
            // cout << "asf" << endl;
            // cout << sz(ord) << endl;

            vector<int> tord(n);
            tord[0] = ord[n/2];
            for(int i = 1; i < n; i+=2) tord[i/2] = ord[i];
            // cout << "asdf" << endl;
            for(int i = 2; i < n; i+=2) tord[n/2 + i/2] = ord[i];

            // for(int x : tord) cout << x << " ";
            // cout << endl;

            vector<int> answer;
            for(int i = 0; i < n; i++) {
                for(int x : a[tord[i]]) answer.push_back(x);
            }
            for(int i = 0; i < sz(answer)/2; i++) cout << answer[i] << " ";
        }
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    // int t = 1;
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