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
    vector<int> a(n); for(int& i : a) cin >> i;

    auto check = [&](vector<int>&a) {
        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[a[i]].push_back(i);
        vector<int> pre(n);
        set<int> cur;
        for(auto on = mp.rbegin(); on != mp.rend(); on++) {
            auto &[x, v] = *on;
            for(int i = 0; i+1 < sz(v); i++) {
                auto it = cur.upper_bound(v[i]);
                if(it==cur.end() || *it > v[i+1]) {
                    //good interval
                    pre[v[i]]++;
                    if(v[i+1]+1<n) pre[v[i+1]+1]--;
                }
            }
            for(int i : v) cur.insert(i);
        }
        partial_sum(all(pre), pre.begin());
        for(int i = 0; i < n; i++) {
            if(pre[i] == 0) return 0;
        }
        return 1;
    };
    //0
    if(check(a)) {cout << 0; return;}
    int pos = max_element(all(a))-a.begin();
    
    auto att = [&](int i, int v) {
        int z = a[i];
        a[i] = v;
        bool ans = check(a);
        a[i] = z;
        return ans;
    };

    if(att(0, a[pos])) {cout << "1\n" << 1 << " " << a[pos]; return;}
    if(att(n-1, a[pos])) {cout << "1\n" << n << " " << a[pos]; return;}
    if(att(pos, 1)) {cout << "1\n" << pos+1 << " " << 1; return;}

    cout << "2\n" << "1 1000000000\n" << n << " 1000000000";
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