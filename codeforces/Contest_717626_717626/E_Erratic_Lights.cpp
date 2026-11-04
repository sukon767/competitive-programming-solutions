#include <bits/stdc++.h>
using namespace std;
void boos() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define pb push_back
#define en '\n'
const int N = 110;
int n;
double dp[N][N][N];
void solve() {
    cin >> n;
    string s;
    cin >> s;
    // s = "";
    // for(int i = 1;i <= 33;i++) {
    //     s += "rgb";
    // }
    // s += "b";
    int cnt_r = 0,cnt_b = 0,cnt_g = 0;
    for(auto c: s) {
        cnt_r += (c == 'r');
        cnt_b += (c == 'b');
        cnt_g += (c == 'g');
    }
    if(cnt_r > cnt_b) swap(cnt_r, cnt_b);
    if(cnt_b > cnt_g) swap(cnt_b, cnt_g);
    if(cnt_r > cnt_b) swap(cnt_r, cnt_b);
    
    double ans = 1.5 * cnt_r;
    for(int k = 0;k <= cnt_r;k++) {
        double cur = min(cnt_b + k, cnt_g + cnt_r - k) * 3.0;
        for(long long j = 1;j <= k;j++) {
            cur *= (cnt_r - j + 1);
            cur /= (double)j;
        }
        for(int i = 1;i <= cnt_r;i++) cur /= 2.0;
        ans += cur;
        
    }
    // cout << cnt_r << " " << cnt_b << " " << cnt_g << endl;

    cout << fixed << setprecision(11) << ans << endl;
    // cout << fixed << setprecision(11) << ans2 << endl;
}

int main() {
    solve();
}
