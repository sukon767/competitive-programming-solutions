#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> pts(k); for(auto &p : pts) cin >> p.f >> p.s;

    array<vector<pair<int, int>>, 4> rot;
    //0
    rot[0] = pts;
    //1
    for(auto &p : pts) rot[1].push_back({m-p.s+1, p.f});
    //2
    for(auto &p : pts) rot[2].push_back({n-p.f+1, m-p.s+1});
    //3
    for(auto &p : pts) rot[3].push_back({p.s, n-p.f+1});

    int lo = 0, hi = 1e9;
    while(lo < hi) {
        int mid = (lo+hi)>>1;
        auto check = [](vector<pair<int, int>> &pts, int n, int m, int s) {
            vector<int> att; for(auto &[x, y] : pts) att.push_back(x); att.push_back(n+s+1);
            sort(all(att)); att.erase(unique(all(att)), att.end()); reverse(all(att));
            for(auto &x : att) {
                if(x <= s+1) continue;
                vector<int> v; v.push_back(0-s); v.push_back(m+1+s);
                for(auto [x1, y1] : pts) {
                    if(1 <= x-x1 && x-x1 <= 2*s+1) {
                        v.push_back(y1);
                    }
                }
                sort(all(v));
                for(int i = 0; i+1 < sz(v); i++) {
                    if(v[i+1]-v[i] > 2*s+1) {
                        return x-(s+1);
                    }
                }
            }
            return -1;
        };

        array<int, 4> bd;
        for(int i = 0; i < 4; i++) {
            int res = check(rot[i], n, m, mid);
            if(res == -1) {bd[i] = -1; break;}
            // cout << res << endl;
            
            if(i == 1 || i == 2) res = n+1-res;
            bd[i] = res;
            // cout << res << endl;
            swap(n, m);
        }

        // cout << ((bd[0]-bd[2]+1 <= 2*mid+1 && bd[3]-bd[1]+1 <= 2*mid+1)) << endl;
        //max x, min y, min x, max y.
        if(bd[0] == -1 || (bd[0]-bd[2]+1 <= 2*mid+1 && bd[3]-bd[1]+1 <= 2*mid+1)) hi = mid;
        else lo = mid+1;
    }

    cout << lo;
}

//king of the sun o_O
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */