#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define retp(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void solve () {
    array<int, 3> nums;
    cin >> nums[0] >> nums[1] >> nums[2];

    bool swap1, swap2, swap3;
    swap1 = swap2 = swap3 = false;
    if (nums[0] > nums[1]) {
        swap(nums[0], nums[1]);
        swap1 = true;
    }
    if (nums[0] > nums[2]) {
        swap(nums[0], nums[2]);
        swap2 = true;
    }
    if (nums[1] > nums[2]) {
        swap(nums[1], nums[2]);
        swap3 = true;
    }

    if (nums[0] + nums[1] < nums[2]) {
        cout << "No\n";
        return;
    }
    
    string a ="a" , b="a", c="a";
    for(int i = 0; i < nums[1]; i++) {
        a += 'a';
    }
    for(int i = 0; i < nums[2]; i++) {
        b += 'a';
    }
    for(int i = 0; i < nums[0] - (nums[2] - nums[1]); i++) {
        a[1 + i] = 'b';
    }

    if (swap3) {
        swap(b, a);
    }
    if (swap2) {
        swap(a, c);
    }
    if (swap1) {
        swap(b, c);
    }
    cout << "Yes\n";
    cout << a << '\n';
    cout << b << '\n';
    cout << c << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    // int n; cin >> n;
    int n = 1;
    while(n--) solve();
}