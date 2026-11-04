#include <bits/stdc++.h>
using namespace std;
void boos() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define pb push_back
#define en '\n'
const int N = 1e4 + 10;
int n;
const int denom[9] = {1,2,5,10,20,50,100,200,500};
bool achievable[N];
void solve() {
    cin >> n;
    if(n % 2) {
        cout << n << en;
        for(int i = 1;i <= n;i++) {
            cout << 1 << " ";
        }
        return;
    }
    int original_n = n;
    vector <int> split;
    if(n >= 500) {
        int k_500 = (n / 500);
        int k_200 = (n / 200);
        if(k_500 % 2 == 0 && k_200 % 2) {
            while(n >= 200) {
                split.pb(200);
                n -= 200;
            }
        }
    }
    while(n > 0) {
        for(int i = 8;i >= 0;i--) {
            if(n >= denom[i])  {
                split.pb(denom[i]);
                n -= denom[i];
                break;
            }
        }
    }
    achievable[0] = 1;
    for(auto s : split) {
        for(int m = original_n; m >= 0;m--) {
            if(achievable[m]) {
                achievable[m + s] = 1;
            }
        }
    }
    if(achievable[original_n / 2]) {
        cout << "splittable";
        return;
    }
    cout << split.size() << en;
    for(auto s : split) {
        cout << s << " ";
    }

}

int main() {
    solve();
}
