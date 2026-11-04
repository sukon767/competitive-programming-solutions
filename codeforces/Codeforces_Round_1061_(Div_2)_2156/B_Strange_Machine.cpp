#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n, q;
    cin >> n;
    cin >> q;
    // cout << n << " " << q << endl;

    string s; cin >> s;
    vector<pair<char, int>> type;
    for(int i = 0; i < n; i++) {
        if(!i) {type.push_back({s[i], 1}); continue;}

        if(s[i]!=s[i-1] || s[i] == 'B') {
            type.push_back({s[i], 1});
        }
        else type.back().second++;
    }

    bool bruh = false;
    for(int i = 0; i < type.size(); i++) {
        if(type[i].first == 'B') {bruh = true; break;}
    }


    for(int i = 0; i < q; i++) {
        if(i) cout << "\n";
        int ans = 0;
        int a; cin >> a;


        if(!bruh) {cout << a; continue;}

        for(int j = 0; j < type.size(); j = ((j+1)%type.size())) {
            if(type[j].first =='A') {
                if(type[j].second >= a) {
                    ans += a;   
                    goto print_message;
                } else {
                    ans += type[j].second; a -= type[j].second;
                }
            }
            else {
                a /= 2; ans++;
                if(!a) goto print_message;
            }

        }

        print_message:
        cout << ans;
        
    }

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}