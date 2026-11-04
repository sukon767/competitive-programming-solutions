#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
#define sz(x) (int)(x).size()

int n;
vector<int> z, mini;

//changed [0, n].
void add(int k, int p, int q, int i = 1, int l = 0, int r = n) {
    if(p <= l && r <= q) {
        z[i] += k;
        mini[i] += k;
        return;
    }

    int m = (l+r)>>1;
    //propagate
    z[i<<1] += z[i]; z[i<<1|1] += z[i];
    mini[i<<1] += z[i]; mini[i<<1|1] += z[i];
    z[i] = 0;

    if(p <= m) add(k, p, q, i<<1, l, m);
    if(m+1 <= q) add(k, p, q, i<<1|1, m+1, r);

    mini[i] = min(mini[i<<1], mini[i<<1|1]);
}
 
int query(int i = 1, int l = 0, int r = n) {
    if(l == r) {
        if(mini[i] <= 0) return l;
        else return l+1;
    }
    //propagate
    z[i<<1]+=z[i]; z[i<<1|1]+=z[i];
    mini[i<<1] += z[i]; mini[i<<1|1] += z[i];
    z[i] = 0;

    int m = (l+r)>>1;

    if(mini[i<<1] <= 0) {
        return query(i<<1, l, m);
    }
    return query(i<<1|1, m+1, r);
}

 
void solve() {
    cin >> n;
    vector<int> a(n);
    for(int &i : a) {cin >> i; i = min(i, 2*n+1);}
 
    z = mini = vector<int>(4*(n+1)+1);
    
    int ans = 0;
    vector<int> f(2*n+2);

    for(int i = 0; i < n; i++) {
        if(f[a[i]] || a[i] >= ans) {
            //just range add 1 from 0 to (a[i]-1)/2
            add(1, 0, min(n, (a[i]-1)/2));
        } else {
            // cout << endl << i << endl;
            //range add 1 from 0 to a[i].
            add(1, 0, min(n, a[i]));
        }
        f[a[i]]++;

        while(ans < n) {
            int f0 = query();
            // cout << endl << i << " " << ans << " " << f0 << " " << f[ans] <<endl;
            if(!f[ans]) {
                if(f0 > ans) {
                    add(-1, 0, ans);
                } else break;
            } else {
                if(f0 > (ans-1)/2) {
                    add(-1, 0, min(n, (ans-1)/2));
                } else break;
            }
            ans++;
        }

        cout << ans << " ";
    }
}
 
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
 
 /* new testament
 * nick belov always reads the entire problem statement.
 */
