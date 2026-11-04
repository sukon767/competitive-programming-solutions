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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int& i : a) cin >> i;

    int lo = 0, hi = 20;
    while(lo < hi) {

        int m = (lo+hi)>>1;
        bool ok = 1;
        auto b = a;
        for(int i = 0; i < n; i+=(1<<m)) {
            sort(b.begin()+i, b.begin()+min(n, i+(1<<m)));
        }
        for(int i = 1; i < n; i++) {
            if(b[i] < b[i-1]) {
                ok = 0; break;
            }
        }

        if(ok) hi = m;
        else lo = m+1;
    }
    cout << (lo==0?0:(1<<(lo-1)));
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