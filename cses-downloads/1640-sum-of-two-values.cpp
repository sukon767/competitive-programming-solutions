#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <queue>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> val(n);
    for(int i = 0; i < n; i++) {
        cin >> val[i].first;
        val[i].second = i;
    }
    sort(val.begin(), val.end());
    map<int, int> bij;
    for(int i = 0; i < n; i++)
        bij[i] = val[i].second;
    int cur = 0;
    int l = 0; int r = n-1;
    pair<int, int> ans = {-1, -1};
    while(r > l) {
        while(r > l+1 && val[l].first + val[r-1].first >= x) {
            cur += val[r-1].first - val[r].first; r--;
        }
        if(val[l].first + val[r].first == x) {
            ans = {bij[l], bij[r]};
            break;
        }
        if(r == l + 1) {
            break;
        } else {
            cur += val[l+1].first - val[l].first; l++;
        }
    }
    if(ans.first == -1)
        cout << "IMPOSSIBLE";
    else
        cout << ans.first+1 << " " << ans.second+1;
}
