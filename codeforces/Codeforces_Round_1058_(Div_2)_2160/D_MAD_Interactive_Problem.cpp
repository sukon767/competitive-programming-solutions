#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int> a(2*n);
    vector<bool> quer(2*n, false);
    quer[0] = true;
    int cnt = 1;
    for(int i = 1; i < 2*n; i++) {
        quer[i] = true;
        cnt++;
        cout << "? " << cnt;
        for(int j = 0; j < 2*n; j++)
            if(quer[j])
                cout << " " << (j+1);

        cout << endl << flush;

        int anser;
        cin >> anser;
        if(anser) {
            a[i] = anser;
            quer[i] = false;
            cnt--;
        }
    }

    cnt = 0;
    for(int i = 0; i < 2*n; i++) {
        if(a[i]) {
            cnt++;
        }
        quer[i] = a[i];
    }


    for(int i = 2*n-1; i >= 0; i--) {
        if(quer[i]) continue;

        quer[i] = true;
        cnt++;
        cout << "? " << cnt;
        for(int j = 0; j < 2*n; j++)
            if(quer[j])
                cout << " " << (j+1);

        cout << endl << flush;

        int anser;
        cin >> anser;
        if(anser) {
            a[i] = anser;
            quer[i] = false; cnt--;
        }
    }

    cout << "!";
    for(int i = 0; i < 2*n; i++)
        cout << " " << a[i];
    

    cout << endl << flush;



}

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}