#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, k, p, m; cin >> n >> k >> p >> m;
    p--;
    vector<int> cyc;
    multiset<int> cur;
    vector<int> a(n); for(int &i : a) cin >> i;
    vector<vector<int>> left(m+1);

    for(int i = 0; i < n; i++) if(i != p) left[a[i]].push_back(i);
    for(int i = 0; i < k; i++) cur.insert(a[i]);

    bool did = false;
    for(int i = k-1; i < n; i++) {
        // cout << i << endl;
        if(!did && p <= i) {
            cyc.push_back(p);
            cur.erase(cur.find(a[p]));
            did = true;
        } else {
            int cont = left[*cur.begin()].back();
            left[*cur.begin()].pop_back();

            cyc.push_back(cont);
            cur.erase(cur.begin());
        }

        if(i+1 < n) cur.insert(a[i+1]);
    }

    int x = 0;
    int pd = 0;

    for(int i = 0; i < cyc.size(); i++) {
        pd += a[cyc[i]];
    }

    x += m/pd;
    m -= m/pd*pd;
    for(int i = 0; i < cyc.size(); i++) {
        if(m < a[cyc[i]]) break;
        if(cyc[i] == p) x++;
        m -= a[cyc[i]];
    }


    cout << x;



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