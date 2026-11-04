#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n;  cin >> n;
    if(n == 1)  {cout << 0; return;}
 
    vector<vector<double>> p(n, vector<double>(n));
    for(vector<double> &i : p)
        for(double &j : i)  {int k; cin >> k;  j= k/100.0;}
    
    vector<double> E(n);
    vector<double> prod(n, 1);
    set<int>    unvisited;
    for(int i = 0; i < n-1; i++)  {unvisited.insert(i);
        E[i] = 1;
        prod[i] = 1-p[i][n-1];
    }
 
    bool done = false;
    int prev = n-1;
 
    while(!done) {
        double minVal = INFINITY; int minNode = -1;
        for(int x : unvisited) {
            if(prod[x] == 1)    continue;
            double ev = E[x]/(1 - prod[x]);
            if(ev < minVal) {
                minNode = x; minVal = ev;
            }
        }
            
        if(minNode == -1)   {cout << "IAMGAY"; return;}
 
        E[minNode] = minVal;
        unvisited.erase(minNode);
        for(int x : unvisited)  {
            E[x] += prod[x]*p[x][minNode]*E[minNode];
            prod[x] *= 1-p[x][minNode];
        }
        if(!minNode)    done = true;
        prev = minNode;
    }
        
 
    cout << setprecision(30) << E[0];
    
    
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}