#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define sz(x) (int)(x).size()

template <typename T>
struct BIT {
    int n;
    vector<T> tree;
    
    BIT(int n) : n(n), tree(n + 1, 0) {}
    
    void add(int i, T val) {
        for (i++; i <= n; i += i & -i) {
            tree[i] = (tree[i] + val);
            // tree[i] = (tree[i] + val) % mod;
        }
    }
    
    T query(int i) {
        T sum = 0;
        for (i++; i > 0; i -= i & -i) {
            sum = (sum + tree[i]);
            // sum = (sum + tree[i]) % mod;
        }
        return sum;
    }
    
    T query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
        // return (query(r) - query(l - 1) + mod) % mod;
    }
    
    int lower_bound(T val) {
        if (val <= 0) return 0;
        int pos = 0;
        int pw = 1 << (31 - __builtin_clz(n));
        for (; pw > 0; pw >>= 1) {
            if (pos + pw <= n && tree[pos + pw] < val) {
                pos += pw;
                val -= tree[pos];
            }
        }
        return pos;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n); for(int& i : a) {cin >> i; i--;}
 
    vector<int> pre(n);
    pair<int, int> bd;
    pair<int, int> st, gol;

    for(int j = 0; j < 2; j++) {
        int lo = 0, hi = n-1;
        pair<int, int> arr = {0, n-1};
        while(lo < hi) {
            int m;
            if(j) m = (lo+hi)>>1;
            else m = (lo+hi+1)>>1;
     
            pair<int, int> pf;
     
            bool ok = false;
            fill(pre.begin(), pre.end(), 0);
            pair<int, int> bst = {0, -1};
     
            for(int i = 0; i < n; i++) {
                if(j) {
                    if(a[i] > m) pre[i]--;
                    else pre[i]++;
                } else {
                    if(a[i] < m) pre[i]--;
                    else pre[i]++;
                }
                
                if(i) pre[i] += pre[i-1];
                
                if(i >= k-1) {
                    if(pre[i] - bst.first >= 0) {
                        ok = true; arr = {bst.second+1, i};
                        break;
                    }                                
                    bst = min(bst, {pre[i-(k-1)], i-(k-1)});
                }
            }
     
            if(ok) {
                if(j) hi = m;
                else lo = m;
            } else {
                if(j) lo = m+1;
                else hi = m-1;
            }
        }
        bd.second = lo;
        gol = arr;
        swap(bd.first, bd.second);
        swap(st, gol);
    }

    // cout << bd.first << " " << bd.second << endl;
    // cout << st.first << " " << st.second << endl;
    // cout << gol.first << " " << gol.second << endl;

    vector<vector<int>> ans;
    int on = bd.first;
    BIT<int> bit(n);
    for(int i = st.first; i <= st.second; i++) bit.add(a[i], 1);
    while(st != gol) {
        while(on <= bd.second && bit.query(0, on-1) <= (st.second-st.first+1)/2 && bit.query(on+1, n-1) <= (st.second-st.first+1)/2) {
            ans.push_back({on+1, st.first+1, st.second+1}); on++;
        }
        if(st.second < gol.second) {bit.add(a[st.second+1], 1); st.second++;}
        else if(st.first > gol.first) {bit.add(a[st.first-1], 1); st.first--;}
        else if(st.first < gol.first) {bit.add(a[st.first], -1); st.first++;}
        else {bit.add(a[st.second], -1); st.second--;}
    }
    while(on <= bd.second) {ans.push_back({on+1, st.first+1, st.second+1}); on++;}

    cout << sz(ans) << "\n";
    for(auto&v : ans) {
        for(int &i : v) cout << i << " "; 
        cout << "\n";
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
