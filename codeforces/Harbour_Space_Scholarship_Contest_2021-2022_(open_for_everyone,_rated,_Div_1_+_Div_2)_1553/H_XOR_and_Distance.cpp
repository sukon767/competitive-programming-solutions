#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

vector<int> mind, mi, ma;
vector<bool> s;
vector<bool> a;
int n, k;

int reverse(int n) {
    int ans = 0;
    for(int i = 0; i < k; i++) {
        if(n&(1<<i)) ans |= (1<<(k-1-i));
    }

    return ans;
}

void build(int i = 1, int d = 0) {
    if(d == k) {int l = i ^ (1<<k); if(a[l]) {mi[i] = ma[i] = 0;} else {mi[i] = -1; ma[i] = -1;} mind[i] = INT_MAX; return;}

    build(i<<1, d+1);    build(i<<1|1, d+1);

    if(mi[i<<1] != -1)
        mi[i] = mi[i<<1];
    else if(mi[i<<1|1] != -1) 
        mi[i] = mi[i<<1|1] + (1 << (k-d-1));
    else 
        mi[i] = -1;
    
    if(ma[i<<1|1] != -1)
        ma[i] = ma[i<<1|1];
    else if(mi[i<<1] != -1) 
        ma[i] = ma[i<<1] + (1 << (k-d-1));
    else 
        ma[i] = -1;

    mind[i] = min(mind[i<<1], mind[i<<1|1]);
    if(mi[i<<1|1] != -1 && ma[i<<1] != -1)
        mind[i] = min(mind[i], (mi[i<<1|1] + ma[i<<1] + 1));

    // cout << i << " " << mind[i] << " " << ma[i<<1] << " " << mi[i<<1|1] << endl;
}

void update(int diff, int md, int i = 1, int d = 0) {

    s[i] = s[i] ^ bool(diff&(1 << (md-d)));

    if(d < md) {
        update(diff, md, i<<1, d+1);
        update(diff, md, i<<1|1, d+1);
    }

    int L = i<<1|s[i]; int R = i<<1|(s[i]^1);

    if(mi[L] != -1)
        mi[i] = mi[L];
    else if(mi[R] != -1) 
        mi[i] = mi[R] + (1 << (k-d-1));
    else 
        mi[i] = -1;
    
    if(ma[R] != -1)
        ma[i] = ma[R];
    else if(mi[L] != -1) 
        ma[i] = ma[L] + (1 << (k-d-1));
    else 
        ma[i] = -1;

    mind[i] = min(mind[L], mind[R]);
    if(mi[R] != -1 && ma[L] != -1)
        mind[i] = min(mind[i], (mi[R] + ma[L] + 1));

    // if(diff == 3)
    // cout << i << " " << mind[i] << " " << mind[L] << " " << mind[R] << " " << ma[L] << " " << mi[R] << " " << s[i] << endl;
}



void solve() {
    cin >> n >> k;
    a = vector<bool>(1<<k);
    for(int i = 0; i < n; i++)  {int x; cin >> x; a[x] = true;}
    
    mind = mi = ma = vector<int>(1 << (k+1));
    s = vector<bool>(1 << (k+1));

    vector<int> ans(1<<k);
    build();
    ans[0] = mind[1];

    for(int i = 1; i < (1<<k); i++) {
        int cul = reverse(i);
        int diff = cul^reverse(i-1);
        while(diff && !(diff%2)) diff >>=1;
        int dep = 0; int temp = diff;
        while(temp > 1) {dep++; temp>>=1;}
        update(diff, dep);
        ans[cul] = mind[1];

        
        // cout << cul << " " << diff << " " << dep << " " << ans[cul] << " " << s[1] << " " << s[2] << endl;
    }

    for(int i = 0; i < (1<<k); i++) {
        if(i) cout << " ";
        cout << ans[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t =1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}