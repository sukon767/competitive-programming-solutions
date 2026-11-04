#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, d, k; cin >> n >> d >> k;
    if(k == 1) {
        if(d == 1 && n == 2) cout << "YES\n1 2";
        else cout << "NO";
        return;
    }
    if(d > n-1) {cout << "NO"; return;}

    vector<pair<int, int>> adj;
    vector<int> deg(n);
    for(int i = 0; i < d; i++) {
        adj.push_back({i, i+1}); deg[i]++; deg[i+1]++;
    }

    int on = d+1;
    queue<pair<int, int>> c;
    for(int i = 1; i < d; i++) {
        // cout << i << " " << on << endl;
        for(int j = 0; j < k-2; j++) {
            if(on == n) {goto exit;}
            c.push({on, min(i, d-i)-1}); deg[on]++; deg[i]++; adj.push_back({i, on}); 
            on++;
        }

        while(c.size()) {
            if(!c.front().second) {c.pop(); continue;}
            int x = c.front().first, d = c.front().second;
            // cout << i << " " << x << " " << deg[x] << " " << on << endl;

            for(int j = 0; j < k-deg[x]; j++) {
                if(on == n) {goto exit;}
                c.push({on, d-1}); deg[on]++; adj.push_back({x, on});
                on++;
            }
            deg[x] = k;
            c.pop();
        }
            
    }

    exit:
    if(on == n) {   
        cout << "YES\n";
        for(auto p : adj) cout << p.first+1 << " " << p.second+1 << "\n";
    } else cout << "NO";    

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