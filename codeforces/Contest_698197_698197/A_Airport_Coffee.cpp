#include "bits/stdc++.h"
using namespace std;
#define int int64_t

void setup(){
}

void solve(){
    int l,a,b,t,r;
    cin>>l>>a>>b>>t>>r;
    int n;
    cin>>n;
    if (n==0){
        cout<<0<<"\n";
        return;
    }
    vector<int> locs(n);
    for (int i=0;i<n;i++){
        cin>>locs[i];
    }
    if (locs.back()==l){
        n--;
    }
    else{
        locs.push_back(l);
    }
    vector<pair<double,int>> dp(n+1,{LLONG_MAX/2,int(0)});
    dp[0]={locs[0]/a,int(-1)};
    for (int i=0;i<n;i++){
        int cloc = locs[i];
        double ctime  = dp[i].first;
        double ntime = t+r;
        int nloc = cloc + a*t + r*b;
        int ncart = distance(locs.begin(),lower_bound(locs.begin(),locs.end(),nloc));
        if (true){
            //calculate distance to new cart
            int npos = min(ncart,n);
            if (npos>i){
                int dist = locs[npos]-cloc;
                double tt = 0;
                if (dist-a*t<=0){
                    tt = double(dist)/a;
                }
                else{
                    tt += t;
                    dist -= a*t;
                    if (dist-r*b<=0){
                        tt += double(dist)/b;
                    }
                    else{
                        tt += r;
                        dist -= b*r;
                        tt += double(dist)/a;
                    }

                }
                if (dp[npos].first>(ctime+tt)){
                    dp[npos]={ctime+tt,i};
                }

            }
        }
        if (ncart>i+1){
            int npos = ncart-1;
            //calculate distance to new cart
            if (npos>i){
                int dist = locs[npos]-cloc;
                double tt = 0;
                if (dist-a*t<=0){
                    tt = double(dist)/a;
                }
                else{
                    tt += t;
                    dist -= a*t;
                    if (dist-r*b<=0){
                        tt += double(dist)/b;
                    }
                    else{
                        tt += r;
                        dist -= b*r;
                        tt += double(dist)/a;
                    }

                }
                if (dp[npos].first>(ctime+tt)){
                    dp[npos]={ctime+tt,i};
                }


            }
        }

    }
    vector<int> bcarts;
    int cp = n;
    while (cp>=0){
        cp = dp[cp].second;
        if (cp>=0){
            bcarts.push_back(cp);
        }
    }
    cout<<bcarts.size()<<"\n";
    for (int i:bcarts){
        cout<<i<<" ";
    }
    cout<<"\n";
    //cout<<dp[n].first<<"\n";







    
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
