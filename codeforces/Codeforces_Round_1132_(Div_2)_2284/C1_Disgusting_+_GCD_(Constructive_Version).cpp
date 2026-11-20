#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

vector<int> lst;

//sukon always reads the entire problem statement.
void solve() {
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        cout << lst[x] << " ";
    }
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 2e5;
    vector<bool> sieve(N+1);
    lst = vector<int>(N+1);
    for(int i = 2; i <= N; i++) {
        if(!sieve[i]) {
            for(int j = 2*i; j <= N; j+=i) sieve[j] = 1;
        }
    }

    for(int i = N-1; i >= 0; i--) {
        if(!sieve[i]) {
            lst[i] = i;
        } else lst[i] = lst[i+1];
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