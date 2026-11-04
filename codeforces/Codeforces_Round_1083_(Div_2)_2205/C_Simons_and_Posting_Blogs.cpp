#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n);
    for(auto &i : a) {
        int li; cin >> li;
        i = vector<int>(li);
        for(auto &j : i) cin >> j;
        vector<int> t;
        map<int, bool> temp;

        for(int j = int(i.size())-1; j >= 0; j--) {
            if(!temp[i[j]]) t.push_back(i[j]);
            temp[i[j]] = true;
        }
        i = t;
    }
    // for(int i = 0; i < n; i++) {
    //     cout << i+1 << endl;
    //     for(int x : a[i]) cout <<x  << " ";
    //     cout << endl;
    // }

    
    vector<int> ans;
    vector<bool> doneNum(1e6);
    while(a.size()) {
        sort(a.begin(), a.end(), [&](auto &x, auto &y) {
            int l = 0, r = 0;
            while(l < x.size() && r < y.size()) {
                while(l < x.size() && doneNum[x[l]]) l++;
                while(r < y.size() && doneNum[y[r]]) r++;
                if(!(l < x.size() && r < y.size())) break;
                if(x[l] < y[r]) return true;
                else if(y[r] < x[l]) return false;
                l++, r++;
            }
            if(l < x.size()) return false;
            else if(r < y.size()) return true;
            else return false;
        });

        for(int x : a.front()) {
            if(!doneNum[x]) ans.push_back(x);
            doneNum[x] = true;
        }

        reverse(a.begin(), a.end());
        a.pop_back();
    }

    for(int x : ans) cout << x << " ";
    



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