#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
using ull = unsigned long long;

ll n, k, x, y;

vector<int> bin(ll N, ll K) {
    if(!N) return {};
    int st = __bit_width(static_cast<ull>(N))-1;
    vector<int> ans = {1};
    ll bit = (1LL<<st); bit >>= 1;
    for(int i = st-1; i >= 0; i--) {
        //double the approx

        vector<int> t1(2*ans.size());
        for(int i = 0; i < ans.size(); i++) {
            if(!ans[i]) continue;
            vector<ll> tst = {2*i, 2*i+x, 2*i+y};
            if(2*i < t1.size()) t1[2*i]++;
            if(2*i+x < t1.size()) t1[2*i+x]++;
            if(2*i+y < t1.size()) t1[2*i+y]++;
        }

        if(N & bit) {
            //find next term
            int c = 0;
            if(t1.size() >= x) c += t1[t1.size()-x];
            if(t1.size() >= y) c += t1[t1.size()-y];
            t1.push_back(c);
        }

        ans.clear();
        for(int i = max(0LL, int(t1.size())-k); i < t1.size(); i++) {
            ans.push_back(t1[i]%2);
        }

        bit >>= 1;
        
    }
    return ans;
}

void solve() {
    cin >> n >> k >> x >> y;
    if(x == y) {
        for(int i = 0; i < k; i++) cout << 0;
        return;
    }
    if(y < x) swap(x, y);

    vector<int> ans(k);
    //for bits k-1 to k-x, it corresponds to n-k to n-k+x-1
    vector<int> p1 = bin(n-k+x, k);
    reverse(p1.begin(), p1.end());

    for(int i = 0; i < x; i++) {
        ans[k-x+i] = p1[i];
    }

    //for bits k-x-1 to k-y it corresponds n-k+x -y to n-k+y-1 -y
    for(int i = 0; i+x < min((ll)p1.size(), y); i++) {
        ans[k-y+i] = p1[i+x];
    }

    reverse(ans.begin(), ans.end());

    for(int i : ans) cout << i;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    // int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}