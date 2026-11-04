#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define sz(x) (int)(x).size()
 
void solve() {
    int a, b; cin >> a >> b;
    vector<pair<int, int>> ans;
    bool ok = 0;
    for(int dif = 3; dif >= -3; dif--) {
        if(dif==0) continue;
        vector<pair<int, int>> t;
        int x = a, y = b;
        // cout << x << " " << y << " asdf " << dif << endl;
        for(int i = 0; i < dif; i++) {
            t.push_back({25, 0});
            x-=25;
        }
        for(int i = 0; i < -dif; i++) {
            t.push_back({0, 25});
            y-=25;
        }
        for(int i = 0; i < 3-abs(dif); i++) {
            t.push_back({25, 0}); t.push_back({0, 25});
            x-=25; y-=25;
        }
        if(sz(t)==5) {
            if(dif>0) {t[3].first=15; x+=10; swap(t[3], t[4]);}
            else {t[4].second=15; y+=10;}
        }
        
        // cout << za << " " << zb << endl;
        
        //setup the differences
        int za = 0, zb = 0;
        while(za < sz(t) && t[za].first-2 <= t[za].second) za++;
        while(zb < sz(t) && t[zb].first >= t[zb].second-2) zb++;
        
        while(x-y > 0) {
            if(zb == sz(t)) goto sad;
            if(t[zb].first < t[zb].second-2) {t[zb].first++; x--;}
            while(zb < sz(t) && t[zb].first >= t[zb].second-2) zb++;
        }
 
        
        while(x-y < 0) {
            if(za == sz(t)) goto sad;
            if(t[za].first-2 > t[za].second) {t[za].second++; y--;}
            while(za < sz(t) && t[za].first-2 <= t[za].second) za++;
        }
        
        if(x-y != 0 || x < 0) goto sad;
 
        za = 0, zb = 0;
        while(za < sz(t) && t[za].first-2 <= t[za].second) za++;
        while(zb < sz(t) && t[zb].first >= t[zb].second-2) zb++;

        while(x > 0) {
            if(za == sz(t) || zb == sz(t)) break;
            if((t[zb].first < t[zb].second-2) && (t[za].first-2 > t[za].second)) {
                t[zb].first++; t[za].second++; x--; y--;
            }
            while(zb < sz(t) && t[zb].first >= t[zb].second-2) zb++;
            while(za < sz(t) && t[za].first-2 <= t[za].second) za++;
        }
 
        
        for(int i = 0; i < sz(t); i++) {
            if(abs(t[i].first - t[i].second)==2) {
                while(x) {
                    x--; y--;
                    t[i].first++; t[i].second++;
                }
            }
        }
 
        if(x==0 && y==0) {
            ans = t; ok = 1;
            break;
        }
 
        sad:
        ok = 0;
    }
 
    if(ok) {
        int r = 0, s = 0;
        for(int i = 0; i < sz(ans); i++) if(ans[i].first > ans[i].second) r++; else s++;
        cout << r << ":" << s << "\n";
        if(sz(ans)!=5) {
            sort(ans.begin(), ans.end(), [&](const auto& a, const auto& b) {return a.first-a.second < b.first-b.second;});
            if(r < s) reverse(ans.begin(), ans.end());
        }
        for(int i = 0; i < sz(ans); i++) cout << ans[i].first << ":" << ans[i].second << " ";
    } else cout << "Impossible";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    // int t = 1;
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