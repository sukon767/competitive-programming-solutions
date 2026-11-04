#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
using ll = long long;
const int MAXN = 1e5;
int ret[2 * MAXN];
map<int, int> g[MAXN];
int t[MAXN];
bool vis[MAXN];
int cnt = 0;
int n;
int w = MAXN * 2 + 1;
bool dfs(int s) {
  cnt++;
  vis[s] = 1;
  while (g[s].size()) {
    if (cnt == n || g[s].find(t[cnt]) == g[s].end()) {
      for (auto &a : g[s])
        if (!vis[a.a])
          return 0;
      break;
    }
    ret[g[s][t[cnt]]] = w--;
    g[s].erase(t[cnt]);
    if (!dfs(t[cnt]))
      return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[--a][--b] = i;
    g[b][a] = i;
  }
  for (int i = 0; i < n; i++)
    cin >> t[i], t[i]--;
  fill(ret, ret + m, 1);
  if (t[0] != 0 || !dfs(0))
    cout << "impossible\n";
  else {
    for (int i = 0; i < m; i++)
      cout << ret[i] << " ";
    cout << "\n";
  }
}