#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    vector<pair<int, int>> rgb(3);
    for(auto &i : rgb) cin >> i.first;
    rgb[0].second = 1; //r
    rgb[1].second = 2; //g
    rgb[2].second = 4; //b
    sort(rgb.begin(), rgb.end()); reverse(rgb.begin(), rgb.end());

    // cout << rgb[0].first << endl;
    vector<int> move;
    string ans;
    
    map<int, string> t;
    t[1] = "R";
    t[2] = "G";
    t[4] = "B";
    t[3] = "RG";
    t[5] = "RB";
    t[6] = "GB";

    while(rgb[1].first + rgb[2].first > rgb[0].first) {move.push_back(rgb[1].second + rgb[2].second); rgb[1].first--; rgb[2].first--;}
    if(rgb[0].first > rgb[1].first + rgb[2].first) {ans += t[rgb[0].second]; rgb[0].first--;}

    while(rgb[0].first && rgb[1].first) {
        move.push_back(rgb[0].second + rgb[1].second);
        rgb[0].first--; rgb[1].first--;
    }

    while(rgb[0].first && rgb[2].first) {
        move.push_back(rgb[0].second + rgb[2].second);
        rgb[0].first--; rgb[2].first--;
    }

    


    for(int i = int(move.size())-1; i >= 0; i--) {
        string r = t[move[i]];
        if(!ans.size()) {ans += r; continue;}
        char c1 = r[0], c2 = r[1];
        
        if(ans.size() == 1) {
            if(c1 == ans.back()) {ans += c2; ans += c1;}
            else {ans += c1; ans += c2;}
        } else {
            char d = ans[ans.size()-2];
            if(c1 != ans.back() && c2 != d) {
                ans += c1; ans += c2;
            } else {
                ans += c2; ans += c1;
            }
        }
    }

    cout << ans;

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