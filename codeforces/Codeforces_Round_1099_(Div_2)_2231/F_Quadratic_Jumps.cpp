#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define sz(x) (int)(x).size()
 
int n, q;
vector<pair<int, vector<int>>> bst;
 
int query(int a, int b) {
    int d = b-a;
    if(bst[d].first == 1) {
        return 1;
    } else if(bst[d].first == 2) {
        for(int i = 0; i < 2; i++) {
            if(1 <= a + bst[d].second[i] && a + bst[d].second[i] <= n) return 2;
        }
    }
 
    //THE case;
    //the first move
    for(int x = 1; x*x <= n; x++) {
        //into the gap
        for(int k = -1; k < 2; k+=2) {
            if(!(1 <= a + k*x*x && a + k*x*x <= n)) continue;

            int c = d - k*x*x;
            if(bst[abs(c)].first != 2) continue;
            vector<int> mv = {bst[abs(c)].second[0], bst[abs(c)].second[1]};
            if(c < 0) {
                mv[0] *= -1;
                mv[1] *= -1;
            }
            for(int i = 0; i < 2; i++) {
                if(1 <= a + k*x*x + mv[i] && a + k*x*x + mv[i] <= n) return 3;
            }
        }
    }
 
    return 4;
}
 
void solve() {
    cin >> n >> q;
    bst = vector<pair<int, vector<int>>>(n+1, {-1, {}});
    for(int i = 1; i*i <= n; i++) {
        bst[i*i] = {1, {}};
    }
 
    for(int i = 1; i*i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            for(int k = -1; k < 2; k+=2) {
                int x = i*i +k*j*j;
                if(1 <= x && x <= n) {                  
                    if(bst[x].first != -1) continue;
                    bst[x] = {2, {i*i, k*j*j}};
                }
            }
        }
    }
 
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << query(a, b) << "\n";
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