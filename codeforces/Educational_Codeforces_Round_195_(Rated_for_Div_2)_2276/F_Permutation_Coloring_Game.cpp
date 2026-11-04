#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

vector<vector<vector<int>>> part;

//sukon always reads the entire problem statement.
void solve() {
    int n, k; cin >> n >> k;
    vector<int> p(n); for(auto& i : p) cin >> i, i--;
    vector<bool> vis(n);
    vector<int> cyc;
    vector<int> f(k+2);
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        int size = 0;
        while(!vis[i]) {
            size++;
            vis[i] = 1;
            i = p[i];
        }

        if(size >= k+2) {
            cout << "Bob"; return;
        }
        cyc.push_back(size);
        f[size]++;
    }

    sort(all(cyc));
    if(cyc[0] == k+1) {
        cout << "Bob"; return;
    }
    
    // for(ll x : cyc) cout << x << endl;
    //we handle k = 1 separately.
    if(k==1) {
        cout << (f[2]==0 || f[1]&1 ? "Alice" : "Bob");
        return;
    }

    
    //if there is a k+1, then alice has to destroy everything else > 1
    //but what if theres 1s left? this is the true question
    //so alice destroys the stuff and maybe eats some 1s
    //with m ones left, who wins.
    //0, lose
    //1...k, win
    //k+1 lose
    //k+2...2k+1 win
    //2k+2 lose
    //etc.
    if(cyc.back() == k+1) {
        int sum = 0;
        int ones = 0;
        for(int i = 0; i+1 < sz(cyc); i++) if(cyc[i]>1) sum += cyc[i]; else ones++;
        if(sum > k) {
            cout << "Bob"; return;
        }
        for(int i = max(0, ones-(k-sum)); i <= ones-(sum==0); i++) {
            if(i%(k+1) == 0) {
                cout << "Alice"; return;
            }
        }
        cout << "Bob"; return;
    }

    //otherwise bob just griddies
    //say we subset sum or something.
    //if alice can remove r with s cycles, then sum(size-1) would decrease by r-s.
    //say what remains is t. if t <= k alice always wins.
    //if t > k, then either you have a bunch of 2s where alice wins, or alice loses
    //so either alice can nuke all the non 2s, or alice and make the sum <= k !!!

    vector<int> m(k+1, -1); m[0] = 0;
    for(int x : cyc) {
        for(int i = k; i >= x; i--) {
            if(m[i-x] != -1) m[i] = max(m[i], m[i-x] + x-1);
        }
    }
    int mx = *max_element(all(m));
    int sum = accumulate(all(cyc), 0) - sz(cyc);
    if(sum - mx <= k) {
        cout << "Alice"; return;
    }

    //nuke all the > 2.
    int sum3 = 0;
    for(int x : cyc) if(x > 2) sum3 += x;
    if(sum3 <= k) cout << "Alice";
    else cout << "Bob";
}

//king of the sun o_O
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