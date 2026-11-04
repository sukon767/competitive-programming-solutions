#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

// Fills lookup array lookup[][] in bottom up manner.
vector<vector<pair<int, int>>> buildSparseTable(vector<int> &arr) {
    int n = arr.size();

    // create the 2d table
    vector<vector<pair<int, int>>> lookup(n + 1,
                vector<pair<int, int>>(log2(n) + 1));

    // Initialize for the intervals with length 1
    for (int i = 0; i < n; i++)
        lookup[i][0] = {arr[i], i};

    // Compute values from smaller to bigger intervals
    for (int j = 1; (1 << j) <= n; j++) {

        // Compute minimum value for all intervals with
        // size 2^j
        for (int i = 0; (i + (1 << j) - 1) < n; i++) {

            if (lookup[i][j - 1] < 
                lookup[i + (1 << (j - 1))][j - 1])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = 
                lookup[i + (1 << (j - 1))][j - 1];
        }
    }

    return lookup;
}

// Returns minimum of arr[L..R]
pair<int, int> query(int L, int R, vector<vector<pair<int, int>>> &lookup)  {

    // Find highest power of 2 that is smaller
    // than or equal to count of elements in range
    int j = (int)log2(R - L + 1);

    // Compute minimum of last 2^j elements with first
    // 2^j elements in range.
    if (lookup[L][j] <= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];
    else
        return lookup[R - (1 << j) + 1][j];
}

//sukon always reads the entire problem statement.
void solve() {
    int n, k; cin >> n >> k;
    vector<int> p(n); for(int &i : p) cin >> i, i--;
    vector<int> ip(n);
    for(int i = 0; i < n; i++) ip[p[i]]=i;
    if(n&1) {
        auto sparse = buildSparseTable(ip);

        if(k > n-1) {cout << -1; return;}
        vector<int> ord(n-1); iota(all(ord), 0);
        reverse(all(ord));

        auto cmp = [&](int a, int b) {
            // cout << a << " " << b << endl;
            // bool print = a==1 && b==2;
            bool sw = 0;
            if(a > b) {swap(a, b); sw = 1;}
            int af = a&(~1), bf = b&(~1);

            pair<pair<int, int>, bool> mn = {{INT_MAX, 0}, 0};
            if(af+3 < bf) mn.f = min(mn.f, query(af+3, bf-1, sparse));
            if(mn.f.f != INT_MAX) {
                int x = mn.f.s+(mn.f.s&1 ? 1 : -1), y = mn.f.s+(mn.f.s&1 ? -1 : 1);
                mn.s = x < y;
            }
            pair<int, bool> mni = {mn.f.f, mn.s};
            // cout << mni.f << " " << mni.s << endl;

            int k1 = (a&1 ? -1 : 1), k2 = (b&1 ? -1 : 1);
            for(int i = 0; i < 3; i++) {
                //the place where it goes to is actually the opposite...
                int x = af + (i-k1+3)%3;
                int y = (af+i < bf ? (af+i)^1 : bf+(-k2+3)%3);
                
                // if(print) cout << ip[af+i] << " " << x << " " << y << " " << (x<y) << endl;
                if(x != y) mni = min(mni, {ip[af+i], x<y});
            }

            for(int i = 0; i < 3; i++) {
                int x = (af+2 < bf+i ? bf+i + ((bf+i)&1 ? 1 : -1) : af+(2-k1+3)%3);
                int y = bf + (i-k2+3)%3;

                // if(print) cout << ip[bf+i] << " " << x << " " << y << " " << (x<y) << endl;
                if(x != y) mni = min(mni, {ip[bf+i], x<y});
            }
            // if(print) {
            //     cout << mni.f << " " << mni.s << " " << sw << endl;
            // }
            return mni.s^sw;
        };
        sort(all(ord), cmp);
        int pos = ord[--k];
        int pf = pos&(~1);
        int k3 = (pos&1 ? -1 : 1);
        vector<int> nip;
        for(int i = 0; i < pf; i++) nip.push_back(ip[i^1]);
        for(int i = 0; i < 3; i++) nip.push_back(ip[pf+(i+k3+3)%3]);
        for(int i = pf+3; i < n; i+=2) {nip.push_back(ip[i+1]); nip.push_back(ip[i]);}
        vector<int> np(n); for(int i = 0; i < n; i++) np[nip[i]] = i;
        for(int x : np) cout << x+1 << " ";
    } else {
        if(k > 1) {cout << -1; return;}
        vector<int> nip;
        for(int i = 0; i < n; i++) nip.push_back(ip[i^1]);
        vector<int> np(n); for(int i = 0; i < n; i++) np[nip[i]] = i;
        for(int x : np) cout << x+1 << " ";
    }
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