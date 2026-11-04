#include "bits/stdc++.h"
using namespace std;
#define int int64_t

void setup(){
}

void solve(){
    int a,b;
    cin>>a>>b;
    if (a==0&&b==0){
        cout<<"Not a moose\n";
        return;
    }
    if (a!=b){
        cout<<"Odd ";
    }
    if (a==b){
        cout<<"Even ";
    }
    cout<<2*max(a,b)<<"\n";





    
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
