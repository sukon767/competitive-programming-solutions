#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int cnt = 0;
    int rn = 0;
    int xv1 = 0, i1 = 0, both = 0, dub = 0;
    int score = 0; 

    for(int i = 0; i < n; i++) {
        // cout << i << " " << rn << endl;
        if(s[i] == '?') {

            rn++;
            cnt++;

            if(i && i < n-1 && s[i-1] == 'I' && (s[i+1] == 'X' || s[i+1] == 'V')) {
                both++; rn--; continue;
            }

            if(i && s[i-1] == 'I') {xv1++; rn--; continue;}

            if(i < n-1 && (s[i+1] == 'X' || s[i+1] == 'V')) {i1++; rn--; continue;}
        } else {
            dub += rn/2;
            rn = 0;
            if(s[i] == 'I') {
                if(i < n-1 && (s[i+1] == 'X' || s[i+1] == 'V')) score--;
                else score++;
            }
            else if(s[i] == 'V') score+=5;
            else score+=10;
        }
    }
    dub += rn/2;

    // cout << xv1 << " " << i1 << " " << both << " " << dub << endl;

    for(int i = 0; i < q; i++) {
        int cx, cv, ci; cin >> cx >> cv >> ci;
        int temp = cnt;
        ci = min(temp, ci); temp -= ci;
        cv = min(temp, cv); temp -= cv;
        cx = min(temp, cx); temp -= cx;
        int ans = score + ci + 5*cv + 10*cx;
        // cout << i << " " << ans << endl;



        int minus = 0;
        int cvx = cv + cx;
        minus += min(cvx, xv1); cvx -= min(cvx, xv1);
        minus += min(ci, i1); ci -= min(ci, i1);

        // cout << i << " " << ci << " " << cvx << endl;
        
        int tboth = both;
        int d = abs(ci-cvx);
        int z = min(d, tboth);
        if(ci > cvx) {
            ci -= z;
        } else {
            cvx -= z;
        }
        tboth -= z; minus += z;

        if(tboth >= ci+cvx) {
            tboth -= ci+cvx; minus += ci+cvx; ci = cvx = 0;
        } else {
            ci -= tboth/2; cvx -= tboth/2;
            if(tboth&1) ci--;
            minus += tboth;
        }

        // cout << i << " " << dub << " " << ci << " " << cvx << endl;

        minus += min(dub, min(ci, cvx));

        cout << ans-2*minus << "\n";
    }
}
 
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

 /* new testament
 * nick belov always reads the entire problem statement.
 */