#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
vector<int> get_factors(const vector<pair<int,int>>& pf) {
    vector<int> factors = {1};

    for (auto [p, e] : pf) {
        vector<int> new_factors;
        ll pe = 1;
        for (int i = 0; i <= e; ++i) {
            for (ll f : factors)
                new_factors.push_back(f * pe);
            pe *= p;
        }
        factors.swap(new_factors);
    }

    sort(factors.begin(), factors.end()); 
    return factors;
}

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n); for(int &i : a) cin >> i;

    vector<int> freq(n+1);

    vector<int> fac(n+1);
    for(int i = 2; i <= n; i++)
        if(!fac[i])
            for(int j = i; j <= n; j+=i)
                if(!fac[j]) fac[j] = i;

    for(int x : a) {
        vector<pair<int, int>> pf; int prev = -1;
        int k = x;
        while(fac[k]) {
            if(fac[k] != prev) {
                pf.push_back({fac[k], 1});
                prev = fac[k];
            } else {
                pf.back().second++;
            }
            k/=fac[k];
        }

        vector<int> f = get_factors(pf);
        for(int y : f) {
            if(3*y == x || y <= x/4) continue;

            freq[y]++;
            if(y+1 <= n) freq[y+1]--;
        }

        if(!(x%3)) {
            freq[x/3]++; freq[x/3+1]--;
        }

        freq[1]++; freq[x/4 + 1]--;
        
    }


    for(int i = 1; i <= n; i++) freq[i] += freq[i-1];

    int ans = 0;
    for(int i = n; i >= 0; i--) {
        if(freq[i] >=n-k) {
            ans = i; break;
        }
    }

    cout << ans;


}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}