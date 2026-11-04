#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<int> p(k);
    for(int &i : a) cin >> i;
    for(int &i : p) {cin >> i; i--;}

    string a2;
    vector<int> p2;
    int it = 0;
    int s = 0;
    for(int i = 0; i < n; i++) {
        if(!i || a[i] != a[i-1]) {a2 += '0'+a[i]; s++;}
        if(it < k && p[it] == i) {
            if(!p2.size() || p2.back() != s-1) p2.push_back(s-1); 
            it++;
        }
    }

    p2.push_back(s-1);

    for(int i = (int)p2.size()-1; i > 0; i--) p2[i] -= p2[i-1];
    int sum = s - 1;

    for(int i = 0; i < p2.size(); i++) {
        if(p2[i] > sum-p2[i]) {
            if(0 < i && i+1 < p2.size()) {cout << p2[i];}
            else {
                cout << p2[i] + p2[i]%2;
            }
            return;
        }
    }

    int ans = 0;
    if(p2[0] % 2) {sum--; p2[0]--; ans++;}
    ans += sum/2 + sum%2;
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