#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n); for(int &i : a) cin >> i;
    vector<pair<int, int>> freq(n+1); for(int x : a) freq[x].first++;
    for(int i = 0; i <= n; i++) freq[i].second = i;
    
    sort(freq.begin(), freq.end());

    vector<int> cnt(n+1);
    for(int i = n; i >= 0; i--) {
        if(i < n) freq[i].first += freq[i+1].first;
        cnt[freq[i].second] = freq[i].first-1;
    }
    
    
    vector<int> o(n);
    
    for(int i = 0; i < n; i++) {
        o[cnt[a[i]]] = i;
        cnt[a[i]]--;
    }

    for(int i = 0; i < n; i++) {
        b[o[i]] = a[o[(i + freq.back().first)%n]];
    }

    for(int x : b) cout << x << " ";
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