// CutSandstone always reads the entire problem statement.
#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;
using ll = long long;
const ll oo = 1e18;
template <class T> T uMin(T &a, T b) { return a = min(a, b); }
template <class T> T uMax(T &a, T b) { return a = max(a, b); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;
    cin >> t;
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (t == "Encode") {
        int ind = 0;
        for (int i = 1; i < n; i++)
            if (s[i] != s[0]) {
                ind = i;
                break;
            }
        for (int i = 0; i < ind; i++)
            s[i] = '2';
        cout << s << "\n";
    } else {
        int ind = -1;
        for (int i = 0; i < n; i++)
            if (s[i] != '2' && s[(i + 1) % n] == '2') {
                ind = i;
                break;
            }
        if (ind != -1) {
            if (ind != n - 1)
                rotate(s.begin(), s.begin() + ind + 1, s.end());
            int x = 0;
            while (s[x] == '2')
                x++;
            for (int i = 0; i < x; i++)
                s[i] = '1' + '0' - s[x];
        }
        cout << s << "\n";
    }
}