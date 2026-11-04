#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    string s; cin >> s;

    int n = s.size();

    if(n == 1) {cout << s; return;}

    int tot = 0;
    vector<int> freq(10);
    for(int i = 0; i < n; i++) {
        freq[int(s[i]) - int('0')]++; 
    }

    for(int i = 0; i < 10; i++) tot += i*freq[i];
    int N = 9*n+1;
    vector<int> dp(N);


    for(int i = 0; i < N; i++) {

        int x = i;
        vector<int> t(10); 
        while(x > 9) {
            int sx = 0;
            int k = x;
            while(k) {
                t[k%10]++;
                sx += k%10;
                k /= 10;
            }
            x = sx;
        }

        t[x]++;

        // if(i == 12) {
        //     for(int j = 0; j < 10; j++) cout << j << " " << t[j] << endl;
        // }


        for(int j = 0; j < 10; j++) {
            if(dp[i] == -1) break;

            if(t[j] > freq[j]) dp[i] = -1;
            else dp[i] += j*t[j];
        }
    }

    // cout << "asdf" << endl;

    // for(int i = 0; i < N; i++) {
    //     cout << i << " " << dp[i] << endl;
    // }

    // cout << tot << " " << s << endl;

    for(int i = 1; i < N; i++) {

        // cout << "asdf" << endl;
        if(dp[i] == -1) continue;
        if(tot - dp[i] == i) {
            // construct

            
            string ans;

            int x = i;
            while(x > 9) {
                string temp;

                int sx = 0;
                int k = x;
                while(k) {
                    freq[k%10]--;
                    temp = char(k%10 + int('0')) + temp;
                    sx += k%10;
                    k /= 10;
                }
                ans += temp;

                x = sx;
            }
            freq[x]--;
            ans += char(x + int('0'));

            string pre;

            for(int j = 9; j >= 0; j--)
                for(int k = 0; k < freq[j]; k++) pre += char(j + int('0'));

            pre += ans;
            cout << pre;
            return;
        }
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