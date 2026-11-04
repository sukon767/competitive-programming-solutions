#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<bool, bool>> bound(n); vector<int> pref(n);
    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;    l--; r--;
        bound[l].first = true; bound[r].second = true;
        pref[l]++; if(r < n-1)  pref[r+1]--;
    }

    //0 check
    for(int i = 0; i < n; i++) {
        if(i)   pref[i] += pref[i-1];
        if(pref[i] == m)
            {
                for(int j = 0; j < n; j++) {
                    if(j)   cout << " ";
                    if(j == i) cout << 0;
                    else if(j < i)   cout << j+1;
                    else cout << j;
                }
                return;
            }
    }
        
    
    //1 check
    for(int i = 0; i < n-1; i++) {
        if(!(bound[i].second && bound[i+1].first)) {
            for(int j = 0; j < n; j++) {
                if(j)   cout << " ";
                if(j == i || j == i+1)
                    if(!bound[i].second)    cout << j-i;
                    else    cout << 1-(j-i);
                else if(j < i)   cout << j + 2;
                else cout << j;
            }
            return;
        }
    }

    cout << 0 << " " << 2 << " " << 1;
    for(int i = 3; i < n; i++)  cout << " " << i;
    

    
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}