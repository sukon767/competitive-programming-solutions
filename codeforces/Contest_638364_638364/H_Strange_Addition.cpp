#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int solve() {
    int k;
    cin >> k;
    vector<pair<int, int>> d(k);
    for(int i = 0; i < k; i++) {
        int k; cin >> k;
        int x = k;    

        int add = 0;
        int p2 = 1;
        while(x) {
            if(x%10) add+=p2;
            p2*=2;
            x/=10;
        }

        d[i] = {add, k};
    }

    vector<int> ans;

    for(int i = 0; i < k; i++)  if(!d[i].second)    {ans.push_back(0);  break;}

    int sofar = 0;
    vector<int> no;

    for(int bit = 0; bit < 3; bit++) {
        for(int i = 0; i < k; i++)  if(d[i].first == (1 << bit))    {ans.push_back(d[i].second);    sofar |= d[i].first;  break;}
    }



    int left = 7 - sofar;

    // cout << left << " " << k << "\n";

    // for(int i= 0; i < k; i++)
    //     cout << d[i].first << "\n";

    for(int i = 0; i < k; i++)
        if((d[i].first & left) == d[i].first) {
            bool add = true;
            for(int bit = 0; bit < 3; bit++)
                if(d[i].first == (1 << bit))    {add == false; break;}
            if(!d[i].first) add = false;

            // if(d[i].first == 6)   cout << add << " " << i << "\n";

            if(add) {
                ans.push_back(d[i].second);
                break;}
        }
            

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++) {
        if(i)   cout << " ";
        cout << ans[i];  
    }


    return 0;
}

int main() {
    // int t; cin >> t;
    int t = 1;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}