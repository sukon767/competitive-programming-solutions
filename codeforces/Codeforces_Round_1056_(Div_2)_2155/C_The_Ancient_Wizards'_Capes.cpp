#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<char>    pos(n);
    bool same = true;

    for(int &i : a) cin >> i;

    for(int i = 1; i < n; i++) {
        if(abs(a[i] - a[i-1]) >=2) {cout << 0; return;}
        else if(a[i] - a[i-1] == 1) {
            same = false;
            pos[i] = 'l';
            if(pos[i-1] == 'r') {cout << 0; return;}
            pos[i-1] = 'l';
        } else if(a[i-1] - a[i] == 1) {
            same = false;
            pos[i] = 'r';
            if(pos[i-1] == 'l') {cout << 0; return;}
            pos[i-1] = 'r';
        } else {
            if(pos[i-1] == 'l') pos[i] = 'r';
            else if(pos[i-1] == 'r') pos[i] = 'l';
        }
    }
    

    if(same)    {
        if(n%2)  {
            if(1+(n-1)/2 == a[0])
            cout << 2;
            else cout << 0;
        }
            
        else  {
            if(1+(n-1)/2 == a[0] || 2+(n-1)/2 == a[0]) cout << 1;
            else cout << 0;
        }
        return;}

    int firstd = 0;
    
    while(!pos[firstd])    {firstd++;}


    for(int i = firstd-1; i >= 0; i--) {
        if(pos[i+1] == 'l') pos[i] = 'r';
        else if(pos[i+1] == 'r') pos[i] = 'l';
    }

    // for(int i = 0; i < n; i++)  cout << pos[i] << " " << i << "\n";

    int check = 1;
    for(int i =1; i < n; i++) if(pos[i] == 'r') check++;

    if(check == a[0])   cout << 1;
    else cout << 0;
    
        

}

int main() {
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        if(i)   cout << "\n";
        solve();
    }
}