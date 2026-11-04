#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    vector<set<int>> inds(26);

    int mm = 0;

    for(int i = 0; i < n; i++)
        inds[int(s[i]) - int('a')].insert(i);

    vector<int> p(n);
    for(int i = n-1; i >= 0; i--) {
        int num = int(t[i]) - int('a');

        if(i == n-1) {if(inds[num].upper_bound(i) == inds[num].begin()) {cout << -1; return;} 
        p[i] = *(--inds[num].end()); mm = i - p[i]; continue;}

        auto it = inds[num].upper_bound(min(i, p[i+1]));
        if(it == inds[num].begin()) {cout << -1; return;}
        it--;
        p[i] = *it;

        mm = max(mm, i-p[i]);
        // cout << mm << " " << i << " " << p[i] << endl;
        if(mm > k) {cout << -1; return;}
    }

    // for(int i = 0; i < n; i++) cout << i << " " << p[i] << endl;

    cout << mm;
    for(int i = 0; i < mm; i++) {
        assert(p[i] <= i);
        string st = s;
        for(int j = 0; j < n; j++) {
            if(p[j] < j) {
               p[j]++; st[j] = s[j-1];
            }    
        }
        s = st;

        cout << "\n" << s;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}