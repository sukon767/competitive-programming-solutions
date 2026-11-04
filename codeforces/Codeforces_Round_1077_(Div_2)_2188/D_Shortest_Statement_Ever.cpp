#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int x, y; cin >> x >> y;
    vector<vector<int>> ans;
    
    for(int i = 0; i < 2; i++) {
        int p = x;
        int q = 0;

        vector<int> cont = {p};

        for(int b = 0; b < 30; b++) {
            if(cont.back() & (1 << b)) {
                cont.push_back(cont.back() + (1 << b));
            }
        }

        // if(i) {
        //     for(int x : cont) cout << x << endl;
        // }

        //under
        for(int k : cont) {
            p = x, q = 0;
            for(int b = 29; b >= 0; b--) {
                if(q + (1 << b) > y)  continue;
                if(k & (1 << b)) continue;

                q += (1 << b);
            }
            // if(k == 11) cout << q << endl;

            if(i) ans.push_back({abs(k-x) + abs(q-y), q, k});
            else ans.push_back({abs(k-x) + abs(q-y), k, q});
        }

        //over
        for(int k : cont) {
            p = x, q = 0;
            for(int b = 29; b >= 0; b--) {
                if(k & (1 << b)) q += (1 << b);
            }
            
            for(int b = 29; b >= 0; b--) {
                // if(k == 11)
                // cout << q << " " << ((1 << 30) - 1 - y) << endl;
                if(q + (1 << b) > ((1 << 30) - 1 - y))  continue;
                if(k & (1 << b)) continue;

                q += (1 << b);
                // if(k == 11) cout << b << endl;
            }

            q = (1 << 30) - 1 - q;
            // if(k == 11) cout << q << " " <<  k << " " << y << endl;
            
            if(i) ans.push_back({abs(k-x) + abs(q-y), q, k});
            else ans.push_back({abs(k-x) + abs(q-y), k, q});
        }

        swap(x, y);   
    }

    // for(int i = 0; i < ans.size(); i++) {
    //     cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;
    // }

    

    sort(ans.begin(), ans.end());
    
    cout << ans[0][1] << ' ' << ans[0][2];
    
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