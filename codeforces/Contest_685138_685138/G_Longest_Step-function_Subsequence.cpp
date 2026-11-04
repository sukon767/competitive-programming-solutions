#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;
    map<int, int> cnt1, cnt2;
    set<pair<int, int>> c1, c2;
    int ans = 0;
    for(int i = 0; i < n; i++) cnt2[a[i]]++;

    for(auto &p : cnt2) {
        c2.insert({p.second, p.first});
    }

    for(int i = 0; i < n; i++) {
        
        //update {cnt1[a[i]], a[i]}
        if(c1.find({cnt1[a[i]], a[i]}) != c1.end()) c1.erase(c1.find({cnt1[a[i]], a[i]}));
        cnt1[a[i]]++;
        c1.insert({cnt1[a[i]], a[i]});

        if(c2.find({cnt2[a[i]], a[i]}) != c2.end()) c2.erase(c2.find({cnt2[a[i]], a[i]}));
        cnt2[a[i]]--;
        c2.insert({cnt2[a[i]], a[i]});

        // cout << "asdf" << endl;


        auto p1 = prev(c1.end()), p2 = prev(c2.end());
        if((*p1).second != (*p2).second && (*p1).first && (*p2).first) {

            // cout << (*p1).second << " " << (*p1).first << " " << (*p2).second << " " << (*p2).first << endl;
            
            ans = max(ans, (*p1).first + (*p2).first);

            // cout << ans << endl;
        }

        if(cnt1.size() >= 2) {
            auto p11 = prev(p1);
            if((*p11).second != (*p2).second && (*p11).first && (*p2).first) {
                ans = max(ans, (*p11).first + (*p2).first);
            }
        }

        if(cnt2.size() >= 2) {
            auto p22 = prev(p2);
            if((*p1).second != (*p22).second && (*p1).first && (*p22).first) {
                ans = max(ans, (*p1).first + (*p22).first);
            }
        }
        // cout << i << " " << ans << endl;
    }

    cout << ans;
}
 
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