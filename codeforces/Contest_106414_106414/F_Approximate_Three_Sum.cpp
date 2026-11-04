#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, m; cin >> n >> m;
    vector<pair<ll, int>> a(n);
    for(auto &p : a) {
        cin >> p.first;
    }
    for(int i = 0; i < n; i++) a[i].second =i+1;
    sort(a.begin(), a.end());

    if(a[0].first + a[1].first + a[2].first > 2*m) {cout <<-1; return;}

    int l = n;
    for(int i = 2; i < n; i++) {
        if(a[i].first >= a[i-1].first+m+2) {l = i; break;}
    }

    if(l < 3 || a[l-3].first+a[l-2].first+a[l-1].first < m) {
        if(l == n || a[0].first + a[1].first + a[l].first > 2*m) {
            cout << -1;
        } else {
            cout << a[0].second << " " << a[1].second << " " << a[l].second;
        }
    } else {
        //ivt 0 to l-1
        int i = 0, j = 1, k = 2;
        vector<int> ans;
        int r, s;
        ll cur;
        if(a[i].first + a[j].first + a[l-1].first >= m) {
            ans = {i, j};
            r = 2, s = l-1;
            cur = a[i].first+a[j].first;
        } else {
            k = l-1;
            if(a[i].first + a[l-2].first + a[k].first >= m) {
                ans = {i, k};
                r = 1, s = l-2;
                cur = a[i].first + a[k].first;
            } else {
                j = l-2;
                ans = {j, k};
                r = 0, s = l-3;
                cur = a[j].first + a[k].first;
            }
        }

        for(int i = r; i <= s; i++) {
            if(cur + a[i].first >= m && cur + a[i].first <= 2*m) {
                ans.push_back(i);
                break;
            }
        }

        cout << a[ans[0]].second << " " << a[ans[1]].second << " " << a[ans[2]].second;
    }
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