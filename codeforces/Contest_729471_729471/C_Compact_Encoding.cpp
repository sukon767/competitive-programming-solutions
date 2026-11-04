#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define retp(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve () {
    int n;
    cin >> n;

    if(n == 0) {
        cout << 0;
        // cout << "\n";
        return;
    }

    vector<int> b;
    int bb = (1<<7)-1;
    for(int i = 5; i >= 0; i--) {
        b.push_back(n & (bb));
        n >>= 7;
    }

    while(sz(b) && b.back() == 0) b.pop_back();
    reverse(all(b));

    // for(int x : b) cout << x << " ";
    // cout << endl;

    for(int i = 0; i < sz(b); i++) {
        int x = b[i];
        if(i+1 < sz(b)) x |= (1<<7);
        cout << x << " ";
    }

    // cout << "\n";
    
    return;   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    // int n; cin >> n;
    int n = 1;
    while(n--) solve();
}