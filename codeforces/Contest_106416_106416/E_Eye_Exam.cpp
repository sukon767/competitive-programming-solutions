#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int N; cin >> N;
    int l = INT_MIN, r = INT_MAX;
    int l1 = -1;

    bool done = false;

    vector<pair<pair<int, int>, char>> q;
    for(int i = 0; i < N; i++) {
        int a, b; char c; cin >> a >> b >> c;
        q.push_back({{a, b}, c});
    }
    
    for(int i = 0; i < N; i++) {
        int a = q[i].first.first, b = q[i].first.second;
        char c = q[i].second;
       
        if(c == 'A') {
            if(a%2 == b%2) r = min(r, (a+b)/2 -1);
            else r = min(r, (a+b)/2);
        }
        else if(c == 'B') {
            l = max(l, (a+b)/2 + 1);
        }
        else {
            if(a%2 != b%2) {cout << "*"; return;}
            int m = (a+b)/2;
            if(l1 != -1 && l1 != m) {
                cout << "*"; return;
            }
            l1 = m;
        }
    }

    if(l1 == -1) {
        if(l <= r) cout << l << " " << r;
        else cout << "*";
    } else {
        if(l <= l1 && l1 <= r) cout << l1 << " " << l1;
        else cout << "*";
    }
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