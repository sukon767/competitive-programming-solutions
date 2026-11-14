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
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector<int> sr = {0}, tr = {0};
    for(int u = 0; u < 2; u++) {
        for(int i = 0; i < sz(s); i++) {
            if(s[i] == 'W') sr.push_back(0);
            else sr.back()++;
        }
        swap(sr, tr); swap(s, t);
    }

    int N = max(n, m);
    vector<int> fs(N), ft(N);
    for(int u = 0; u < 2; u++) {
        int prev = sz(s);
        for(int i = 0; i < sz(s); i++) {
            if(s[i] == 'W') prev = i;
            if(prev <= i) fs[i-prev]++;
        }
        if(prev < sz(s)) for(int i = sz(s); i-prev < N; i++) fs[i-prev]++;
        partial_sum(all(fs), fs.begin());
        swap(fs, ft); swap(s, t);
    }

    vector<int> sa, ta;
    for(int u = 0; u < 2; u++) {
        int a = 0;
        bool ok = 0;
        for(int x = 1; x <= sz(s); x++) {
            if(s[x-1] == 'W') {a = 0; ok = 1; continue;}
            a++;
            //the minimum value is (x + y - a), where y is the first W in t.
            //the maximum value is (x + y + b - a) and (x + y - 1). so y-1, y+b
            //max value of y is last W.
            //max value of y+b is obviously just the last R (if there exists a W).

            int l = INT_MAX, r = INT_MIN;
            
            //bull and shit
            if(ok) {
                if(sz(tr) > 1) {
                    l = x + (tr[0]+1) - a;
                    r = x + (sz(t) - tr.back()) - 1;
                    r = max(r, x + sz(t) - a);
                }
                l = min(l, x - a);
                r = max(r, x + tr[0] - a);
                if(l <= r) sa.push_back(r-l+1);
            } else {
                sa.push_back(1 + ft[a-1]);
            }
        }
        swap(sr, tr); swap(s, t); swap(sa, ta); swap(fs, ft);
    }
    for(int x : sa) cout << x << " ";
    cout << "\n";
    for(int x : ta) cout << x << " ";
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