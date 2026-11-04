#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    vector<string> ans(t);
 
 
    for(int j = 0; j < t; j++) {
 
        int n;
        cin >> n;
        vector<long long> nums(2*n);
 
        for(int i = 0; i < 2*n; i++)
            cin >> nums[i];
 
        sort(nums.begin(), nums.end());
        
        bool yn = true;
        long long pref = 0;
        long long prefK = 0;
 
        if(nums[0] == nums[1] && nums[0] % 2 == 0)
            for(int i = 1; i < n; i++) {
                long long nw = nums[2*i] - nums[2*i - 1];
                if(nw <= 0 || nw % (2*i) != 0 || nums[2*i] != nums[2*i + 1]) {
                    yn = false;
                    break;
                }
                pref += nw/(2*i);
                prefK += pref;
            }
        else
            yn = false;
        
        // cout << (nums[0] == nums[1]) << (nums[0] % 2 == 0);

        if(yn && nums[0]/2 - prefK > 0 && (nums[0]/2 - prefK) % n == 0)
            ans[j] = "YES";
        else
            ans[j] = "NO";


        // if(j == 4)
        //     cout << nums[0] << " " << prefK << " " << nums[0]/2 - prefK;
    }
    for(int i = 0; i < t-1; i++)
        cout << ans[i] << "\n";
    cout << ans[t-1];
}