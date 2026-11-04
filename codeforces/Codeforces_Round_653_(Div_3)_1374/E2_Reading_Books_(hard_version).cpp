#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

template <class T> class BIT {
  private:
    int size;
    vector<pair<T, T>> bit;

  public:
    BIT(int size) : size(size), bit(size + 1) {}

    /** Adds val to the element at index ind. */
    void add(int ind, T val) {
        ll og = ind;
      ind++;
      for (; ind <= size; ind += ind & -ind) { bit[ind] = {bit[ind].first+val, bit[ind].second + val*og};}
    }

    T findKth(int target) {
        int idx = 0;
        T current_sum = 0;
        T ret = 0;
        // Start from the largest power of 2 less than or equal to N
        for (int i = 1 << (int)log2(size); i > 0; i >>= 1) {
            int next_idx = idx + i;
            if (next_idx <= size && current_sum + bit[next_idx].first < target) {
                idx = next_idx;
                current_sum += bit[next_idx].first;
                ret += bit[next_idx].second;
            }
        }
        return ret + (target-current_sum)*(idx); // The first index where prefix sum >= target
    }

};

void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<vector<pair<ll, int>>> pre(4);
    BIT<ll> bit(1e4+1);
    int segsize = 0;

    for(int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        pre[3-(2*y+z)].push_back({x, i+1});
        if(!y && !z) {
            bit.add(x, 1); segsize++;
        }
    }

    for(int j = 0; j < 4; j++) {
        sort(pre[j].begin(), pre[j].end());
    }

    pair<ll, int> best = {LLONG_MAX, -1}, out = {0, 0};
    int start = max(0, k-(int)min(pre[1].size(), pre[2].size()));
    if(start > pre[0].size()) {cout << -1; return;}

    //add bare minimum 11s
    for(int i = 0; i < start; i++) {
        out.first += pre[0][i].first;
        out.second++;
    }

    //add matching 10s and 01s complete k
    for(int j = 1; j <= 2; j++) {
        for(int i = 0; i < k-start; i++) {
            out.first += pre[j][i].first;
            out.second++;
        }
    }

    //dump rest into bit
    for(int j = 1; j <= 2; j++) {
        for(int i = k-start; i < pre[j].size(); i++) {
            bit.add(pre[j][i].first, 1);
            segsize++;
        }
    }

    for(int i = start; i <= pre[0].size(); i++) {
        if(segsize >= m-out.second && out.second <= m) {
            ll aug = bit.findKth(m-out.second);
            if(out.first + aug < best.first) {
                best = {out.first + aug, i};
            }
        }
        
        if(i < pre[0].size()) {out.first += pre[0][i].first; out.second++;}
        if(0 <= k-i-1) {
            for(int j = 1; j <= 2; j++) {
                if(k-i-1 < pre[j].size()) {
                    out.first -= pre[j][k-i-1].first;
                    out.second--;
                    bit.add(pre[j][k-i-1].first, 1); segsize++;
                }
            }
        }
    }

    if(best.second == -1) {
        cout << -1;
    } else {
        //this means take < ind.
        cout << best.first << "\n";
        for(int i = 0; i < best.second; i++) cout << pre[0][i].second << " ";
        for(int i = 0; i < k-best.second; i++) cout << pre[1][i].second << " " << pre[2][i].second << " ";
        int cnt = best.second + max(0, k-best.second)*2;

        set<pair<ll, int>> recover;
        for(int j = 1; j <= 2; j++) {
            for(int i = max(0, k-best.second); i < pre[j].size(); i++) recover.insert(pre[j][i]);
        }
        for(int i = 0; i < pre[3].size(); i++) recover.insert(pre[3][i]);

        auto it = recover.begin();
        while(cnt < m) {
            cout << it->second << " ";
            it = next(it);
            cnt++;
        }
    }
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

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */