#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define sz(x) (int)(x).size()
template <typename T> struct BIT {
  private:
    int size;
    vector<T> bit;
    vector<T> arr;
  public:
    BIT(int size) : size(size), bit(size + 1), arr(size) {}
    /** Sets the value at index ind to val. */
    void set(int ind, T val) { add(ind, val - arr[ind]); }
    /** Adds val to the element at index ind. */
    void add(int ind, T val) {
      arr[ind] = (arr[ind] + val);
      ind++;
      for (; ind <= size; ind += ind & -ind) { bit[ind] = (bit[ind]+val); }
    }
    /** @return The sum of all values in [0, ind]. */
    T pref_sum(int ind) {
      ind++;
      T total = 0;
      for (; ind > 0; ind -= ind & -ind) { total = (total+bit[ind]); }
      return total;
    }
    /** The first index where prefix sum >= target */
    T findKth(int target) {
        int idx = 0;
        T current_sum = 0;
        // Start from the largest power of 2 less than or equal to N
        for (int i = 1 << (int)log2(size); i > 0; i >>= 1) {
            int next_idx = idx + i;
            if (next_idx <= size && current_sum + bit[next_idx] < target) {
                idx = next_idx;
                current_sum += bit[next_idx];
            }
        }
        return idx+1;
        //MAY HAVE TO REMOVE THE +1 IF CONVERTING 0-INDEX TO 1-INDEX, NOT SURE. BE AWARE
    }
};
void solve() {
    int n, q; cin >> n >> q;
    vector<int> x(n);
    for(int& i : x) cin >> i;
    vector<int> rt(n);
    map<int, int> mp;
    BIT<int> fen(n);
    for(int i = n-1; i >= 0; i--) {
        if(mp[x[i]]) {
            rt[i] = mp[x[i]]-1;
            fen.add(rt[i], -1);
            fen.add(i, 1);
        } else {
            rt[i] = -1;
            fen.add(i, 1);
        }
        mp[x[i]] = i+1;
    }
    // cout << "asdf" << endl;
    vector<pair<pair<int, int>, int>> que(q);
    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        que[i] = {{--l, --r}, i};
    }
    // cout << "asdf" << endl;
    vector<int> ans(q);
    sort(que.begin(), que.end());
    int on = 0;
    for(int i = 0; i < q; i++) {
        // cout << que[i].first.first << " " << que[i].first.second << endl;
        while(on < que[i].first.first) {
            fen.add(on, -1);
            if(rt[on] != -1) fen.add(rt[on], 1);
            on++;
        }
        ans[que[i].second] = fen.pref_sum(que[i].first.second);
        if(que[i].first.first) ans[que[i].second] -= fen.pref_sum(que[i].first.first-1);
    }
    for(int x : ans) cout << x << "\n";
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
 /* new testament
 * nick belov always reads the entire problem statement.
 */
