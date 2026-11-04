#include <bits/stdc++.h>
using namespace std;
void boos() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define pb push_back
#define en '\n'
const int N = 2e5 + 10;
const int INF = 1e9 + 7;
int a[N], b[N], c[N];
int n;
void solve() {
    cin >> n;
    int sumA = 0, sumB = 0;
    pair <int,int> mxC = {-INF,0};
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
        sumA += a[i];
        sumB += b[i];
        c[i] = b[i] - a[i];
        mxC = max(mxC, {c[i], i});
    }
    if(sumA + mxC.first >= sumB) {
        cout << mxC.second;
    }else {
        cout << "impossible";
    }

}

int main() {
    solve();
}
