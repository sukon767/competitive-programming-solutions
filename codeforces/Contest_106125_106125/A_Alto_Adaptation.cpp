#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

/*
dp[i] = it is possible to make intervals of size >= k up to i
iterate the right endpoint
iterate the left endpoint
for all intervals of size >=k that can be made valid 
interval -> [j, i]
take any such dp[j-1] and set dp[i] = dp[j-1]
how to find interval?
iterate right endpoint, iterate left starting at i-k+1
while everyone inside can be put inside it is good
dp[0] = true
dp[i] = false
iterate all valid max intervlas starting from 
i-k+1 to 0
24 * 1000 * 1000 * log(1000)

maintain set of transpositions s.t. it lands in interval
keep expanding window while there is nonoverlap

*/

void solve() {
    int n, L, H;
    cin >> n >> L >> H;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    auto In = [&](int x) -> bool {
        if(L<=x and x<=H) return true;
        return false;
    };
    vector<pair<int,int>> feasible(n+1);
    for(int i = 1; i <= n; i++) {
        int l = -11, r = -11;
        for(int k = -10; k <= 10; k++) {
            if(In(a[i]+k*12)) {
                if(l==-11) l=k;
                r=k;
            }
        }
        feasible[i]={l,r};
    }
    auto Ok = [&](int k) -> bool {
        vector<bool> dp(n+1, false);
        dp[0]=true;
        for(int i = 1; i <= n; i++) {
            bool f = 0;
            pair<int,int> overlap = feasible[i];
            // j will be index at which it is no longer possible
            int j;
            for(j = i; j >= 1; j--) {
                auto [l,r] = feasible[j];
                if(overlap.first>r or overlap.second<l) {
                    break;
                } else {
                    overlap.first = max(overlap.first, l);
                    overlap.second = min(overlap.second, r);
                }
                if(j<=i-k+1) {
                    f|=dp[j-1];
                }
            }
            dp[i]=f;
        }
        if(dp[n]) return true;
        else return false;
    };
    int l = 1, r = n+10;
    while(r-l>1) {
        int m = (l+r)>>1;
        if(Ok(m)) {
            l=m;
        } else {
            r=m;
        }
    }
    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}