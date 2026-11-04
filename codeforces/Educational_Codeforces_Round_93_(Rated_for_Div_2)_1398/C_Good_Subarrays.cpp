#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int t;
    cin >> t;
    vector<long long> ans(t);

    for(int j = 0; j < t; j++) {
        int n;
        string x;
        cin >> n;
        cin >> x;

        map<int, int> val;
        vector<int> prefix(n);
        for(int i = n-1; i >= 0; i--)
            prefix[i] = ((int) x[i]) - 48;

        for(int i = 1; i < n; i++)
            prefix[i] += prefix[i-1];

        val[0] = 1;

        for(int i = 0; i < n; i++) {
            ans[j] += val[prefix[i] - i - 1];
            val[prefix[i] - i - 1]++;
        }
    }

    for(int i = 0; i < t-1; i++)
        cout << ans[i] << "\n";

    cout << ans[t-1];
}