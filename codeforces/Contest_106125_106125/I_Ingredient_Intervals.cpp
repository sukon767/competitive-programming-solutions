#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

/*
dp[i] = it is possible to make intervals of size >= k up to i
iterate the right endpoint
iterate the left endpoint
for all intervals of size >=k that can be made valid
interval -> [j, i]
take any such dp[j-1] and set dp[i] = dp[j-1]
how to find interval?
iterate right endpoint, iterate left starting at i-k+1
while everyone inside can be put inside it is good
dp[0] = true
dp[i] = false
iterate all valid max intervlas starting from
i-k+1 to 0
24 * 1000 * 1000 * log(1000)

maintain set of transpositions s.t. it lands in interval
keep expanding window while there is nonoverlap

*/
#define a first
#define b second
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<string> s;
	vector<double> v;
	string t;
	getline(cin, t);
	for (int i = 0; i < n; i++) {
		getline(cin, t);
		auto ind = t.find(' ');
		if (ind == string::npos) {
			s.push_back(t);
			v.push_back(-1);
		} else {
			s.push_back(t.substr(0, ind));
			v.push_back(stod(t.substr(ind + 1)) / 100);
		}
	}
	vector<pair<double, int>> r{{1, -1}};
	for (int i = 0; i < n; i++)
		if (v[i] != -1) r.push_back({v[i], i});
	r.push_back({0, n});
	double smin = 0, smax = -1;
	for (int i = 1; i < r.size(); i++) {
		smin += r[i].a * (r[i].b - r[i - 1].b);
		smax += r[i - 1].a * (r[i].b - r[i - 1].b);
	}
	cout << fixed << setprecision(6);
	for (int i = 1; i < r.size(); i++) {
		double curMn = r[i].a * (r[i].b - r[i - 1].b - 1);
		double curMx = r[i - 1].a * (r[i].b - r[i - 1].b - 1);
		smin -= curMn;
		smax -= curMx;
		for (int j = r[i - 1].b + 1; j < r[i].b; j++) {
			int cntHigh = j - r[i - 1].b - 1;
			int cntLow = r[i].b - j - 1;
			cout << s[j] << " "
				 << max(r[i].a,
						(1 - smax - r[i - 1].a * cntHigh) / (cntLow + 1)) *
						100
				 << " "
				 << min(r[i - 1].a,
						(1 - smin - r[i].a * cntLow) / (cntHigh + 1)) *
						100
				 << "\n";
		}
		smin += curMn;
		smax += curMx;
	}
}