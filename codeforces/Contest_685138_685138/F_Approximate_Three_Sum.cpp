#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; while(t--){
        int n,m; cin >> n >> m;
        vector<pair<int,int>> a(n);
        for(int i = 0; i<n; i++){
            cin >> a[i].a;
            a[i].b = i+1;
        }
        sort(a.begin(),a.end());
        int p = 0;
        while(p < n && a[p].a <= m) p++;
        if(p < 2){
            cout << "-1\n";
            continue;
        }
        if(p < n && a[0].a+a[1].a+a[p].a <= 2*m){
            cout << a[0].b << " " << a[1].b << " " << a[p].b << "\n";
            continue;
        }
        if(a[0].a+a[1].a+a[2].a > 2*m){
            cout << "-1\n";
            continue;
        }
        bool w = 0;
        for(int i = 2; i<p; i++) if(a[0].a+a[1].a+a[i].a >= m){
            cout << a[0].b << " " << a[1].b << " " << a[i].b << "\n";
            w = 1;
            break;
        }
        if(w) continue;
        for(int i = 1; i<p-1; i++) if(a[0].a+a[i].a+a[p-1].a >= m){
            cout << a[0].b << " " << a[i].b << " " << a[p-1].b << "\n";
            w = 1;
            break;
        }
        if(w) continue;
        for(int i = 0; i<p-2; i++) if(a[i].a+a[p-2].a+a[p-1].a >= m){
            cout << a[i].b << " " << a[p-2].b << " " << a[p-1].b << "\n";
            w = 1;
            break;
        }
        if(!w) cout << "-1\n";
    }
}