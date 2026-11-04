#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

vector<pair<int, int>> trie, dp;
vector<int> unused;
int k;

void insert(const ll &key) {
    int cur = 0;

    ll b = 1;
    for (int i = 0; i < k; i++) {
        if(!(key & b)) {
            if(trie[cur].first == -1) {
                if(unused.size()) {
                    trie[unused.back()] = {-1, -1};
                    dp[unused.back()] = {0, 0};
                    trie[cur].first = unused.back();
                    unused.pop_back();
                } else {
                    trie[cur].first = trie.size();
                    trie.push_back({-1, -1});
                    dp.push_back({0, 0});
                }
                
            }
            cur = trie[cur].first;
        } else {
            if(trie[cur].second == -1) {
                if(unused.size()) {
                    trie[unused.back()] = {-1, -1};
                    dp[unused.back()] = {0, 0};
                    trie[cur].second = unused.back();
                    unused.pop_back();
                } else {
                    trie[cur].second = trie.size();
                    trie.push_back({-1, -1});
                    dp.push_back({0, 0});
                }
            }
            cur = trie[cur].second;
        }

        b <<= 1;
    }

    dp[cur].second = -1;
}

void add(const ll &key, int v) {
    
    int cur = 0;
 
    vector<int> path;
    path.push_back(0);
 
    ll b = 1;
    for (int i = 0; i < k; i++) {
        if(!(key & b)) cur = trie[cur].first;
        else cur = trie[cur].second;

        dp[cur].first += v;
        path.push_back(cur);
        b <<= 1;
    }
 
    // update up
    for (int i = int(path.size()) - 2; i >= 0; i--)
    {
        int node = path[i];
 
        if(trie[node].first != -1 && !dp[trie[node].first].first) {unused.push_back(trie[node].first); trie[node].first = -1;}
        if(trie[node].second != -1 && !dp[trie[node].second].first) {unused.push_back(trie[node].second); trie[node].second = -1;}
        
        int s = -1;
 
        if(trie[node].first == -1) s = max(s, 0);
        else s = max(s, dp[trie[node].first].second);

        if(trie[node].second == -1) s = max(s, 0);
        else s = max(s, dp[trie[node].second].second);
 
        if(s == -1) dp[node].second = -1;
        else dp[node].second = dp[node].first + s;
    }
 
}

void solve() {
    int n, q; cin >> n >> q >> k;
    vector<ll> a(n); for(ll &i : a) cin >> i;

    trie = vector<pair<int, int>>(1, {-1, -1}), dp = vector<pair<int, int>>(1);
    unused.clear();

    //build trie
    for(ll x : a) {
        insert(x);
        add(x, 1);
    }

    cout << dp[0].second << '\n';

    for(int i = 0; i < q; i++) {
        int x; ll v; cin >> x >> v;
        --x;
        
        add(a[x], -1);
        insert(v);
        add(v, 1);
        a[x] = v;

        cout << dp[0].second << "\n";
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