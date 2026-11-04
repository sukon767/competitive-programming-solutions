#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()


const int K = 26;

struct Vertex {
    int next[K];
    bool output = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    
    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<ll> a;
vector<ll> val(1);
vector<Vertex> t(1);

void add_string(string const& s, int i) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
            val.push_back(0);
        }
        v = t[v].next[c];
    }
    t[v].output = true;
    val[v] += a[i];
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

template <typename T>
vector<vector<T>> matMul(const vector<vector<T>>& a, const vector<vector<T>>& b) {
    assert(sz(a) && sz(b) && sz(a[0]) && sz(b[0]) && sz(a[0]) == sz(b));
    vector<vector<T>> ans(sz(a), vector<T>(sz(b[0])));
    for(int i = 0; i < sz(a); i++) {
        for(int j = 0; j < sz(b[0]); j++) {
            ll t = LLONG_MIN>>4;
            for(int k = 0; k < sz(b); k++) {
                t = max(t, a[i][k]+b[k][j]);
            }
            ans[i][j] = t;
        }
    }
    return ans;
}

template <typename T>
vector<vector<T>> matExp(vector<vector<T>> a, ll N) {
    int n = sz(a);
    assert(n && n == sz(a[0]));
    vector<vector<T>> ans(n, vector<T>(n, LLONG_MIN>>4));
    for(int i = 0; i < n; i++) ans[i][i] = 0;
    while(N) {
        if(N&1) ans = matMul(ans, a);
        a = matMul(a, a);
        N>>=1;
    }
    return ans;
}

void solve() {
    ll n, l; cin >> n >> l;
    a = vector<ll>(n); for(ll& i : a) cin >> i;
    for(int i = 0; i < n; i++) {
        string s; cin >> s; add_string(s, i);
    }
    int m = sz(t);
    for(int i = 0; i < m; i++) get_link(i);
    vector<vector<int>> adj(m);
    for(int i = 0; i < m; i++) adj[t[i].link].push_back(i);
    auto dfs = [&](auto&& self, int x) -> void {
        for(int y : adj[x]) if(y!=x) {val[y]+=val[x]; self(self, y);}
    };
    dfs(dfs, 0);
    vector<vector<ll>> A(m, vector<ll>(m, LLONG_MIN>>4));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < K; j++) {
            int z = go(i, 'a'+j);
            A[i][z] = max(A[i][z], val[z]);
        }
    }
    A = matExp(A, l);
    cout << *max_element(A[0].begin(), A[0].end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
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