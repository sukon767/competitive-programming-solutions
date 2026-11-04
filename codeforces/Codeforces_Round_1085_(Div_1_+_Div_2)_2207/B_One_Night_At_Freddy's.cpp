#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, m, l; cin >> n >> m >> l;
    vector<int> a(n); for(int &i : a) cin >> i;

    multiset<int> pq;
    int le = 0;
    int cnt = n;
    for(int i = 1; i <= l; i++) {
        
        if(pq.size() < min(cnt+1, m)) pq.insert(1);
        else {auto it = pq.begin(); int adder = *(it) + 1; pq.erase(it); pq.insert(adder);}

        if(le < n && a[le] == i) {
            if(pq.size()) pq.erase(--pq.end());
            le++;
            cnt--;
        }
        // cout << i << endl;
        // for(int x : pq) cout << x << " ";
        // cout << endl;
    }

    if(pq.size()) cout << *pq.begin();
    else cout << 0;
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