#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, k, l; cin >> n >> k >> l; k*=2; l*=2;
    vector<int> a(n); for(int &i : a) {cin >> i; i*=2;}

    int t = a[0];
    int c = k;
    a[0] = 0;

    for(int i = 1; i < n; i++) { //LOOK AT BOUNDS
        // cout << "asdf" << " " << n << endl;
        if(abs(a[i] - c) <= t) {
            a[i] = t; c += k;
        } else if(a[i] < c) {
            a[i] += t; c = a[i]+k;
        } else {
            a[i] -= t;
            int d = (a[i] - c)/2;
            if(l <= c+d) {
                t += l-c; break;
            }

            a[i] -= d;
            c = a[i]+k;
            t += d;
            // cout << t/2.0 << " " << d/2.0 << "\n";
        }

        if(c >= l) break;
    }

    if(c < l) {t += l-c;}

    cout << t;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}