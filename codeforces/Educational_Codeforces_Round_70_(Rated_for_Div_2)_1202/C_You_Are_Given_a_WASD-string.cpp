#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> x, y;
    x = y = {0};
    
    for(int i = 0; i < n; i++) {
        if(s[i] == 'W') y.push_back(y.back() + 1);
        if(s[i] == 'A') x.push_back(x.back() + 1);
        if(s[i] == 'S') y.push_back(y.back() - 1);
        if(s[i] == 'D') x.push_back(x.back() - 1);
    }
    bool widthDown = false, heightDown = false;

    int firstmin = 0, lastmax = 0;
    int maxer = INT_MIN; int miner = INT_MAX;
    for(int i = 0; i < x.size(); i++) {
        if(x[i] >= maxer) {
            lastmax = i;
            if(x[i] > maxer) {maxer = x[i];}
        }

        if(x[i] < miner) {
            firstmin = i;
            {miner = x[i];}
        }
    }
    int width = maxer - miner +1;
    widthDown |= (lastmax+1 < firstmin);

        // cout << lastmax << " " << firstmin << endl;


    for(int &i : x)  i*=-1;

    firstmin = 0, lastmax = 0;
    maxer = INT_MIN; miner = INT_MAX;
    for(int i = 0; i < x.size(); i++) {
        if(x[i] >= maxer) {
            lastmax = i;
            if(x[i] > maxer) {maxer = x[i];}
        }

        if(x[i] < miner) {
            firstmin = i;
            {miner = x[i];}
        }
    }
    widthDown |= (lastmax+1 < firstmin);

//

    firstmin = 0, lastmax = 0;
    maxer = INT_MIN; miner = INT_MAX;
    for(int i = 0; i < y.size(); i++) {
        if(y[i] >= maxer) {
            lastmax = i;
            if(y[i] > maxer) {maxer = y[i];}
        }

        if(y[i] < miner) {
            firstmin = i;
            {miner = y[i];}
        }
    }
    int height = maxer - miner +1;
    heightDown |= (lastmax+1 < firstmin);


    for(int &i : y)  i*=-1;

    firstmin = 0, lastmax = 0;
    maxer = INT_MIN; miner = INT_MAX;
    for(int i = 0; i < y.size(); i++) {
        if(y[i] >= maxer) {
            lastmax = i;
            if(y[i] > maxer) {maxer = y[i];}
        }

        if(y[i] < miner) {
            firstmin = i;
            {miner = y[i];}
        }
    }
    heightDown |= (lastmax+1 < firstmin);
        // cout << firstmin << " " << lastmax << endl;
        // for(int i : y)  cout << i << endl;








    ll ans = ll(height)*width;
    if(widthDown) ans = min(ans, ll(height)*(width-1));
    if(heightDown) ans = min(ans, ll(height-1)*(width));


    
    cout << ans;
    // cout << endl << widthDown << " " << heightDown;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    // int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}