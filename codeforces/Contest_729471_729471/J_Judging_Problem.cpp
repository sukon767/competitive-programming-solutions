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

void solve (){
    int n;
    cin >> n;
    vector<pair<string, string>> prob(n);
    for (int i = 0; i < n; i++) {
        cin >> prob[i].first >> prob[i].second;
    }

    map<string, set<int>> fi, se;
    for(int i = 1; i < n; i++) {
        fi[prob[i].first].insert(i);
        se[prob[i].second].insert(i);
    }

    pair<string, string> prev = prob[0];
    for (int i = 1; i < n; i++) {
        if (prob[i].first == prev.first || prob[i].second == prev.second) {
            fi[prob[i].first].erase(i);
            se[prob[i].second].erase(i);
            prev = prob[i];
        } else {
            if (!fi[prev.first].empty() || !se[prev.second].empty()) {
                cout << "No\n";
                return;
            }
            fi[prob[i].first].erase(i);
            se[prob[i].second].erase(i);
            prev = prob[i];
        }
    }
    cout << "Yes\n";
    return;   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    while(n--) solve();
}