#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define a first
#define b second
const int mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int w, h, d, n;
	cin >> w >> h >> d >> n;
	int g = gcd(w, n);
	int wc = g - 1;
	n /= g;
	g = gcd(h, n);
	n /= g;
	int hc = g - 1;
	g = gcd(d, n);
	n /= g;
	int dc = g - 1;
	if (n == 1)
		cout << wc << " " << hc << " " << dc << "\n";
	else
		cout << "-1\n";
}