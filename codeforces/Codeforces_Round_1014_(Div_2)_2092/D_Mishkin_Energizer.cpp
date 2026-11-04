#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    // map<char, int> inv; inv[0] = 'L'; inv[1] = 'I'; inv[2] = 'T';
    vector<char> x = {'L', 'I', 'T'};
    vector<int> c(3);

    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') c[0]++;
        else if(s[i] == 'I')    c[1]++;
        else c[2]++;
    }


    int maxInd = 0; int minInd = 0;
    if(c[1] > c[0]) {maxInd = 1;}
    if(c[2] > c[maxInd])    {maxInd = 2;}
    char maxChar = x[maxInd];
    
    if(c[1] < c[0]) {minInd = 1;}
    if(c[2] < c[minInd])    {minInd = 2;}
    char minChar = x[minInd];

    if(c[maxInd] == c[minInd]) {
        cout << 0; return;
    }


    int start = -1;
    for(int i = 0; i < n-1; i++)
        if(s[i] != s[i+1] && ((s[i] == maxChar) || (s[i+1] == maxChar))) {
            start = i; break;
        }

    if(start == -1) {cout << -1; return;}

    int midInd = 3 - maxInd - minInd;

    cout << 2*(c[maxInd] + c[midInd] - 2*c[minInd]);
    
    if(s[start] == maxChar) {
        for(int i = 0; i < 2*(c[maxInd] - c[minInd]); i++) {
            cout  << "\n" << start+1;
        }

        
        int be;
        if(s[start+1] == minChar) be = start + 2;
        else be = start + 1;

        for(int i = 0; i < 2*(c[midInd] - c[minInd] ); i++) {
            cout  << "\n" << be+1;
        }
    } else {
        for(int i = 0; i < 2*(c[maxInd] - c[minInd]); i++) {
            cout << "\n" << start+1+i;
        }

        int be;
        if(s[start] == minChar) be = start + 1;
        else be = start;

        for(int i = 0; i < 2*(c[midInd] - c[minInd] ); i++) {
            cout  << "\n" << be+1;
        }
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