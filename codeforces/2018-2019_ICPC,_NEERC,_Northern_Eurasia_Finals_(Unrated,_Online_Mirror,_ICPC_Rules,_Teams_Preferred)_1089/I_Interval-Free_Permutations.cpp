// CutSandstone always reads the entire problem statement.
#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
using ll = long long;
const ll oo = 1e18;
template <class T> T uMin(T &a, T b) { return a = min(a, b); }
template <class T> T uMax(T &a, T b) { return a = max(a, b); }
const int N = 400;
ll dp[N + 1][N + 1];
ll fac[N + 1];
ll ret[N + 1];
ll small[N + 1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, p;
    cin >> t >> p;
    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % p;
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 0; k < i; k++)
                dp[i][j] = (dp[i][j] + dp[k][j - 1] * fac[i - k]) % p;
        }
    }
    small[0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < i; j++)
            small[i] = (small[i] - small[j] * fac[i - j] % p + p) % p;

    //cout << (small[5]+120)%p << endl;
    ret[0]=ret[1]=1;
    ret[2]=2;

    for(int i = 3; i <= N; i++) {
        ret[i]=(small[i]+fac[i])%p;
        ret[i]=ret[i]*2%p;
    }

    //cout << ret[3] << " " << small[3] << endl;

    
    for (int i = 3; i <= N; i++) {
        for (int j = 3; j < i; j++)
            ret[i] = (ret[i] + dp[i][j] * ret[j]) % p;
        ret[i] = (fac[i] - ret[i] + p) % p;
    }
    while (t--) {
        int n;
        cin >> n;
        cout << ret[n] << "\n";
    }
}