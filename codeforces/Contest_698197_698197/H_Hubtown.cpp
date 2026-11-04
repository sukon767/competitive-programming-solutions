#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()

/**
 * Author: Simon Lindholm
 * Date: 2015-01-31
 * License: CC0
 * Source: me
 * Description: A class for ordering angles (as represented by int points and
 *  a number of rotations around the origin). Useful for rotational sweeping.
 *  Sometimes also represents points or vectors.
 * Usage:
 *  vector<Angle> v = {w[0], w[0].t360() ...}; // sorted
 *  int j = 0; rep(i,0,n) { while (v[j] < v[i].t180()) ++j; }
 *  // sweeps j such that (j-i) represents the number of positively oriented triangles with vertices at 0 and i
 * Status: Used, works well
 */
// #pragma once

struct Angle {
	int x, y;
	int t;
	Angle(int x, int y, int t=0) : x(x), y(y), t(t) {}
	Angle operator-(Angle b) const { return {x-b.x, y-b.y, t}; }
	int half() const {
		assert(x || y);
		return y < 0 || (y == 0 && x < 0);
	}
	Angle t90() const { return {-y, x, t + (half() && x >= 0)}; }
	Angle t180() const { return {-x, -y, t + half()}; }
	Angle t360() const { return {x, y, t + 1}; }
};
bool operator<(Angle a, Angle b) {
	// add a.dist2() and b.dist2() to also compare distances
	return make_tuple(a.t, a.half(), a.y * (ll)b.x) <
	       make_tuple(b.t, b.half(), a.x * (ll)b.y);
}

// Given two points, this calculates the smallest angle between
// them, i.e., the angle that covers the defined line segment.
pair<Angle, Angle> segmentAngles(Angle a, Angle b) {
	if (b < a) swap(a, b);
	return (b < a.t180() ?
	        make_pair(a, b) : make_pair(b, a.t360()));
}
Angle operator+(Angle a, Angle b) { // point a + vector b
	Angle r(a.x + b.x, a.y + b.y, a.t);
	if (a.t180() < r) r.t--;
	return r.t180() < a ? r.t360() : r;
}
Angle angleDiff(Angle a, Angle b) { // angle b - angle a
	int tu = b.t - a.t; a.t = b.t;
	return {a.x*b.x + a.y*b.y, a.x*b.y - a.y*b.x, tu - (b < a)};
}

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<Angle, pair<int, int>>> t; //angle capacity
    vector<pair<Angle, pair<int, int>>> tc; //angle type
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        tc.push_back({Angle(x, y), {1, i}});
    }
    for(int i = 0; i < m; i++) {
        int x, y, c; cin >> x >> y >> c;
        tc.push_back({Angle(x, y), {2, i}});
        t.push_back({Angle(x, y), {c, i}});
    }

    if(m==1) {
        cout << min(t[0].second.first, n) << "\n"; 
        for(int i = 0; i < min(t[0].second.first, n); i++) cout << tc[i].second.second << " " << 0 << "\n";
        return;
    }

    
    sort(t.begin(), t.end());
    sort(tc.begin(), tc.end());
    
    vector<int> share(m);
    int base = 0;
    vector<vector<int>> citLeft(m);
    vector<pair<int, int>> bmvs;

    // for(int i = 0; i < m; i++) {
    //     cout << t[i].second.second << endl;
    // }

    // for(int i = 0; i < n+m; i++) {
    //     cout << tc[i].second.first << " " << tc[i].second.second << endl;
    // }

    // cout << "ASDf" << endl;
    int l = m-1;
    for(int i = 0; i < n+m; i++) {
        if(tc[i].second.first==2) {
            l++; l%=m;
        } else {
            //check for turnarounds might be restarded

            // cout << tc[i].second.second << " " << l << endl;
            auto p1 = segmentAngles(tc[i].first, t[(l+1)%m].first), p2 = segmentAngles(t[l].first, tc[i].first);
            Angle x1 = angleDiff(p1.first, p1.second), y1 = angleDiff(p2.first, p2.second);
            

            // if(tc[i].second.second==0) {
            //     cout << t[(l+1)%m].first.x << " " << t[(l+1)%m].first.y << endl;
            //     cout << tc[i].first.x << " " << tc[i].first.y << endl;
            //     cout << t[l].first.x << " " << t[l].first.y << endl;
            //     cout << (x1 < y1) << " " << (y1 < x1) << endl;
            // }

            if(x1 < y1) {
                // if(tc[i].second.second==2) {
                //     cout << t[(l+1)%m].second.first << endl;
                // }
                if(t[(l+1)%m].second.first) { 
                    t[(l+1)%m].second.first--; base++;
                    bmvs.push_back({tc[i].second.second, t[(l+1)%m].second.second});
                }
            } else if(y1 < x1) {
                if(t[l].second.first) {
                    t[l].second.first--; base++;
                    bmvs.push_back({tc[i].second.second, t[l].second.second});
                }
            } else {
                //SUS
                citLeft[l].push_back(tc[i].second.second);
                share[l]++;
            }
        }
    }

    
    pair<int, int> z = {INT_MAX, 0};
    for(int i = 0; i < m; i++) {
        pair<int, int> zz = {share[i] + share[(i+1)%m], i};
        z = min(z, zz);
    }
    
    vector<int> temp1;
    vector<pair<Angle, pair<int, int>>> temp2;
    vector<vector<int>> temp3;
    for(int i = 0; i < m; i++) {
        temp1.push_back(share[(i+z.second)%m]);
        temp2.push_back(t[(i+z.second)%m]);
        temp3.push_back(citLeft[(i+z.second)%m]);
    }
    share = temp1; t = temp2; citLeft = temp3;
    
    //now iterate on force.
    //share[i] is the gap between t[i] and t[i+1]
    //so we iterate share[0], share[1], with t[1]. YES
    int ans = 0;
    vector<pair<int, int>> mvs(m);
    for(int b = max(0, min(share[0], t[1].second.first - share[1])); b <= min(share[0], t[1].second.first); b++) {
        vector<int> sh = share;
        vector<pair<int, int>> pp(m);
        auto tt = t;
        int cur = 0;

        int g;
        sh[0]-=b, tt[1].second.first-=b;
        cur += b;
        pp[0].second += b;
        for(int i = 1; i < m+1; i++) {
            //try before and after
            g = min(sh[i%m], tt[i%m].second.first); sh[i%m]-=g, tt[i%m].second.first-=g; pp[i%m].first += g;
            cur += g;
            g = min(sh[i%m], tt[(i+1)%m].second.first); sh[i%m]-=g; tt[(i+1)%m].second.first-=g; pp[i%m].second +=g;
            cur += g;
        }
        if(cur > ans) {
            ans = cur;
            mvs = pp;
        } 
    }

    cout << base+ans << "\n";
    assert(sz(bmvs) == base);
    for(auto& p : bmvs) cout << p.first << " " << p.second << "\n";

    for(int i = 0; i < m; i++) {
        for(int x : citLeft[i]) {
            if(mvs[i].first) {
                cout << x << " " << t[i].second.second << "\n";
                mvs[i].first--;
            } else if(mvs[i].second) {
                cout << x << " " << t[(i+1)%m].second.second << "\n";
                mvs[i].second--;
            } else break;
        }
    }
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