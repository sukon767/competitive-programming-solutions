#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

void solve() {
    int n; cin >> n;
    vector<int> p(n), s(n);
    for(int& i : p) {cin >> i; i--;}
    for(int i = 0; i < n; i++) {int x; cin >> x; s[--x] = i;}
    for(int& i : p) i = s[i];
    int k = 0;
    for(int i = 0; i < n; i++) k += abs(i - p[i]);
    int l = k;
    vector<pair<int, int>> ans;
    while(l) {
        int on = -1;
        bool ok = 0;
        for(int i = n-1; i >= 0; i--) {
            if(!ok) {
                if(p[i] != i) {
                    ok=1;
                    on = i;
                }
            } else if(p[i] == on) {
                on = i; break;
            }
        }

        int on2 = -1;
        for(int i = on+1; i < n; i++) {
            if(p[i] <= on) {on2 = i; break;}
        }
        swap(p[on], p[on2]); l -= 2*(on2-on); ans.emplace_back(on, on2);
    }

    cout << (k>>1) << "\n" << sz(ans) << "\n";
    for(auto& p : ans) cout << p.first+1 << " " << p.second+1 << "\n";
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