#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (ll)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second


//sukon always reads the entire problem statement.
void solve() {
    ll n; cin >> n;
    vector<pair<ll, ll>> P(n);
    for(auto &p : P) cin >> p.f >> p.s;
    ll m; cin >> m;
    vector<pair<ll, ll>> Q(m);
    for(auto &q : Q) cin >> q.f >> q.s;
    auto cross = [&](auto &A, auto &B, auto &C) {
        pair<ll, ll> v1 = {B.f-A.f, B.s-A.s}, v2 = {C.f-A.f, C.s-A.s};
        return v1.f*v2.s-v1.s*v2.f;
    };
    auto dist = [](ll l, ll r, ll n) {
        return (r-l+n)%n;
    };

    ll l = 0;
    ll r = 1;
    ll qpt = 0;
    for(ll i = 0; i < m; i++) {
        if(cross(P[l], P[r], Q[i]) < cross(P[l], P[r], Q[qpt])) {
            qpt = i;
        }
    }

    vector<ll> forward(n), backward(n), pre(n);
    while(1) {
        while((r+1)%n != l) {
            //try r+1
            r = (r+1)%n;
            while(cross(P[l], P[r], Q[(qpt+1)%m]) < cross(P[l], P[r], Q[qpt])) qpt = (qpt+1)%m;
            if(cross(P[l], P[r], Q[qpt]) < 0) {
                r = (r-1+n)%n;
                break;
            }
        }

        forward[l] = r;
        l = (l+1)%n;
        if(r == l) r = (l+1)%n;
        if(l == 0) break;
    }

    // for(ll i = 0; i < n; i++) {
    //     cout << i << " " << forward[i] << endl;
    // }

    //build backward
    ll ex = n-2;
    for(ll i = n-1; i >= 0; i--) {
        while(dist((ex-1+n)%n, forward[(ex-1+n)%n], n) >= dist((ex-1+n)%n, i, n)) ex = (ex-1+n)%n;
        backward[i] = ex;
    }

    // for(ll i = 0; i < n; i++) {
    //     cout << i << " " << backward[i] << endl;
    // }

    for(ll i = 0; i < n; i++) {
        pre[i] = dist(i, forward[i], n);
    }
    partial_sum(all(pre), pre.begin());

    auto pref = [&](ll l, ll r) {
        if(l > r) return pre.back() - (l?pre[l-1]:0) + pre[r];
        return pre[r] - (l?pre[l-1]:0);
    };

    ll ans = 0;
    //everything from i+1 to forward[i]
    //everything from backward[i] to i-1.
    for(ll i = 0; i < n; i++) {
        ll bad = dist(i, forward[i], n)+1;
        ll lo1 = 1, hi1 = dist(i, forward[i], n)+1;
        ll lo2 = 1, hi2 = hi1;

        // cout << i << " " << forward[i] << " " << backward[i] << endl;

        //this is to bsearch the first feasible one.
        while(lo1 < hi1) {
            ll mid = (lo1+hi1)>>1;
            ll acc = (i+mid)%n;
            if(dist(acc, forward[acc], n) >= dist(acc, backward[i], n)) hi1 = mid;
            else lo1 = mid+1;
        }

        //this is to bsearch the first one that overdoes it.
        while(lo2 < hi2) {
            ll mid = (lo2+hi2)>>1;
            ll acc = (i+mid)%n;
            if(dist(acc, forward[acc], n) >= dist(acc, i, n)) hi2 = mid;
            else lo2 = mid+1;
        }

        // cout << i << " " << lo1 << " " << lo2 << " " << bad << endl;

        //now we apply prefix sums?
        //so everything from i+lo1 to i+lo2-1 is a thing.
        ll t = 0;
        if(lo1 < lo2) {
            t += pref((i+lo1)%n, (i+lo2-1+n)%n);
            // cout << i << " " << t << endl;
            ll mx = dist((i+lo1)%n, backward[i], n)-1;
            ll mn = dist((i+lo2-1+n)%n, backward[i], n)-1;
            // cout << mx << " " << mn << endl;
            //mn to mx sum
            t -= mx*(mx+1)/2 - (mn-1)*mn/2;
        }

        if(lo2 < bad) {
            t += ((bad-1) - (lo2-1))*(dist(backward[i], i, n));
        }

        // cout << i << " " << t << endl;

        ans += t;
    }
    assert(ans%3 == 0);
    cout << ans/3;
}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    //ll t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}

/* benq's 5 commandments
 * ll overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */