#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define f first
#define s second

#include <iostream>
#include <vector>
using namespace std;

/**
 * 2D Fenwick Tree implementation.
 * Note that all cell locations are zero-indexed
 * in this implementation.
 */
template <typename T> class BIT2D {
  private:
	const int n, m;
	vector<vector<T>> bit;

  public:
	BIT2D(int n, int m) : n(n), m(m), bit(n + 1, vector<T>(m + 1)) {}

	/** adds val to the point (r, c) */
	void add(int r, int c, T val) {
		r++, c++;
		for (; r <= n; r += r & -r) {
			for (int i = c; i <= m; i += i & -i) { bit[r][i] += val; }
		}
	}

	/** @returns sum of points with row in [0, r] and column in [0, c] */
	T rect_sum(int r, int c) {
		r++, c++;
		T sum = 0;
		for (; r > 0; r -= r & -r) {
			for (int i = c; i > 0; i -= i & -i) { sum += bit[r][i]; }
		}
		return sum;
	}

	/** @returns sum of points with row in [r1, r2] and column in [c1, c2] */
	T rect_sum(int r1, int c1, int r2, int c2) {
		return rect_sum(r2, c2) - rect_sum(r2, c1 - 1) - rect_sum(r1 - 1, c2) +
		       rect_sum(r1 - 1, c1 - 1);
	}
};

//sukon always reads the entire problem statement.
void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> a(n, vector<int>(n));
    for(auto &v : a) {
        for(auto& i : v) cin >> i;
    }

    for(auto &v : a) {
        for(auto &i : v) {
            int x; cin >> x;
            i-=x;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = n-1; j > 0; j--) {
            a[i][j] -= a[i][j-1];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = n-1; j > 0; j--) {
            a[j][i] -= a[j-1][i];
        }
    }

    BIT2D<int> bit(n, n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) if(a[i][j]) bit.add(i, j, 1);
    }

    auto upd = [&](int r, int c, int x) {
        if(r >= n) return;
        if(c >= n) return;
        bool before = a[r][c];
        a[r][c] += x;
        bool after = a[r][c];
        int dx = (int)after - (int)before;
        bit.add(r, c, dx);
        // cout << r << " " << c << " good " << endl;
    };


    for(int i = 0; i < q; i++) {
        // cout << "WHAT\n";
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) cout << bit.rect_sum(i, j, i, j) << " ";
        //     cout << endl;
        // }

        char c; cin >> c;
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        // cout << i << endl;
        if(c == 'U') {
            // cout << "asdf1" << endl;
            int x; cin >> x;
            upd(r2+1, c2+1, x);
            upd(r2+1, c1, -x);
            upd(r1, c2+1, -x);
            upd(r1, c1, x);
        } else {
            // cout << "asdf2" << endl;
            if(r1==r2 || c1==c2) {
                cout << "YES\n";
            } else {
                int s = bit.rect_sum(r1+1, c1+1, r2, c2);
                if(s) cout << "NO\n";
                else cout << "YES\n";
            }
        }

        
    }

}

//king of the sun o_O
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}

/* benq's 5 commandments
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */