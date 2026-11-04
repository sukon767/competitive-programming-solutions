#include <bits/stdc++.h>
using namespace std;
void boos() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
#define pb push_back
#define en '\n'
const int N = 110;
int h,w,cnt_k,cnt_i,cnt_t;
char c[N][N];
void solve() {
    cin >> h >> w >> cnt_k >> cnt_i >> cnt_t;
    c[0][0] = 'K';
    c[0][1] = 'I';
    c[0][2] = 'T';
    cnt_k--;
    cnt_i--;
    cnt_t--;
    int last_row = h - 1, last_col = w - 1;
    while(cnt_i > 0) {
        c[last_row][last_col] = 'I';
        last_col--;
        if(last_col < 0) {
            last_col = w - 1;
            last_row--;
        }
        cnt_i--;
    }
    while(cnt_t > 0) {
        c[last_row][last_col] = 'T';
        last_col--;
        if(last_col < 0) {
            last_col = w - 1;
            last_row--;
        }
        cnt_t--;
    }
    while(cnt_k > 0) {
        c[last_row][last_col] = 'K';
        last_col--;
        if(last_col < 0) {
            last_col = w - 1;
            last_row--;
        }
        cnt_k--;
    }
    for(int i = 0;i < h;i++) {
        for(int j = 0;j < w;j++) {
            cout << c[i][j];
        }
        cout << en;
    }
}

int main() {
    solve();
}
