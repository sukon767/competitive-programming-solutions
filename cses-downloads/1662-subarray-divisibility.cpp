#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<long long> arr(n);
    cin >> arr[0];
    for(int i = 1; i < n; i++) {
        cin >> arr[i];
        arr[i] = arr[i];
        arr[i] += arr[i-1];
    }
    map<long long, int> sums;
    long long ans = 0;
    sums[0] = 1;
    for(int i = 0; i < n; i++) {
        ans += sums[(arr[i] % n + n) % n];
        sums[(arr[i] % n + n) % n]++;
    }
    cout << ans << endl;
}
