#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

vector<int> bp, pr;

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    if(n <= 15) {
        cout << "2 1 ";
        for(int i = 3; i <= n; i++) cout << i << " ";
    } else {
        for(int i = 1; i < 2*bp[n]-i; i++) cout << i << " " << 2*bp[n]-i << " ";
        cout << bp[n] << " ";
        for(int i = 2*bp[n]; i <= n; i++) cout << i << " ";
    }
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 2e5;
    vector<bool> sieve(N+1);
    for(int i = 2; i <= N; i++) {
        if(!sieve[i]) {
            pr.push_back(i);
            for(int j = i; j <= N; j+=i) sieve[j] = 1;
        }
    }

    bp = vector<int>(N+1); int pt = 0;
    for(int i = 2; i <= N; i++) {
        while(2*pr[pt+1] <= i+1) pt++;
        bp[i] = pr[pt];
    }

    // pair<ld, int> x = {1, 0};
    // for(int i = 15; i <= N; i++) x = min(x, {ld(bp[i])/i, i});
    // cout << x.f << " " << x.s << endl;

    int t; cin >> t;
    // int t = 1;
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