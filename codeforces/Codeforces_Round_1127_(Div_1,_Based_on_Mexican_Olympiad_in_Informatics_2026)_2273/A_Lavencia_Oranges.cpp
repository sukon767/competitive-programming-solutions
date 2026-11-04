#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//pray
const int mx = 2000;
const int N = 2e5+1;

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    vector<int> ans;
    int lo = 0, hi = mx;
    while(lo < hi) {

        int mid = (lo+hi)>>1;
        vector<int> cnt(mid+1);
        ll sum = 0;
        for(int i = 1; i <= mid; i++) {
            cnt[i] = mid/i;
            sum += cnt[i]*i;
        }

        if(sum < n) {
            lo = mid+1; continue;
        }


        int pt = mid;
        while(sum > n) {
            while(pt >= 0 && (cnt[pt]==0 || sum-pt < n)) pt--;
            assert(pt >= 0);
            sum -= pt; cnt[pt]--;
        }

        hi = mid;
        ans = cnt;
    }
    int on = 1;
    cout << lo << "\n";
    for(int i = 1; i <= lo; i++) {
        for(int j = 0; j < ans[i]; j++) {
            for(int k = 0; k < i; k++) cout << on << " ";
            on++;
        }
    }
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