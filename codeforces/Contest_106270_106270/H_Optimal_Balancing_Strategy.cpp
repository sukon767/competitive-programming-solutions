#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

vector<int> lp;

//sukon always reads the entire problem statement.
void solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<ll> xa, xb;
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        ll ca = 0, cb = 0;
        while(x > 1) {
            if(lp[x] == 2) {
                ca+=2;
            } else {
                cb += lp[x];
            }
            x /= lp[x];
        }

        if(ca >= cb) {
            tot += cb;
            a--;
            xb.push_back(ca-cb);
        } else {
            tot += ca;
            b--;
            xa.push_back(cb-ca);
        }
    }
    sort(all(xa)); sort(all(xb));
    for(int i = 0; i < a; i++) {
        tot += xa[i];
    }
    for(int i = 0; i < b; i++) {
        tot += xb[i];
    }
    cout << tot;
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 1000000;
    lp = vector<int>(N+1);
    vector<int> pr;

    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }

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