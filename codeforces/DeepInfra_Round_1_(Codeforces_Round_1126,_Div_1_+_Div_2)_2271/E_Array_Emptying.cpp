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
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>> os;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        os.push(x);
    }

    int lo = 0, hi = n;
    while(lo < hi) {
        auto cur = os;
        int mid = (lo+hi)>>1;
        int l = 0;
        int r = k+n+2*mid-1;
        while(sz(cur)) {
            auto it = cur.top();
            if(it <= r)  {
                r--;
                cur.pop();
            } else {
                if(l==mid) break;
                cur.pop();
                int y = it;
                y = (y/2) + (y%2);
                cur.push(y); cur.push(y);
                l++;
            }
        }
        
        if(sz(cur) == 0) hi = mid;
        else lo = mid+1;
    }
    cout << (n + 2*lo);
}

//king of the sun o_O
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