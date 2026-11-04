#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> left, right;
    vector<int> stk;
    for(int &i : a) cin >> i;

    for(int i = 0; i < n; i++) {
        if((!i || a[i-1] > a[i]) && (i == n-1 || a[i] < a[i+1])) {
            //ditch
            // cout << i << endl;
            left.push_back(stk.size());
        }
        while(stk.size() && stk.back() < a[i]) stk.pop_back();
        stk.push_back(a[i]);
    }

    stk.clear();

    for(int i = n-1; i >= 0; i--) {
        if((!i || a[i-1] > a[i]) && (i == n-1 || a[i] < a[i+1])) {
            //ditch
            // cout << i << endl;
            right.push_back(stk.size());
        }
        while(stk.size() && stk.back() < a[i]) stk.pop_back();
        stk.push_back(a[i]);
    }

    int ans = 0;
    for(int i = 0; i < left.size(); i++) {
        ans = max(ans, left[i] + right[int(right.size())-1-i]);
    }

    // cout << "left" << " ";
    // for(int x : left) cout << x << " ";
    // cout << endl << "right" << " ";
    // for(int x : right) cout << x << " ";
    // cout << endl;

    // for(int i = 0)

    cout << n - ans-1;
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