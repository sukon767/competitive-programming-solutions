#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int solve() {
    int n; cin >> n;
    // map<>
    vector<pair<int, int>> scores;

    int tscore = 0;
// cout << "asdf\n";
    for(int i = 0; i <n; i++) {
        int sum = 0;
        for(int i = 0; i < 4; i++) {
            int a; cin >> a;
            sum+=a;
        }
        if(!i)  tscore = sum;
        scores.push_back({sum, i+1});
    }

    // cout << "asdf\n";

    sort(scores.begin(), scores.end());

    int rank = 0;
    int i = n-1;
    while(i >= 0 && scores[i].first!=tscore) {
        rank++; i--;
    }
    // cout << "asdf\n";
    
    while(i>=0 && scores[i].first == tscore)
        i--;

        // cout << "asdf\n";
    
    i++; rank++;

    // cout << rank << " " << i << "\n";

    // for(int i = 0; i < n; i++)
    //     cout << scores[i].first << " " << scores[i].second << " " << tscore << "\n";

    while(scores[i].second != 1)   {     i++; rank++;}

    cout << rank;


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