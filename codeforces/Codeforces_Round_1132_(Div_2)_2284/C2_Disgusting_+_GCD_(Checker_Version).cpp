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
    int a, b; cin >> a >> b;
    if(a == b) {
        cout << 0; return;
    }

    if(gcd(a, b) == 1) {
        cout << "1\n" << (b-a); return;
    }

    if(lst[a] <= b) {
        int x = lst[a];
        while(gcd(x, b) != 1) x = lst[x+1];
        cout << "2\n" << (x-a) << " " << (b-x);
        return;
    }

    //gap <= 71 so just retard dp

    vector<pair<int, int>> dp(b-a+1, {INT_MAX, 0});
    dp[0] = {0, 0};
    for(int i = 1; i <= b-a; i++) {
        for(int j = 0; j < i; j++) {
            if(gcd(a+j, a+i) == 1) dp[i] = min(dp[i], {dp[j].f+1, j});
        }
    }
    vector<int> ans;
    int cur = b-a;
    while(cur != 0) {
        ans.push_back(cur-dp[cur].s);
        cur = dp[cur].s;
    }
    reverse(all(ans));
    cout << sz(ans) << "\n";
    for(int x : ans) cout << x << " ";
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