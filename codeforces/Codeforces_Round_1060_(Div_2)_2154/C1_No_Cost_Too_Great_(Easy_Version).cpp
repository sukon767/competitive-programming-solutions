#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


int N = 2e5;
vector<int> fac;


int solve() {
    int n;  cin >> n;
    vector<vector<int>> as(n);
    vector<int> a(n), b(n);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;

    

    map<int, int>   pcnt;

    for(int i = 0; i < n; i++) {
        int k = a[i]; int prev = -1;
        
        while(fac[k]) {
            if(fac[k] != prev) {
                pcnt[fac[k]]++;
                as[i].push_back(fac[k]);
                if(pcnt[fac[k]] == 2)   {cout << 0; return 0;}

                prev = fac[k];
            }

            k/=fac[k];
        }
    }


    for(int i = 0; i < n; i++) {
        int k = a[i]+1; int prev = -1;
        for(int x : as[i])  pcnt[x]--;

        while(fac[k]) {
            if(fac[k] != prev) {
                

                if(pcnt[fac[k]])   {cout << 1; return 0;}

                prev = fac[k];
            }

            k/=fac[k];
        }


        for(int x : as[i])  pcnt[x]++;
    }

    cout << 2;
    return 0;
}

int main() {
    fac = vector<int>(N+1);
    for(int i = 2; i <= N; i++) {
    if(!fac[i])
        for(int j = i; j <= N; j+=i) {
            if(!fac[j]) fac[j] = i;
        }
    }

    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}