#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n); for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;

    for(int i = 0; i < n-k; i++) {
        if(a[i] != a[i+k]) {
            if((b[i] != -1 && b[i] != a[i]) || (b[i+k] != -1 && b[i+k] != a[i+k])) {cout << "NO"; return;}
            b[i] = a[i]; b[i+k] = a[i+k];
        }
    }

    for(int i = 0; i < n-k; i++) {
        if(a[i] == a[i+k]) {
            if(b[i] != -1 || b[i+k] != -1) {
                if(b[i] != -1 && b[i+k] != -1 && b[i] != b[i+k]) {cout << "NO"; return;}
                if(b[i] != -1) b[i+k] = b[i];
                else b[i] = b[i+k]; 
            }
        }
    }

    for(int i = n-k-1; i >= 0; i--) {
        if(a[i] == a[i+k]) {
            if(b[i] != -1 || b[i+k] != -1) {
                if(b[i] != -1 && b[i+k] != -1 && b[i] != b[i+k]) {cout << "NO"; return;}
                if(b[i] != -1) b[i+k] = b[i];
                else b[i] = b[i+k]; 
            }
        }
    }

    vector<int> special(n+1);
    for(int i = 0; i < k; i++) {
        if(a[i] != b[i]) {
            special[a[i]]++;
            if(b[i] != -1) special[b[i]]--;
        } 
    }

    for(int x : special) if(x < 0) {cout << "NO"; return;}

    cout << "YES";
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