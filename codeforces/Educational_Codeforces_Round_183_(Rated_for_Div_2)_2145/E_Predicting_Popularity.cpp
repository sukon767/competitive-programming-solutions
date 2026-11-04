#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

vector<int> pre, mini;
int segLen = 2e6;

void build(int i=1, int l=0, int r=segLen-1) {
    if(l == r)  {pre[i] = mini[i] = -1; return;}
    int m = (l+r)>>1;
    build(i << 1, l, m);    build(i << 1 | 1, m+1, r);
    pre[i] = mini[i] = l-r-1; 
}

void add(int v, int del, int i=1, int l=0, int r=segLen-1) {
    if(l == r) {pre[i]+=del; mini[i]+=del; return;}
    int m = (l+r)>>1;
    if(v <= m)  add(v, del, i << 1, l, m);
    else    add(v, del, i<<1|1, m+1, r);

    pre[i] = pre[i<<1]+pre[i<<1|1];
    mini[i] = min(mini[i<<1], pre[i<<1]+mini[i<<1|1]);
}

int query(int pref=0, int i=1, int l=0, int r=segLen-1) {
    if(l==r)
        if(pref + pre[i] < 0)    return l;
        else return l+1;
    int m = (l+r)>>1;
    if(pref + mini[i << 1] < 0)    return query(pref, i<<1, l, m);
    return query(pref+pre[i<<1], i<<1|1, m+1, r);
}

int solve() {
// cout << "asdf\n";

    int ac, dr;
	cin >> ac >> dr;
    int n;
	cin >> n;
	vector<int> a(n), d(n);
	for (int& i : a) cin >> i;
	for (int& i : d) cin >> i; 
    pre = mini = vector<int>(4*segLen+1);
    
    build();

    // cout << mini[1] << " " << query()<< "\n";

    for(int i = 0; i < n; i++) {
        int p = max(a[i]-ac, 0) + max(d[i]-dr, 0);
        // cout << p << "\n";
        add(p, 1);
    }

    // cout << mini[1] << " " << query()<< "\n";

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        if(i)   cout << "\n";

        int target, newA, newD;    cin >> target >> newA >> newD;
        target--;
        add(max(a[target]-ac, 0) + max(d[target]-dr, 0), -1);
        a[target] = newA; d[target] = newD;
        add(max(a[target]-ac, 0) + max(d[target]-dr, 0), 1);

        cout << query();
    }

    return 0;
}

int main() {
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}