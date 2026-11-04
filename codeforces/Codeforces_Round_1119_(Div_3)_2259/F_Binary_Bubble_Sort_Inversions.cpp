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
    int n; cin >> n;
    vector<int> a(n); for(int& i : a) cin >> i;
    string s; cin >> s;
    //type, length.
    deque<pair<int, int>> run;
    for(int x : a) {
        if(!sz(run) || run.back().f != x) run.push_back({x, 1});
        else run.back().s++;
    }

    // for(auto &p : run) cout << p.f << " " << p.s << endl;

    ll inv = 0;
    int ad = 0;
    for(int x : a) {
        if(x == 1) ad++;
        else inv += ad;
    }

    //ad is number of ones.
    cout << inv << " ";
    for(char c : s) {
        if(c == '1') {
            int l = 0, r = sz(run)-1;
            if(run[0].f == 0) l++;
            if(l < r) {
                inv -= ((n-ad) - (l == 1 ? run[l-1].s : 0));
                run[l].s--;
                if(run[r].f == 0) run.push_back({1, 1});
                else run[r].s++;

                if(run[0].s == 0) run.pop_front();
                if(sz(run) > 1 && run[1].s == 0) {
                    int p = run[0].s;
                    run.pop_front(); run.pop_front();
                    assert(sz(run));
                    run[0].s += p;
                }
            }
        } else {
            int l = 0, r = sz(run)-1;
            if(run[sz(run)-1].f == 1) r--;
            if(l < r) {
                inv -= (ad - (r == sz(run)-2 ? run[r+1].s : 0));
                run[r].s--;
                if(run[l].f == 1) run.push_front({0, 1});
                else run[l].s++;

                if(run[sz(run)-1].s == 0) run.pop_back();
                if(sz(run) > 1 && run[sz(run)-2].s == 0) {
                    int p = run[sz(run)-1].s;
                    run.pop_back(); run.pop_back();
                    assert(sz(run));
                    run[sz(run)-1].s += p;
                }
            }
        }
        // cout << endl;
        // for(auto &p : run) cout << p.f << " " << p.s << endl;

        cout << inv << " ";
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