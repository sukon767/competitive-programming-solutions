#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    map<int, vector<int>>    notate;

    // cout << "asdf\n";

    for(int i = 0; i < n; i++) {
        if(!notate[a[i]].size())
            for(int j = 0; j < 3; j++)
                notate[a[i]].push_back(-1);

        // cout << "asdf\n";

        notate[a[i]][0]++;
        // cout << "asdf\n";

        if(notate[a[i]][1] == -1) notate[a[i]][1] = i+1;

        // cout << "asdf\n";
        notate[a[i]][2] = i+1;

        // cout << "asdf\n";
    }

        // cout << "asdf\n";


    int max = 0;
    int minSize = n+1;
    int l = 0;
    int r = 0;
    for(auto it : notate) {
        if(max < it.second[0]) {
            max = it.second[0];
            minSize = it.second[2] - it.second[1] + 1;
            l = it.second[1];
            r = it.second[2];
        } else if(max == it.second[0]) {
            if(minSize >    it.second[2] - it.second[1] + 1) {
                minSize = it.second[2] - it.second[1] + 1;
                l = it.second[1];
                r = it.second[2];
            }
        }

    }

    cout << l << " " << r;
        


    return 0;
}

int main() {
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}