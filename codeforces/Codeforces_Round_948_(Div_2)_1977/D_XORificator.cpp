#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

ll p1 = 1e9+7, p2 = 1e9+9, B = 7670;

pair<ll, ll> hashd(string x) {
    pair<ll, ll> ans;
    ll b1 = 1, b2 = 1;
    for(int i = 0; i < x.size(); i++) {
        if(x[i] == '1') {ans.first = (ans.first+b1)%p1, ans.second = (ans.second+b2)%p2;}
        b1 = b1*B%p1, b2 = b2*B%p2;
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) cin >> grid[i];
    map<pair<ll, ll>, int> cnt;
    map<pair<ll, ll>, pair<int, int>> typ;

    for(int j = 0; j < m; j++) {
        string x;
        for(int i = 0; i < n; i++) x += grid[i][j];
        pair<ll, ll> y = hashd(x);
        ll b1 = 1, b2 = 1;
        for(int i = 0; i < n; i++) {
            if(x[i] == '0') {
                cnt[{(y.first + b1)%p1, (y.second + b2)%p2}]++;
                typ[{(y.first + b1)%p1, (y.second + b2)%p2}] = {i, j};
            } else {
                cnt[{(y.first - b1 + p1)%p1, (y.second-b2+p2)%p2}]++;
                typ[{(y.first - b1 + p1)%p1, (y.second-b2+p2)%p2}] = {i, j};
            }
            b1 = b1*B%p1, b2 = b2*B%p2;
        }
    }

    pair<int, int> code; int c = 0;
    for(auto x : cnt) {
        if(x.second > c) {code = typ[x.first]; c = x.second;}
    }

    string ans = "";
    for(int i = 0; i < n; i++) {
        if(i == code.first) {ans += char((1 - int(grid[i][code.second] - '0')) + '0');}
        else ans += grid[i][code.second];
    }
    cout << c << "\n";
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