#include "bits/stdc++.h"
using namespace std;
#define int int64_t

void setup(){
}

void solve(){
    int n,q;
    cin>>n>>q;
    int rows=n;
    int cols = n;
    vector<int> r(n);
    vector<int> c(n);
    for (int i=0;i<n;i++){
        r[i]=i%2;
    }
    for (int i=0;i<n;i++){
        c[i]=i%2;
    }
    for (int i=0;i<q;i++){
        string t;
        cin>>t;
        int v;
        cin>>v;
        v--;
        if (t=="ROW"){
            int cu=0;
            int nx=0;
            if (v>0){
                cu+=r[v]==r[v-1];
                nx+=r[v]!=r[v-1];
            }
            if (v+1<n){
                cu+=r[v]==r[v+1];
                nx+=r[v]!=r[v+1];
            }
            r[v]^=1;
            rows+=cu-nx;
        }
        else{
            int cu=0;
            int nx=0;
            if (v>0){
                cu+=c[v]==c[v-1];
                nx+=c[v]!=c[v-1];
            }
            if (v+1<n){
                cu+=c[v]==c[v+1];
                nx+=c[v]!=c[v+1];
            }
            c[v]^=1;
            cols+=cu-nx;
            
        }
        //cout<<rows<<" "<<cols<<"\n";
        cout<<rows*cols<<"\n";
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