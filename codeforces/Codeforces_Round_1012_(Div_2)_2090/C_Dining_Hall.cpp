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
    int n; cin >> n;
    vector<int> ty(n); for(int &i : ty) cin >> i;

    vector<pair<int, int>> tb;
    int on = 1;
    while(sz(tb) < n) {
        for(int i = 0; i < on; i++) {
            tb.push_back({1 + 3*i, 3*on-2 - 3*i});
        }
        on++;
    }
    reverse(all(tb));
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<pair<int, int>> ans(n);
    for(int i = 0; i < n; i++) {
        if(!ty[i] || !sz(pq) || (pq.top()[0] > tb.back().f + tb.back().s)) {
            auto p = tb.back(); tb.pop_back();
            ans[i] = p;
            pq.push({p.f+p.s+1, p.f+1, p.s});
            pq.push({p.f+p.s+1, p.f, p.s+1});
            pq.push({p.f+p.s+4, p.f+1, p.s+1});
        } else {
            ans[i] = {pq.top()[1], pq.top()[2]}; pq.pop();
        }
    }

    for(auto&p : ans) cout << p.f << " " << p.s << "\n";
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