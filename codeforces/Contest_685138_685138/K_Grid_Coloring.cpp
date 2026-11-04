#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
#define a first
#define b second
void solve() {
    int n,m; cin >> n >> m;
    vector<pair<int,int>> v(3);
    for(auto& a: v) cin >> a.a >> a.b, a.a--, a.b--;
    vector<int> dis(3);
    for(int i = 0; i<3; i++)
        dis[i] = abs(v[i].a-v[(i+1)%3].a)+abs(v[i].b-v[(i+1)%3].b);
    if(dis[0] == 2 && dis[1] == 2 && dis[2] == 2){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<vector<char>> ret(n,vector<char>(m));
    for(int i = 0; i<n; i++) for(int j = 0; j<m; j++)
        ret[i][j] = (i+j)%2 ? 'R':'B';
    bool hasOdd = 0;
    if(dis[0]&1){
        hasOdd = 1;
    }else if(dis[1]&1){
        hasOdd = 1;
        rotate(v.begin(),v.begin()+1,v.end());
        rotate(dis.begin(),dis.begin()+1,dis.end());
    }
    if(hasOdd){
        ret[v[2].a][v[2].b] = 'G';
    }else{
        if(dis[1] != 2){
            rotate(v.begin(),v.begin()+1,v.end());
            rotate(dis.begin(),dis.begin()+1,dis.end());
        }else if(dis[2] != 2){
            rotate(v.begin(),v.begin()+2,v.end());
            rotate(dis.begin(),dis.begin()+2,dis.end());
        }
        int x = v[0].a, y = v[0].b;
        char to = ret[x][y] == 'R' ? 'B':'R';
        ret[x][y] = to;
        if(x) ret[x-1][y] = 'G';
        if(x != n-1) ret[x+1][y] = 'G';
        if(y) ret[x][y-1] = 'G';
        if(y != m-1) ret[x][y+1] = 'G';
        ret[v[1].a][v[1].b] = 'G';
    }
    for(int i = 0; i<n; i++) for(int j = 0; j<m; j++){
        if(i) assert(ret[i][j] != ret[i-1][j]);
        if(j) assert(ret[i][j] != ret[i][j-1]);
        assert(ret[i][j] == 'R' || ret[i][j] == 'G' || ret[i][j] == 'B');
    }
    for(int i = 0; i<3; i++) for(int j = i+1; j<3; j++)
        assert(ret[v[i].a][v[i].b] != ret[v[j].a][v[j].b]);
    for(auto& a: ret){
        for(char c: a) cout << c;
        cout << "\n";
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    //int t = 1;
    while(t--) {
        solve();
        // if(t)   cout << "\n";
    }
}