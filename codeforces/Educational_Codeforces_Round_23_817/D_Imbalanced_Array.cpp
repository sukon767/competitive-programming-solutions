#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<ll> a(n);
    vector<pair<int, int>> m1(n, {0, n-1}), m2(n, {0, n-1});

    for(ll &i : a) cin >> i;
    vector<int> stk1, stk2;
    for(int i = 0; i < n; i++) {
        
        while(stk1.size() && a[stk1.back()] < a[i]) stk1.pop_back();
        while(stk2.size() && a[stk2.back()] > a[i]) stk2.pop_back();

        // if(stk1.size()) cout << i << " " << stk1.back() << endl;


        if(stk1.size()) m1[i].first = stk1.back()+1;
        if(stk2.size()) m2[i].first = stk2.back()+1;

        stk1.push_back(i), stk2.push_back(i);
    }

    stk1.clear(), stk2.clear();
    for(int i = n-1; i >=0; i--) {
        while(stk1.size() && a[stk1.back()] <= a[i]) stk1.pop_back();
        while(stk2.size() && a[stk2.back()] >= a[i]) stk2.pop_back();

        if(stk1.size()) m1[i].second = stk1.back()-1;
        if(stk2.size()) m2[i].second = stk2.back()-1;

        stk1.push_back(i), stk2.push_back(i);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += a[i]*(m1[i].second-i+1)*(i-m1[i].first+1);
        ans -= a[i]*(m2[i].second-i+1)*(i-m2[i].first+1);

        // cout << i << " " << m1[i].first << " " << m1[i].second << endl;
        // cout << i << " " << m2[i].first << " " << m2[i].second << endl;
    }

    cout << ans;

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