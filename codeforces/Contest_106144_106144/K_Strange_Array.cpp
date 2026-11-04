#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); }
	};
	vector<int> lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, (int)adj[b].size(), c, c});
		adj[b].push_back({a, (int)adj[a].size() - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < adj[v].size(); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0;
		q[0] = s;
		for (int L = 0; L < 31; L++) do {
				lvl = ptr = vector<int>(q.size());
				int qi = 0, qe = lvl[s] = 1;
				while (qi < qe && !lvl[t]) {
					int v = q[qi++];
					for (Edge e : adj[v])
						if (!lvl[e.to] && e.c >> (30 - L))
							q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
				}
				while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
			} while (lvl[t]);
		return flow;
	}
	bool minCutSourceSide(int a) { return lvl[a] != 0; }
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// int t;
	// cin >> t;
	// while (t--) {
	// 	int n;
	// 	cin >> n;
	// 	string s;
	// 	cin >> s;
	// 	if (s[0] == ')' and s.back() == ')') {
	// 		cout << "Polycarp" << '\n';
	// 	} else {
	// 		int ignore = (s[0] == '(' ? 0 : n - 1);
	// 		deque<char> q;
	// 		for (int i = 0; i < n; i++) {
	// 			if (ignore == i) continue;
	// 			q.push_back(s[i]);
	// 		}
	// 		int bal = 1;
	// 		int turn = 1;
	// 		bool g = 0;
	// 		auto Upd = [&](char c) -> void {
	// 			if (c == ')') {
	// 				bal--;
	// 			} else {
	// 				bal++;
	// 			}
	// 		};
	// 		while (!q.empty()) {
	// 			char f = q.front();
	// 			char b = q.back();
	// 			// 0 for front, 1 for back
	// 			if (turn == 1) {
	// 				int P = 0;
	// 				if (q.front() == '(') P = 1;
	// 				if (!P) {
	// 					q.pop_front();
	// 				} else {
	// 					q.pop_back();
	// 				}
	// 			} else {
	// 				int M = 0;
	// 				if (q.front() == '(') M = 1;
	// 				if (!M) {
	// 					q.pop_front();
	// 					Upd(f);
	// 				} else {
	// 					q.pop_back();
	// 					Upd(b);
	// 				}
	// 			}
	// 			if (bal == 0) {
	// 				g = 1;
	// 				break;
	// 			}
	// 			turn ^= 1;
	// 		}
	// 		cout << (!g ? "Polycarp" : "Monocarp") << '\n';
	// 	}
	// }
	int n, k, m;
	cin >> n >> k >> m;
	vector<vector<int>> r(m, vector<int>(3));
	for (auto& a : r) {
		cin >> a[0] >> a[1] >> a[2];
		a[0]--, a[1]--;
	}
	vector<int> ans(n + 1);
	const int BIT = 30;
	for (int b = 0; b < BIT; b++) {
		vector<int> d(n + 1, -1);
		function<int(int)> get = [&](int x) {
			return d[x] < 0 ? x : d[x] = get(d[x]);
		};
		int cc = n + 1;
		for (auto& a : r)
			if ((a[2] >> b) & 1) {
				int x = get(a[0]), y = get(a[1] + 1);
				if (x == y) continue;
				if (d[x] > d[y]) swap(x, y);
				d[x] += d[y];
				d[y] = x;
				cc--;
			}
		if (cc > 1) {
			for (int i = 0; i <= n; i++)
				if (get(i) != get(0)) ans[i] ^= 1 << b;
			continue;
		}
		int best = -1, f = INT_MAX;
		for (int i = 1; i <= n; i++) {
			Dinic d(n + 1);
			for (auto& a : r)
				if ((a[2] >> b) & 1) d.addEdge(a[0], a[1] + 1, 1, 1);
			int flow = d.calc(0, i);
			if (flow < f) {
				f = flow;
				best = i;
			}
		}
		if (f < k) {
			Dinic d(n + 1);
			for (auto& a : r)
				if ((a[2] >> b) & 1) d.addEdge(a[0], a[1] + 1, 1, 1);
			assert(f == d.calc(0, best));
			for (int i = 1; i <= n; i++)
				if (!d.minCutSourceSide(i)) ans[i] ^= 1 << b;
		}
	}
	for (int i = 1; i <= n; i++) cout << (ans[i] ^ ans[i - 1]) << " ";
	cout << "\n";
}