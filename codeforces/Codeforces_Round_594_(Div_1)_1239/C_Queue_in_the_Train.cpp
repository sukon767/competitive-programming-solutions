#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

void solve() {
    ll n, P; cin >> n >> P;
    vector<ll> t(n); for(ll& i : t) cin >> i;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for(int i = 0; i < n; i++) pq.push({t[i], i+1});

    set<ll> cur;
    queue<ll> qu;
    vector<ll> ti(n);
    ll qtime = 0;
    while(sz(pq)) {
        ll time = pq.top().first;
        while(sz(pq) && pq.top().first==time) {
            auto& p = pq.top();
            // cout << p.first << " " << abs(p.second) << endl;
            if(p.second > 0) {
                q.push(abs(p.second)-1);
            } else {
                int x = qu.front(); qu.pop();
                cur.erase(x);
            }
            pq.pop();
        }
        if(sz(q) && cur.lower_bound(q.top()) == cur.begin()) {
            qu.push(q.top());
            cur.insert(q.top());
            qtime = max(qtime+P, time+P);
            pq.push({qtime, -(q.top()+1)});
            ti[q.top()] = qtime;
            q.pop();
        }
    }

    for(ll& x : ti) cout << x << " ";
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