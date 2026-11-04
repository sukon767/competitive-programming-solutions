#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;

    vector<vector<int>> dumb = 
    {    {8, 9, 1, 13},
        {3, 12, 7, 5},
        {0, 2, 4, 11},
        {6, 10, 15, 14}};

    vector<vector<int>> g(n, vector<int>(n));

    for(int i = 0; i < n/4; i++)
        for(int j = 0; j < n/4; j++)
            for(int x = 0; x < 4; x++)
                for(int y = 0; y < 4; y++) {
                    // cout << i + (n/4)*x << " " << j+ (n/4)*y  << endl;
                    // return;
                    g[i + (n/4)*x][j+ (n/4)*y] = 16*(i*(n/4) + j) +dumb[x][y];
                }

    // int check1 = 0;
    // for(int i = 0; i < n; i++)
    //             check1 ^= g[3][i];

    //             int check2 = 0;
    // for(int i = 0; i < n; i++)
    //             check2 ^= g[i][2];

    // cout << check1 << " " << check2 << "\n";

    for(int i = 0; i < n; i++) {
        if(i)   cout << "\n";
        for(int j = 0; j < n; j++) {
            if(j)   cout << " ";
            cout << g[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}