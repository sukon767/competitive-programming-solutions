#include "bits/stdc++.h"
using namespace std;
#define int int64_t

template <int MOD>
struct Mint {
  int v;

  Mint(int64_t x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}
 
  friend Mint pow(Mint base, int64_t exp) {
    Mint res = 1;
    while (exp) {
      if (exp & 1) {
        res *= base;
      }
      base *= base;
      exp >>= 1;
    }
    return res;
  }

  Mint &operator+=(Mint b) {
    v = v + b.v - (v + b.v >= MOD) * MOD;
    return *this;
  }
  Mint &operator-=(Mint b) {
    v = v - b.v + (v < b.v) * MOD;
    return *this;
  }
  Mint &operator*=(Mint b) {
    v = int(1ll * v * b.v % MOD);
    return *this;
  }
  Mint &operator/=(Mint b) {
    v = int(1ll * v * pow(b, MOD - 2).v % MOD);
    return *this;
  }
  friend Mint operator+(Mint a, Mint b) {
    return a += b;
  }
  friend Mint operator-(Mint a, Mint b) {
    return a -= b;
  }
  friend Mint operator*(Mint a, Mint b) {
    return a *= b;
  }
  friend Mint operator/(Mint a, Mint b) {
    return a /= b;
  }
  friend ostream &operator<<(ostream &os, Mint a) {
    return os << a.v;
  }
};

using mi = Mint<998244353>;

vector<vector<mi>> cache(300005);
vector<mi> recans(int n){
    if (cache[n].size()>0){
        return cache[n];
    }
    if (n==1){
        cache[n]={1};
        return cache[n];
    }

    if (n<=6){
        vector<mi> ret(n);
        for (int i=0;i<n;i++){
            ret[i]=(mi(1)/n);
        }
        cache[n]=ret;
        return cache[n];
    }
    assert(n>6);
    vector<mi> ret(n);
    mi inv = mi(1)/6;
    for (int q=0;q<6;q++){
        vector<int> cur;
        for (int i=0;i<n;i++){
            if (i%6==q){
                continue;
            }
            cur.push_back(i);
        }
        vector<mi> pp=recans(cur.size());
        for (int i=0;i<pp.size();i++){
            ret[cur[i]]+=inv*pp[i];
        }
    }
    cache[n]=ret;
    return cache[n];

}
void setup(){
}

void solve(){
    int n;
    cin>>n;
    for (mi i:recans(n)){
        cout<<i.v<<"\n";
    }

}

signed main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int t=1;
    
    //cin>>t;
 
    setup();
    while (t--){
        solve();
    }
}

//What would Chika do?
//What would Chika do?
//What would Chika do?
//What would Chika do?
//What would Chika do?