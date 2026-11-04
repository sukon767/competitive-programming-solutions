#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
int maxN = 2e9;
int s = sqrt(maxN);
vector<int> fac(s+1);

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> pf;
    int k = n;
    for(int i = 2; i <= s; i++)
        if(fac[i] == i && !(k%i)) {
            while(!(k%i)) {
                if(pf.size() && pf.back().first == i) pf.back().second++;
                else pf.push_back({i, 1});
                k /= i;
            }
        }

    if(k > 1) pf.push_back({k, 1});
    for(auto &p : pf) {
        int c = p.second/n;
        if(p.second % n) c++;
        p.second = c;
    }

    int ans = 1;
    for(auto p : pf)
        for(int i = 0; i < p.second; i++) ans *= p.first;
    
    cout << ans;
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    
    for(int i = 2; i <= s; i++)
        if(!fac[i])
            for(int j = i; j <= s; j+=i)
                if(!fac[j]) fac[j] = i;

    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}