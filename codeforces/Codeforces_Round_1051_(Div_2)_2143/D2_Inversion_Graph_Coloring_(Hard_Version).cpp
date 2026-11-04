#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int mod = 1e9+7;


template <class T> class BIT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	BIT(int size) : size(size), bit(size + 1), arr(size) {}

	/** Sets the value at index ind to val. */
	void set(int ind, T val) { add(ind, val - arr[ind]); }

	/** Adds val to the element at index ind. */
	void add(int ind, T val) {
		arr[ind] = (arr[ind] + val)%mod;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] = (bit[ind]+val)%mod; }
	}

	/** @return The sum of all values in [0, ind]. */
	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total = (total+bit[ind])%mod; }
		return total;
	}
};

vector<BIT<int>> rc;
int n;


void solve() {
    cin >> n;
    vector<int> a(n); for(int &i : a) cin >> i;

    rc = vector<BIT<int>>(2*(n+1), BIT<int>(n+1));
    rc[0].add(0, 1); rc[n+1].add(0, 1);
    vector<int> ku(n+1), ju(n+1);
    for(int i = 0; i < n; i++) {
        fill(ku.begin(), ku.end(), 0); fill(ju.begin(), ju.end(), 0); 
        for(int k = 0; k <= a[i]; k++) ku[k] = rc[n+1+k].pref_sum(a[i])- (k-1 ? rc[n+1+k].pref_sum(k-1) : 0);
        for(int j = a[i]+1; j <= n; j++) ju[j] = rc[j].pref_sum(a[i]);
        for(int k = 0; k <= n; k++) {rc[a[i]].add(k, ku[k]); rc[n+1+k].add(a[i], ku[k]);}
        for(int j = 0; j <= n; j++) {rc[j].add(a[i], ju[j]); rc[n+1+a[i]].add(j, ju[j]);}
    }
    
    int ans = 0;
    for(int j = 0; j <= n; j++)
        ans = (ans+rc[j].pref_sum(n))%mod;
    
    cout << ans;
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}