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

void solve (int n) {
    //then we leave.
    set<pii> seen, adj01, bl, wh;
    auto check = [&](pii p) {
        if(seen.contains(p)) return false;
        bool badj = 0, wadj = 0;
        for(int r = -1; r <= 1; r++) {
            for(int s = -1; s <= 1; s++) {
                if(!r && !s) continue;
                pii q = {p.f+r, p.s+s};
                if(bl.contains(q)) {
                    // if(p.f == -1 && p.s == -1) {
                    //     cout << "hello " << q.f << " " << q.s << endl;
                    // }
                    badj = 1;
                }
                if(wh.contains(q)) wadj = 1;

            }
        }
        return (badj&&wadj);
        //check its adjacency. check that it hasnt been seen yet.
    };
    
    ll shift = 1e6;
    ll os = 0;
    int black = 0, white = 0;
    while (true) {
        black = 0, white = 0;
        seen.clear(); bl.clear(); wh.clear(); adj01.clear();
        //phase 1.
        ll on = os;
        while((black == 0 || white == 0) && (black < n && white < n)) {
            pii cur = {on, 0};
            cout << "? " << on << " 0" << endl;
            char c; cin >> c;
            if(c == 'B') {
                bl.insert(cur);
                black++;
            } else {
                wh.insert(cur);
                white++;
            }
            seen.insert(cur);

            on++;
        }
        on--;
        pii bs = {on, 0};
        for(int r = -1; r <= 1; r++) {
            for(int s = -1; s <= 1; s++) {
                pii why = {bs.f+r, bs.s+s};
                if(check(why)) adj01.insert(why);
            }
        }

        // for(auto p : bl) cout << p.f << " " << p.s << endl;

        while(black < n && white < n && !adj01.empty()) {
            pii att = *adj01.begin();
            adj01.erase(adj01.begin());
            cout << "? " << att.f << " " << att.s << endl;
            char c; cin >> c;
            if(c == 'B') {
                black++; bl.insert(att);
            } else {
                white++; wh.insert(att);
            }
            seen.insert(att);

            for(int r = -1; r <= 1; r++) {
                for(int s = -1; s <= 1; s++) {
                    pii why = {att.f+r, att.s+s};
                    if(check(why)) {
                        adj01.insert(why);
                        // cout << why.f << " " << why.s << endl;
                    }
                }
            }
        }

        if(black < n && white < n) {
            os += shift;
        } else break;
    }

    if(black == n) {
        cout << "! B ";
        for(auto &p : bl) {
            cout << p.f << " " << p.s << " ";
        }
        cout << endl;
        return;
    } else if(white == n) {
        cout << "! W ";
        for(auto &p : wh) {
            cout << p.f << " " << p.s << " ";
        }
        cout << endl;
        return;
    }
    
    assert(false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t, n; cin >> t >> n;
    // int n = 1;
    while(t--) solve(n);
}