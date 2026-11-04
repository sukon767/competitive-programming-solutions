    #include<bits/stdc++.h>
    
    using namespace std;
    
    using ll = long long;
    using ld = long double;
    
    void solve() {
        ll s, k; cin >> s >> k;
        ll ans = 0;
        if(s % 10 == 0) {cout << s*k; return;}
        if(s%10 == 5) {cout << max(s*k, (s+5)*(k-1)); return;}
        if(s % 2) {ans = s*k; s += (s%10); k--;}

        //s is 2 4 6 8
        vector<ll> p(4);
        p[1] = s%10; for(int i = 2; i < 4; i++) p[i] = p[i-1]*2%10;
        for(int i = 1; i < 4; i++) p[i] += p[i-1];

        for(int r = 0; r < 4; r++) {
            if(k < r) continue;
            ll ma = (k-r)/4, opt = (20*k - 20*r - 4*s - 4*p[r])/160;
            ans = max(ans, max((k-r)*(s + p[r]), (k-4*ma-r)*(s+20*ma+p[r])));
            if(0 <= 4*opt + r && 4*opt + r <= k) ans = max(ans, (k-4*opt - r)*(s + 20*opt + p[r]));
                    // cout << r << " " << opt << " " << (k-4*opt - r)*(s + 20*opt + p[r]) << endl;

            if(0 <= 4*(opt+1) + r && 4*(opt+1) + r <= k) ans = max(ans, (k-4*(opt+1) - r)*(s + 20*(opt+1) + p[r]));        
        }

        cout << ans;
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