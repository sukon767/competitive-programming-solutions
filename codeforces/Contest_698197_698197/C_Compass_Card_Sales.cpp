#include "bits/stdc++.h"
using namespace std;
#define int int64_t

void setup(){
}

void solve(){
    int n;
    cin>>n;
    vector<int> r(n);
    vector<int> g(n);
    vector<int> b(n);
    vector<int> id(n);
    vector<set<int>> rc(360);
    vector<set<int>> gc(360);
    vector<set<int>> bc(360);
    map<int,int> idi;
    for (int i=0;i<n;i++){
        cin>>r[i]>>g[i]>>b[i]>>id[i];
        rc[r[i]].insert(i);
        gc[g[i]].insert(i);
        bc[b[i]].insert(i);
        idi[id[i]]=i;
    }
    vector<int> unique(n);

    multiset<int> rs(r.begin(),r.end());
    multiset<int> gs(g.begin(),g.end());
    multiset<int> bs(b.begin(),b.end());
    auto gn = [&](int ind, char c){
        multiset<int>&cs=(c=='r')?(rs):((c=='g')?(gs):(bs));
        vector<set<int>>&cc=(c=='r')?(rc):((c=='g')?(gc):(bc));
        vector<int>&color=(c=='r')?(r):((c=='g')?(g):(b));

        vector<int> res;

        int v = color[ind];
        if (cc[v].size()>1){
            res.push_back(*cc[v].begin());
            if (res[0]==ind){
                res[0]=*cc[v].rbegin();
            }
            return res;
        }

        //above
        auto q = cs.find(v);
        q = next(q);
        if (q==cs.end()){
            q=cs.begin();
        }
        res.push_back(*cc[*q].begin());
        //below
        q = cs.find(v);
        if (q==cs.begin()){
            q=cs.end();
        }
        q=prev(q);
        res.push_back(*cc[*q].begin());
        return res;
    };

    auto calcu = [&](int ind){
        int res=0;
        vector<int> t = gn(ind,'r');
        int v = r[ind];
        if (t.size()!=1){
            //first is above
            int ov = r[t[0]];
            res += ((ov-v)<0)?(360+ov-v):(ov-v);

            //second is below
            ov = r[t[1]];
            res += ((v-ov)<0)?(360+v-ov):(v-ov);
        }

        t = gn(ind,'g');
        v = g[ind];
        if (t.size()!=1){
            //first is above
            int ov = g[t[0]];
            res += ((ov-v)<0)?(360+ov-v):(ov-v);

            //second is below
            ov = g[t[1]];
            res += ((v-ov)<0)?(360+v-ov):(v-ov);
        }

        t = gn(ind,'b');
        v = b[ind];
        if (t.size()!=1){
            //first is above
            int ov = b[t[0]];
            res += ((ov-v)<0)?(360+ov-v):(ov-v);

            //second is below
            ov = b[t[1]];
            res += ((v-ov)<0)?(360+v-ov):(v-ov);
        }

        return res;
    };
    set<pair<int,int>> us;
    for (int i=0;i<n;i++){
        unique[i]=calcu(i);
        us.insert({unique[i],-id[i]});
    }
    vector<int> ans;
    for (auto i:us){
        //cout<<i.first<<" "<<i.second<<"\n";
    }
    for (int i=0;i<n;i++){
        //<<"BRUH"<<endl;
        pair<int,int>  cur = *us.begin();
        ans.push_back(-cur.second);
        us.erase(us.begin());
        int ind = idi[-cur.second];
        //cout<<ind<<endl;

        vector<int> torecalc;
        for (int i:gn(ind,'r')){
            torecalc.push_back(i);
        }
        for (int i:gn(ind,'g')){
            torecalc.push_back(i);
        }
        for (int i:gn(ind,'b')){
            torecalc.push_back(i);
        }
        //cout<<"MEOW"<<endl;

        //remove

        int rv = r[ind];
        int gv = g[ind];
        int bv = b[ind];

        rc[rv].erase(rc[rv].find(ind));
        gc[gv].erase(gc[gv].find(ind));
        bc[bv].erase(bc[bv].find(ind));
        //cout<<"HELP"<<endl;

        rs.erase(rs.find(rv));
        gs.erase(gs.find(gv));
        bs.erase(bs.find(bv));
        //cout<<"BRUH"<<endl;

        //recalc

        for (int i:torecalc){
            if (i!=ind){
            //remove old
            us.erase({unique[i],-id[i]});
            unique[i] = calcu(i);
            us.insert({unique[i],-id[i]});
            }
        }
        //cout<<i<<endl;
    }
    for (int i:ans){
        cout<<i<<endl;
    }
    
}

signed main(){
    //cin.tie(0); ios::sync_with_stdio(0);
    int t=1;
    
    //cin>>t;
 
    setup();
    while (t--){
        solve();
    }
}
