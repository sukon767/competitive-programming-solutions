#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> u(n);
    for (int i = 0; i < n; i++)
      u[i] = s[i] == 'u' ? i : i ? u[i - 1] : -1;
    vector<int> cu(n), cs(n);
    for (int i = 0; i < n; i++) {
      cu[i] = s[i] == 'u';
      cs[i] = s[i] == 's';
    }
    partial_sum(cu.begin(), cu.end(), cu.begin());
    partial_sum(cs.begin(), cs.end(), cs.begin());
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      int len = i - u[i];
      int x = u[i];
      int y = x - len;
      int z = y - len;
      if (z >= -1 && cs[x] == cs[y] && cu[y] == (z == -1 ? 0 : cu[z]))
        dp[i] = (z == -1 ? 0 : dp[z]) + (i - z);
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
  }
}