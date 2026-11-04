#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b,c; cin >> a >> b >> c;
    int p1 = 0, p2 = 0, p3 = 0;
    a+=" ";
    b+=" ";
    c+=" ";
    string r = "";
    while(a[p1] != ' ' || b[p2] != ' ' || c[p3] != ' '){
        if(a[p1] == b[p2] || a[p1] == c[p3]){
            assert(a[p1] != ' ');
            if(a[p1] == b[p2]) p2++;
            else p3++;
            r+=a[p1++];
        }else{
            assert(b[p2] == c[p3]);
            assert(b[p2] != ' ');
            r+=b[p2++];
            p3++;
        }
    }
    cout << r << "\n";
}