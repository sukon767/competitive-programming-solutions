    #include<bits/stdc++.h>
    
    using namespace std;
    
    using ll = long long;
    using ld = long double;
    
    void solve() {
        ll n, m; cin >> n >> m;
        vector<pair<ll, ll>> a(n); for(auto &i : a) cin >> i.first;
        for(ll i = 0; i < n; i++) a[i].second = i+1;
        sort(a.begin(), a.end());
        if(m > n/2) {cout << -1 << "\n"; return;}

        if(!m) {
            ll cur = 0;
            for(ll i = 0; i < n-1; i++) cur += a[i].first;
            if(cur < a[n-1].first) {cout << -1 << "\n"; return;}
            cur = 0;
            ll ind = n-3;
            while(ind >= 0 && cur < a[n-1].first - a[n-2].first) {
                cur += a[ind].first;
                ind--;
            }

            cout << n-1 << "\n";
            for(ll i = 0; i <= ind; i++) {
                cout << a[i].second << " " << a[i+1].second << "\n";
            }
            for(ll i = ind+1; i <= n-2; i++)
                cout << a[i].second << " " << a[n-1].second << "\n";
            // cout << "debug " << ind << " " << cur << endl;
            return;
        }

        cout << n-m << "\n";
        for(ll i = 0; i < n-2*m; i++) cout << (a[i].second) << " " << (a[i+1].second) << "\n";
        for(ll i = n-1; i >= n-m; i--) {cout << (a[i].second) << " " << (a[i-m].second) << "\n";}

    }
    
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        ll t; cin >> t;
        //ll t = 1;
        for(ll i = 0; i < t; i++) {
            if(i)   cout << "\n";
            solve();
        }
    }