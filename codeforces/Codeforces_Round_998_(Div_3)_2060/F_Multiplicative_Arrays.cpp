#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
struct mi {
  ll v;
  explicit operator ll() const { return v; }
  mi() { v = 0; }
  mi(ll _v) : v(_v % MOD) { v += (v < 0) * MOD; }
  bool operator<(const mi& other) const {
    return v < other.v;
  }
  friend std::ostream& operator<<(std::ostream& os, const mi& m) {
      os << m.v;
      return os;
  }
};
mi &operator+=(mi &a, mi b) {
  if ((a.v += b.v) >= MOD) a.v -= MOD;
  return a;
}
mi &operator-=(mi &a, mi b) {
  if ((a.v -= b.v) < 0) a.v += MOD;
  return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi(a.v * ll(b.v)); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, ll p) {
  assert(p >= 0);
  return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
  assert(a.v != 0);
  return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }
mi& operator/=(mi& a, mi b) { return a = a/b; }
bool operator==(mi a, mi b) {return a.v == b.v;}
bool operator!=(mi a, mi b) {return a.v != b.v;}


ll k;
vector<ll> fac;

vector<pair<ll, ll>> pf(ll N) {
    ll k = N;
    long prev = 1;
    vector<pair<ll, ll>> peList;
    while(fac[k]) {
        if(fac[k] != prev) {
            peList.push_back({fac[k], 1});
            prev = fac[k];
        } else
            peList[peList.size() - 1].second++;
        k /= fac[k];
    }

    return peList;
}

int main() {
    ll t;
    cin >> t; vector<vector<mi>> ans;

    for(int d = 0; d < t; d++) {
        ll n;
        cin >> k >> n;
        
        ans.push_back({n});

        fac = vector<ll>(k+1);
        for(ll i = 2; i <= k; i++)
        if(!fac[i])
            for(ll j = i; j <= k; j += i)
                fac[j] = i;
        
        for(ll x = 2; x <= k; x++) {
            mi Ans = 0;

            vector<pair<ll, ll>> pfi = pf(x);
            ll esum = 0;
            for(pair<ll, ll> pe : pfi)
                esum += pe.second;

            vector<mi> cumu(1);
            for(ll s = 1; s <= min(n, esum); s++) {
                for(ll i = 1; i < cumu.size(); i++) {
                    cumu[i]*= s; cumu[i]/=s-i; }
                
                mi snew = 1;
                for(pair<ll, ll> pe : pfi) {
                    ll e = pe.second;
                    //s-1+e choose e
                    for(ll j = 1; j <= e; j++) {
                        snew *= s-1+j; snew /= j; }
                }
                
                //cout << snew << " " << x << " " << s << " " <<  " " << esum << "\n";

                for(mi sub : cumu)
                    snew -= sub;

                cumu.push_back(snew);

                //cout << snew << " " << x << " " << s << " " <<  " " << esum << "\n";

                for(ll j = 0; j < s+1; j++) {
                    snew *= n+1-j; snew/= s+1-j;
                    //cout << n+1-j << " " << s+1-j << " " << snew << "\n";
                    }
                Ans += snew;

                //cout << snew << " " << x << " " << "\n";

            }

            ans[d].push_back(Ans);
        
        }

        
    }

    for(int i = 0; i < t-1; i++) {
        for(int j = 0; j < ans[i].size() - 1; j++)
            cout << ans[i][j] << " ";
        cout << ans[i][ans[i].size() -1] << "\n";
    }

    for(int j = 0; j < ans[t - 1].size() - 1; j++)
            cout << ans[t - 1][j] << " ";
    cout << ans[t-1][ans[t-1].size() -1];
}