#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

//sukon always reads the entire problem statement.
void solve() {
    //1, 3, 7: 1
    //all even: n
    //all even but there is some 5s....
    //reduce to even but play on 0, 1, 2, 3, 4 mod 5. try to make 4 essentially.
    //if (there exists a nonzero and at least two evens) or (there exists a 4)
    //then we can make everything a 4.
    //then answer is 1.
    //otherwise this means we cannot game anything so n.

    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    vector<int> f(9);
    int evens = 0;
    for(int x : a) {
        if(x == 1 || x == 3 || x == 7) {
            cout << 1; return;
        } else {
            if(x%2 == 0) evens++;
        }
        f[x]++;
    }
    int fives = n-evens;

    if(fives == 0) cout << n;
    else if(f[4] || (evens-f[0] && evens>=2)) {
        cout << 1;
    } else cout << n;
}

//king of the sun o_O
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